#include "Scene.h"

#include <algorithm>

#include "game/renders/light/LightRender.h"
#include "game/renders/particles/ParticleRender.h"
#include "game/renders/sky/SkyboxRender.h"
#include "game/renders/spaceships/SpaceshipRender.h"

class NoDescriptorBinder : public ActorDescriptorBinder {
 public:
  void BindActorDescriptorSet(const PipelineLayout& pipelineLayout,
                              const CommandBuffer& commandBuffer,
                              const u32 actorIndex) const override {}
};

class ArrayDescriptorBinder : public ActorDescriptorBinder {
 public:
  ArrayDescriptorBinder(std::vector<DescriptorSet> descriptorSets)
      : descriptorSets(std::move(descriptorSets)) {}

  void BindActorDescriptorSet(const PipelineLayout& pipelineLayout,
                              const CommandBuffer& commandBuffer,
                              const u32 actorIndex) const override {
    commandBuffer.CmdBindDescriptorSet(VK_PIPELINE_BIND_POINT_GRAPHICS,
                                       pipelineLayout, 1,
                                       descriptorSets[actorIndex]);
  }

 private:
  std::vector<DescriptorSet> descriptorSets;
};

static constexpr const u32 RenderCount = 4;

Scene::Scene(const Initializer& initializer,
             DynamicUniformBufferInitializer& uniformBufferInitializer,
             const DescriptorSetLayoutFactory& descriptorSetLayoutFactory,
             const RenderPipeline::Initializer& renderPipelineInitializer,
             const ShaderModuleFactory& shaderModuleFactory,
             const ResourceBinder::ImageSamplerWriter& imageSamplerWriter,
             ResourceLoader& resourceLoader, const wnd::Window& window,
             const u32& imageIndex)
    : renderers(RenderCount), window(&window), camera() {
  std::unique_ptr<ParticleRender> particleRender =
      std::make_unique<ParticleRender>();

  std::vector<std::unique_ptr<SceneRender>> sceneRenders(RenderCount);
  sceneRenders[0] = std::make_unique<LightRender>();
  sceneRenders[1] = std::make_unique<SkyboxRender>();
  sceneRenders[2] = std::make_unique<SpaceshipRender>(
      camera, window, particleRender->GetParticleController());
  sceneRenders[3] = std::move(particleRender);

  std::vector<VkDescriptorPoolSize> descriptorPoolSizes;
  SceneDescriptor::ConfigureDescriptorPoolSizes(descriptorPoolSizes);
  u32 descriptorSetCount = 1;

  DescriptorSetLayout sceneDescriptorLayout =
      SceneDescriptor::CreateSceneDescriptorLayout(descriptorSetLayoutFactory);

  struct RenderInit {
    RenderPipeline renderPipeline;
    std::vector<std::unique_ptr<Actor>> actors;
    std::optional<DescriptorSetLayout> actorDescriptorSetLayout;
  };

  std::vector<RenderInit> renderInits(RenderCount);

  for (u32 renderIndex = 0; renderIndex < sceneRenders.size(); ++renderIndex) {
    RenderInit& renderInit = renderInits[renderIndex];
    const std::unique_ptr<SceneRender>& render = sceneRenders[renderIndex];

    const std::unique_ptr<PipelineStateFactory> pipelineStateFactory =
        render->ConfigurePipeline();
    const std::unique_ptr<DescriptorConfiguration> descriptorConfiguration =
        render->ConfigureDescriptors();
    renderInit.actors = render->LoadActors(resourceLoader);

    descriptorConfiguration->ConfigureDescriptorPoolSizes(descriptorPoolSizes);
    std::optional<DescriptorSetLayout> actorDescriptorSetLayout =
        descriptorConfiguration->ConfigureActorDescriptorSet(
            descriptorSetLayoutFactory);

    std::vector<const DescriptorSetLayout*> descriptorSetLayouts = {
        &sceneDescriptorLayout};

    if (actorDescriptorSetLayout.has_value()) {
      descriptorSetLayouts.push_back(&actorDescriptorSetLayout.value());
      descriptorSetCount += renderInit.actors.size();
    }

    renderInit.renderPipeline =
        RenderPipeline(renderPipelineInitializer, shaderModuleFactory,
                       descriptorSetLayouts, *pipelineStateFactory);
    renderInit.actorDescriptorSetLayout = std::move(actorDescriptorSetLayout);
  }

  descriptorPool = initializer.CreateDescriptorPool(
      DescriptorPoolCreateInfoBuilder()
          .SetPPoolSizes(descriptorPoolSizes.data())
          .SetPoolSizeCount(descriptorPoolSizes.size())
          .SetMaxSets(descriptorSetCount));

  std::vector<DescriptorSet::WriteDescriptorSet> descriptorSetWrites;

  sceneDescriptor =
      SceneDescriptor(std::move(sceneDescriptorLayout), descriptorPool,
                      uniformBufferInitializer, imageIndex);
  sceneDescriptor.WriteDescriptorSets(descriptorSetWrites);

  for (u32 renderIndex = 0; renderIndex < sceneRenders.size(); ++renderIndex) {
    RenderInit& renderInit = renderInits[renderIndex];

    std::unique_ptr<ActorDescriptorBinder> descriptorBinder;

    if (renderInit.actorDescriptorSetLayout.has_value()) {
      std::vector<DescriptorSet> descriptorSets(
          descriptorPool.AllocateDescriptorSets(
              renderInit.actorDescriptorSetLayout.value(),
              renderInit.actors.size()));

      for (u32 actorIndex = 0; actorIndex < renderInit.actors.size();
           ++actorIndex) {
        const std::unique_ptr<Actor>& actor = renderInit.actors[actorIndex];
        const DescriptorSet& descriptorSet = descriptorSets[actorIndex];

        ResourceBinder textureRegistry(imageSamplerWriter, descriptorSet,
                                       descriptorSetWrites);

        actor->GetMesh().BindTexture(textureRegistry);
        actor->BindBuffers(textureRegistry);
      }

      descriptorBinder =
          std::make_unique<ArrayDescriptorBinder>(std::move(descriptorSets));

    } else {
      descriptorBinder = std::make_unique<NoDescriptorBinder>();
    }

    renderers[renderIndex] = std::move(SceneRenderer(
        std::move(renderInit.renderPipeline), std::move(descriptorBinder),
        std::move(renderInit.actors)));
  }

  std::vector<VkWriteDescriptorSet> writeDescriptorSets(
      descriptorSetWrites.size());
  std::transform(
      descriptorSetWrites.begin(), descriptorSetWrites.end(),
      writeDescriptorSets.begin(),
      [](const DescriptorSet::WriteDescriptorSet& writeDescriptorSet) {
        return writeDescriptorSet.Build();
      });
  initializer.UpdateDescriptorSets(writeDescriptorSets.size(),
                                   writeDescriptorSets.data());
}

