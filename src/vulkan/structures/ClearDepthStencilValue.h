#ifndef VULKAN_SRC_VULKAN_STRUCTURES_CLEARDEPTHSTENCILVALUE_H
#define VULKAN_SRC_VULKAN_STRUCTURES_CLEARDEPTHSTENCILVALUE_H

#include <vulkan/vulkan_core.h>

#include "define_structure.h"
#include "types.h"

STRUCTURE_BUILDER_NO_STYPE(ClearDepthStencilValueBuilder,
                           VkClearDepthStencilValue)
STRUCTURE_SETTER(Depth, float, depth)
STRUCTURE_SETTER(Stencil, u32, stencil)
END_STRUCTURE_BUILDER

#endif  // VULKAN_SRC_VULKAN_STRUCTURES_CLEARDEPTHSTENCILVALUE_H
