#include "CommandPool.h"

#include "error.h"

namespace vk {

CommandPool::CommandPool() : commandPool(nullptr) {}

CommandPool::CommandPool(VkDevice device, VkQueue queue,
                         const CommandPoolCreateInfoBuilder& infoBuilder)
    : device(device), queue(queue) {
  PROCEED_ON_VALID_RESULT(
      vkCreateCommandPool(device, infoBuilder.Build(), nullptr, &commandPool));
}

CommandPool::CommandPool(CommandPool&& other) noexcept
    : device(other.device), queue(other.queue), commandPool(other.commandPool) {
  other.commandPool = nullptr;
}

CommandPool::~CommandPool() {
  if (commandPool != nullptr) {
    vkDestroyCommandPool(device, commandPool, nullptr);
  }
}

CommandPool& CommandPool::operator=(CommandPool&& other) noexcept {
  this->~CommandPool();
  new (this) CommandPool(std::move(other));
  return *this;
}

CommandBuffer CommandPool::AllocatePrimaryCommandBuffer() const {
  return AllocateCommandBuffer(VK_COMMAND_BUFFER_LEVEL_PRIMARY);
}

CommandBuffer CommandPool::AllocateSecondaryCommandBuffer() const {
  return AllocateCommandBuffer(VK_COMMAND_BUFFER_LEVEL_SECONDARY);
}

CommandBuffer CommandPool::AllocateCommandBuffer(
    const VkCommandBufferLevel level) const {
  return CommandBuffer(device, queue, commandPool,
                       CommandBufferAllocateInfoBuilder()
                           .SetCommandPool(commandPool)
                           .SetLevel(level));
}

}  // namespace vk
