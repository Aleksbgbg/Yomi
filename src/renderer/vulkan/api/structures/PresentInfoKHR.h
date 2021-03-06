#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_PRESENTINFOKHR_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_PRESENTINFOKHR_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(PresentInfoKhrBuilder, VkPresentInfoKHR,
                  VK_STRUCTURE_TYPE_PRESENT_INFO_KHR)
STRUCTURE_SETTER(WaitSemaphoreCount, u32, waitSemaphoreCount)
STRUCTURE_SETTER(PWaitSemaphores, const VkSemaphore*, pWaitSemaphores)
STRUCTURE_SETTER(SwapchainCount, u32, swapchainCount)
STRUCTURE_SETTER(PSwapchains, const VkSwapchainKHR*, pSwapchains)
STRUCTURE_SETTER(PImageIndices, const u32*, pImageIndices)
STRUCTURE_SETTER(PResults, VkResult*, pResults)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_PRESENTINFOKHR_H_
