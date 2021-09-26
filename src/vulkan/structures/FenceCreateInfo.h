#ifndef VULKAN_SRC_VULKAN_STRUCTURES_FENCECREATEINFO_H
#define VULKAN_SRC_VULKAN_STRUCTURES_FENCECREATEINFO_H

#include <vulkan/vulkan_core.h>

#include "types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(FenceCreateInfoBuilder, VkFenceCreateInfo, VK_STRUCTURE_TYPE_FENCE_CREATE_INFO)
  STRUCTURE_SETTER(FenceCreateInfoBuilder, Flags, const VkFenceCreateFlags, flags)
END_STRUCTURE_BUILDER

#endif // VULKAN_SRC_VULKAN_STRUCTURES_FENCECREATEINFO_H