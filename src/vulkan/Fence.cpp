#include "Fence.h"
#include "error.h"

Fence::Fence(VkDevice device) : Fence(device, 0) {}

Fence::Fence(VkDevice device, const VkFenceCreateFlags createFlags) : device(device) {
  PROCEED_ON_VALID_RESULT(
      vkCreateFence(device, FenceCreateInfoBuilder().SetFlags(createFlags).Build(), nullptr, &fence))
}

Fence::~Fence() {
  if (fence != nullptr) {
    vkDestroyFence(device, fence, nullptr);
  }
}

VkFence Fence::Raw() {
  return fence;
}

Fence& Fence::Wait() {
  PROCEED_ON_VALID_RESULT(vkWaitForFences(device, 1, &fence, VK_TRUE, UINT64_MAX))
  return *this;
}

Fence& Fence::Reset() {
  PROCEED_ON_VALID_RESULT(vkResetFences(device, 1, &fence))
  return *this;
}