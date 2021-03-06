#ifndef SRC_RENDERER_VULKAN_API_IMAGE_H_
#define SRC_RENDERER_VULKAN_API_IMAGE_H_

#include <vulkan/vulkan.h>

#include "ImageView.h"
#include "renderer/vulkan/api/structures/ImageCreateInfo.h"

namespace vk {

class Image {
  friend class CommandBuffer;
  friend class DeviceMemory;

 public:
  Image();
  Image(VkDevice device, const ImageCreateInfoBuilder& infoBuilder);

  Image(const Image&) = delete;
  Image(Image&& other) noexcept;

  ~Image();

  Image& operator=(const Image&) = delete;
  Image& operator=(Image&& other) noexcept;

  VkMemoryRequirements GetMemoryRequirements() const;

  ImageView CreateView(ImageViewCreateInfoBuilder infoBuilder) const;

 private:
  VkDevice device;
  VkImage image;
  VkImageCreateInfo createInfo;
};

}  // namespace vk

#endif  // SRC_RENDERER_VULKAN_API_IMAGE_H_
