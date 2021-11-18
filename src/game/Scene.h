#ifndef VULKAN_SRC_GAME_SCENE_H
#define VULKAN_SRC_GAME_SCENE_H

#include <vector>

#include "Camera.h"
#include "DynamicUniformBuffer.h"
#include "game/SceneDescriptor.h"
#include "game/model/UpdateContext.h"
#include "game/renders/SceneRenderer.h"
#include "general/windowing/Window.h"
#include "vulkan/CommandBuffer.h"

class Scene {
 public:
  class Initializer {
   public:
    virtual ~Initializer() = default;

    virtual DescriptorPool CreateDescriptorPool(
        const DescriptorPoolCreateInfoBuilder& infoBuilder) const = 0;
    virtual void UpdateDescriptorSets(
        const u32 descriptorSetCount,
        const VkWriteDescriptorSet* const descriptorSetWrites) const = 0;
  };

  Scene() = default;
  Scene(const Initializer& initializer,
        DynamicUniformBufferInitializer& uniformBufferInitializer,
        const DescriptorSetLayoutFactory& descriptorSetLayoutFactory,
        const RenderPipeline::Initializer& renderPipelineInitializer,
        const ShaderModuleFactory& shaderModuleFactory,
        const ResourceBinder::ImageSamplerWriter& imageSamplerWriter,
        ResourceLoader& resourceLoader, const wnd::Window& window,
        const u32& imageIndex);

  Scene(const Scene&) = delete;
  Scene(Scene&&) = delete;

  Scene& operator=(const Scene&) = delete;
  Scene& operator=(Scene&&) = delete;

  void UpdateAspect(const float aspect);

  void UpdateModel(const UpdateContext& context);
  void Render(const CommandBuffer& commandBuffer) const;

 private:
  std::vector<SceneRenderer> renderers;

  const wnd::Window* window;
  Camera camera;

  DescriptorPool descriptorPool;
  SceneDescriptor sceneDescriptor;
};

#endif  // VULKAN_SRC_GAME_SCENE_H
