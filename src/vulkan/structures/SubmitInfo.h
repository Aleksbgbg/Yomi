#ifndef VULKAN_SRC_VULKAN_STRUCTURES_SUBMITINFO_H
#define VULKAN_SRC_VULKAN_STRUCTURES_SUBMITINFO_H

#include <vulkan/vulkan_core.h>

#include "types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(SubmitInfoBuilder, VkSubmitInfo, VK_STRUCTURE_TYPE_SUBMIT_INFO)
  STRUCTURE_SETTER(SubmitInfoBuilder, WaitSemaphoreCount, const u32, waitSemaphoreCount)
  STRUCTURE_SETTER(SubmitInfoBuilder, PWaitSemaphores, const VkSemaphore*, pWaitSemaphores)
  STRUCTURE_SETTER(SubmitInfoBuilder, PWaitDstStageMask, const VkPipelineStageFlags*, pWaitDstStageMask)
  STRUCTURE_SETTER(SubmitInfoBuilder, CommandBufferCount, const u32, commandBufferCount)
  STRUCTURE_SETTER(SubmitInfoBuilder, PCommandBuffers, const VkCommandBuffer*, pCommandBuffers)
  STRUCTURE_SETTER(SubmitInfoBuilder, SignalSemaphoreCount, const u32, signalSemaphoreCount)
  STRUCTURE_SETTER(SubmitInfoBuilder, PSignalSemaphores, const VkSemaphore*, pSignalSemaphores)
END_STRUCTURE_BUILDER

#endif // VULKAN_SRC_VULKAN_STRUCTURES_SUBMITINFO_H