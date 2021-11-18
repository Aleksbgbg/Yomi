#include "SceneDescriptor.h"

#include <array>

#include "vulkan/structures/DescriptorPoolSize.h"

void SceneDescriptor::ConfigureDescriptorPoolSizes(
    std::vector<VkDescriptorPoolSize>& poolSizes) {
  poolSizes.push_back(DescriptorPoolSizeBuilder()
                          .SetType(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC)
                          .SetDescriptorCount(1));
  poolSizes.push_back(DescriptorPoolSizeBuilder()
                          .SetType(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER)
                          .SetDescriptorCount(1));
}

DescriptorSetLayout SceneDescriptor::CreateSceneDescriptorLayout(
    const DescriptorSetLayoutFactory& descriptorSetLayoutFactory) {
  return descriptorSetLayoutFactory.CreateDescriptorSetLayout(
      DescriptorSetLayoutCreateInfoBuilder().SetBindingCount(1).SetPBindings(
          DescriptorSetLayoutBindingBuilder()
              .SetBinding(0)
              .SetDescriptorCount(1)
              .SetDescriptorType(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC)
              .SetStageFlags(VK_SHADER_STAGE_VERTEX_BIT |
                             VK_SHADER_STAGE_FRAGMENT_BIT)));
}

SceneDescriptor::SceneDescriptor(
    DescriptorSetLayout layout, const DescriptorPool& descriptorPool,
    DynamicUniformBufferInitializer& dynamicUniformBufferInitializer,
    const u32& bufferObjectIndex)
    : sceneDescriptorSetLayout(std::move(layout)),
      sceneDescriptorSet(
          descriptorPool.AllocateDescriptorSet(sceneDescriptorSetLayout)),
      viewTransformBuffer(dynamicUniformBufferInitializer, sceneDescriptorSet),
      bufferObjectIndex(&bufferObjectIndex) {}

void SceneDescriptor::WriteDescriptorSets(
    std::vector<DescriptorSet::WriteDescriptorSet>& descriptorSetWrites) const {
  descriptorSetWrites.push_back(
      std::move(viewTransformBuffer.CreateWriteDescriptorSet(0)));
}

PerFrameData& SceneDescriptor::FrameData() {
  return viewTransformBuffer.Value();
}

void SceneDescriptor::FlushFrameData() const {
  viewTransformBuffer.Flush(*bufferObjectIndex);
}

void SceneDescriptor::BindActorDescriptorSet(
    const CommandBuffer& commandBuffer,
    const PipelineLayout& pipelineLayout) const {
  commandBuffer.CmdBindDescriptorSet(
      VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout, 0, sceneDescriptorSet,
      viewTransformBuffer.CalculateDynamicOffset(*bufferObjectIndex));
}

glm::mat4 Project(const float aspect) {
  glm::mat4 projection =
      glm::perspective(glm::radians(55.0f), aspect, 0.1f, 3000.0f);
  projection[1][1] *= -1;

  return projection;
}

void SceneDescriptor::UpdateAspect(const float aspect) {
  FrameData().projection = Project(aspect);
}
