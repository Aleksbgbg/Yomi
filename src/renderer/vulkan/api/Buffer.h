#ifndef SRC_RENDERER_VULKAN_API_BUFFER_H_
#define SRC_RENDERER_VULKAN_API_BUFFER_H_

#include <vulkan/vulkan.h>

#include "renderer/vulkan/api/structures/BufferCreateInfo.h"

namespace vk {

class Buffer {
  friend class CommandBuffer;
  friend class DescriptorSet;
  friend class DeviceMemory;

 public:
  Buffer();
  Buffer(VkDevice device, const BufferCreateInfoBuilder& infoBuilder);

  Buffer(const Buffer&) = delete;
  Buffer(Buffer&& other) noexcept;

  ~Buffer();

  Buffer& operator=(const Buffer&) = delete;
  Buffer& operator=(Buffer&& other) noexcept;

  VkDeviceSize Size() const;

  VkMemoryRequirements GetMemoryRequirements() const;

 private:
  VkDevice device_;
  VkBuffer buffer_;
  VkDeviceSize size_;
};

}  // namespace vk

#endif  // SRC_RENDERER_VULKAN_API_BUFFER_H_
