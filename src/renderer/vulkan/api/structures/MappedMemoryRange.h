#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_MAPPEDMEMORYRANGE_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_MAPPEDMEMORYRANGE_H_

#include <vulkan/vulkan.h>

#include "define_structure.h"

STRUCTURE_BUILDER(MappedMemoryRangeBuilder, VkMappedMemoryRange,
                  VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE)
STRUCTURE_SETTER(Memory, VkDeviceMemory, memory)
STRUCTURE_SETTER(Offset, VkDeviceSize, offset)
STRUCTURE_SETTER(Size, VkDeviceSize, size)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_MAPPEDMEMORYRANGE_H_
