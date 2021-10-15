#ifndef VULKAN_SRC_MEMORY_DEVICEMEMORYALLOCATOR_H
#define VULKAN_SRC_MEMORY_DEVICEMEMORYALLOCATOR_H

#include <memory>
#include <vector>

#include "DeviceHeap.h"
#include "DeviceMemorySubAllocation.h"
#include "vulkan/Buffer.h"
#include "vulkan/DeviceMemory.h"
#include "vulkan/Image.h"
#include "vulkan/VirtualDevice.h"

class DeviceMemoryAllocator {
 public:
  DeviceMemoryAllocator() = default;
  DeviceMemoryAllocator(
      VirtualDevice* virtualDevice,
      const VkPhysicalDeviceMemoryProperties* const memoryProperties);

  DeviceMemorySubAllocation BindMemory(
      const Buffer& buffer, const VkMemoryPropertyFlags requiredProperties);
  DeviceMemorySubAllocation BindMemory(
      const Image& image, const VkMemoryPropertyFlags requiredProperties);

 private:
  DeviceMemorySubAllocation ReserveMemoryBlock(
      const VkMemoryRequirements& memoryRequirements,
      const VkMemoryPropertyFlags requiredProperties);

 private:
  class HeapAllocator : public Allocator {
   public:
    HeapAllocator() = default;
    HeapAllocator(VirtualDevice* virtualDevice, u32 memoryTypeIndex);

    std::unique_ptr<MemoryObject> Allocate(VkDeviceSize size) override;

   private:
    VirtualDevice* virtualDevice;
    u32 memoryTypeIndex;
  };

  struct Heap {
    HeapAllocator allocator;
    DeviceHeap deviceHeap;
  };

  VirtualDevice* virtualDevice;
  const VkPhysicalDeviceMemoryProperties* memoryProperties;

  std::vector<Heap> heapsPerMemoryIndex;
};

#endif  // VULKAN_SRC_MEMORY_DEVICEMEMORYALLOCATOR_H
