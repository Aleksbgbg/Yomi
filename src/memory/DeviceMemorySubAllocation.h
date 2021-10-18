#ifndef VULKAN_SRC_MEMORY_DEVICEMEMORYSUBALLOCATION_H
#define VULKAN_SRC_MEMORY_DEVICEMEMORYSUBALLOCATION_H

#include "ReservedBlock.h"
#include "vulkan/DeviceMemory.h"

class DeviceMemorySubAllocation {
  friend class DeviceMemoryAllocator;

 public:
  DeviceMemorySubAllocation() = default;

  void* Map(const VkDeviceSize offset, const VkDeviceSize size) const;
  void Unmap() const;

  void MapCopy(const void* const data, const VkDeviceSize size) const;

  void FlushMappedMemoryRange(const VkDeviceSize offset,
                              const VkDeviceSize size) const;

 private:
  DeviceMemorySubAllocation(const DeviceMemory* const memory,
                            ReservedBlock reservedBlock);

  void Bind(const Buffer& buffer) const;
  void Bind(const Image& image) const;

 private:
  const DeviceMemory* memory;
  ReservedBlock reservedBlock;

  VkDeviceSize allocatedMemoryOffset;
};

#endif  // VULKAN_SRC_MEMORY_DEVICEMEMORYSUBALLOCATION_H