void Scene::UpdateAspect(const float aspect) {
  sceneDescriptor.UpdateAspect(aspect);
}

void Scene::UpdateModel(const UpdateContext& context) {
  for (SceneRenderer& renderer : renderers) {
    renderer.UpdateModel(context);
  }

  PerFrameData& frame = sceneDescriptor.FrameData();
  frame.view = camera.GetViewMatrix();
  frame.cameraPosition = camera.GetPosition();
  frame.lightingPosition = glm::vec3(0.0f, 0.0f, 100000.0f);
  frame.material = {.ambient = glm::vec3(1.0f),
                    .diffuse = glm::vec3(1.0f),
                    .specular = glm::vec3(1.0f),
                    .shininess = 32.0f};
  const glm::vec3 lightColor(77.0f / 255.0f, 77.0f / 255.0f, 1.0f);
  frame.light = {.position = glm::vec3(0.0f, 0.0f, 10000.0f),
                 .ambient = lightColor * 0.02f,
                 .diffuse = lightColor,
                 .specular = lightColor};
}

void Scene::Render(const CommandBuffer& commandBuffer) const {
  sceneDescriptor.FlushFrameData();

  for (const SceneRenderer& renderer : renderers) {
    renderer.Render(commandBuffer, sceneDescriptor, *window);
  }
}
