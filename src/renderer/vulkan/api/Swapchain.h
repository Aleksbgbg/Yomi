#ifndef SRC_RENDERER_VULKAN_API_SWAPCHAIN_H_
#define SRC_RENDERER_VULKAN_API_SWAPCHAIN_H_

#include <vulkan/vulkan.h>

#include <vector>

#include "Fence.h"
#include "Framebuffer.h"
#include "Image.h"
#include "RenderPass.h"
#include "Semaphore.h"
#include "SynchronisationPack.h"
#include "renderer/vulkan/api/structures/SwapchainCreateInfo.h"

namespace vk {

class Swapchain {
  friend class Queue;

 public:
  Swapchain();
  Swapchain(VkDevice device, const Swapchain& oldSwapchain,
            SwapchainCreateInfoBuilder& infoBuilder);
  Swapchain(VkDevice device, const SwapchainCreateInfoBuilder& infoBuilder);

  Swapchain(const Swapchain&) = delete;
  Swapchain(Swapchain&& other) noexcept;

  ~Swapchain();

  Swapchain& operator=(const Swapchain&) = delete;
  Swapchain& operator=(Swapchain&& other) noexcept;

  VkFormat GetImageFormat() const;
  VkExtent2D GetImageExtent() const;

  struct AcquireNextImageResult {
    u32 imageIndex;
    VkResult status;
  };
  AcquireNextImageResult AcquireNextImage(
      const SynchronisationPack& synchronisation) const;

  u32 GetImageCount() const;

  std::vector<Framebuffer> GetFramebuffers(const RenderPass& renderPass) const;
  std::vector<Framebuffer> GetFramebuffers(
      const RenderPass& renderPass,
      const std::vector<const ImageView*>& attachments) const;

 private:
  VkDevice device;
  VkSwapchainKHR swapchain;
  std::vector<VkImage> images;
  std::vector<ImageView> imageViews;
  VkFormat imageFormat;
  VkExtent2D imageExtent;
};

}  // namespace vk

#endif  // SRC_RENDERER_VULKAN_API_SWAPCHAIN_H_
