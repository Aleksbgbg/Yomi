#ifndef SRC_RENDERER_VULKAN_API_FENCE_H_
#define SRC_RENDERER_VULKAN_API_FENCE_H_

#include <vulkan/vulkan.h>

#include "renderer/vulkan/api/structures/FenceCreateInfo.h"

namespace vk {

class Fence {
 public:
  Fence();
  explicit Fence(const VkDevice device);
  Fence(const VkDevice device, const VkFenceCreateFlags createFlags);

  Fence(const Fence&) = delete;
  Fence(Fence&& other) noexcept;

  ~Fence();

  Fence& operator=(const Fence&) = delete;
  Fence& operator=(Fence&& other) noexcept;

  VkFence Raw() const;

  const Fence& Wait() const;
  const Fence& Reset() const;

 private:
  VkDevice device;
  VkFence fence;
};

}  // namespace vk

#endif  // SRC_RENDERER_VULKAN_API_FENCE_H_
