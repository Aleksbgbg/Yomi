#ifndef VULKAN_SRC_VULKAN_STRUCTURES_BUFFERCREATEINFO_H
#define VULKAN_SRC_VULKAN_STRUCTURES_BUFFERCREATEINFO_H

#include <vulkan/vulkan_core.h>

#include "types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(BufferCreateInfoBuilder, VkBufferCreateInfo, VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO)
  STRUCTURE_SETTER(BufferCreateInfoBuilder, Size, const VkDeviceSize, size)
  STRUCTURE_SETTER(BufferCreateInfoBuilder, Usage, const VkBufferUsageFlags, usage)
  STRUCTURE_SETTER(BufferCreateInfoBuilder, SharingMode, const VkSharingMode, sharingMode)
END_STRUCTURE_BUILDER

#endif // VULKAN_SRC_VULKAN_STRUCTURES_BUFFERCREATEINFO_H
