#ifndef SRC_RENDERER_VULKAN_API_DESCRIPTORSET_H_
#define SRC_RENDERER_VULKAN_API_DESCRIPTORSET_H_

#include <vulkan/vulkan.h>

#include <memory>

#include "Buffer.h"
#include "ImageView.h"
#include "Sampler.h"
#include "renderer/vulkan/api/structures/WriteDescriptorSet.h"

namespace vk {

class DescriptorSet {
  friend class CommandBuffer;

 public:
  class WriteDescriptorSet {
    friend DescriptorSet;
    enum class Type { Buffer, Image };

   public:
    WriteDescriptorSet(const DescriptorBufferInfoBuilder& descriptorBuilder,
                       WriteDescriptorSetBuilder writeBuilder);
    WriteDescriptorSet(const DescriptorImageInfoBuilder& descriptorBuilder,
                       WriteDescriptorSetBuilder writeBuilder);

    ~WriteDescriptorSet() = default;

    WriteDescriptorSet(const WriteDescriptorSet& other) noexcept;
    WriteDescriptorSet(WriteDescriptorSet&& other) noexcept;

    WriteDescriptorSet& operator=(const WriteDescriptorSet& other) noexcept;
    WriteDescriptorSet& operator=(WriteDescriptorSet&& other) noexcept;

    VkWriteDescriptorSet Build() const;

   private:
    void ReassignPointers();

   private:
    Type type;
    union {
      VkDescriptorBufferInfo bufferInfo;
      VkDescriptorImageInfo imageInfo;
    } info;
    WriteDescriptorSetBuilder writeBuilder;
  };

  DescriptorSet() = default;
  explicit DescriptorSet(VkDescriptorSet descriptorSet);

  DescriptorSet(const DescriptorSet&) = delete;
  DescriptorSet(DescriptorSet&&) = default;

  DescriptorSet& operator=(const DescriptorSet&) = delete;
  DescriptorSet& operator=(DescriptorSet&&) = default;

  DescriptorSet::WriteDescriptorSet CreateBufferWrite(
      const Buffer& buffer, const VkDescriptorType descriptorType,
      const u32 binding) const;
  DescriptorSet::WriteDescriptorSet CreateImageSamplerWrite(
      const ImageView& samplerImageView, const Sampler& sampler,
      const VkImageLayout imageLayout, const u32 binding) const;

 private:
  VkDescriptorSet descriptorSet;
};

}  // namespace vk

#endif  // SRC_RENDERER_VULKAN_API_DESCRIPTORSET_H_
