#ifndef VULKAN_SRC_RENDERER_VULKAN_API_SEMAPHORE_H_
#define VULKAN_SRC_RENDERER_VULKAN_API_SEMAPHORE_H_

#include <vulkan/vulkan.h>

#include "renderer/vulkan/api/structures/SemaphoreCreateInfo.h"

class Semaphore {
 public:
  Semaphore();
  Semaphore(VkDevice device, const SemaphoreCreateInfoBuilder& infoBuilder);

  Semaphore(const Semaphore&) = delete;
  Semaphore(Semaphore&& other) noexcept;

  ~Semaphore();

  Semaphore& operator=(const Semaphore&) = delete;
  Semaphore& operator=(Semaphore&& other) noexcept;

  const VkSemaphore* Pointer() const;
  VkSemaphore Raw() const;

 private:
  VkDevice device;
  VkSemaphore semaphore;
};

#endif  // VULKAN_SRC_RENDERER_VULKAN_API_SEMAPHORE_H_