#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_EXTENT3D_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_EXTENT3D_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER_NO_STYPE(Extent3DBuilder, VkExtent3D)
public:
explicit Extent3DBuilder(const VkExtent2D extent2d)
    : value_({.width = extent2d.width, .height = extent2d.height}) {}
STRUCTURE_SETTER(Width, const u32, width)
STRUCTURE_SETTER(Height, const u32, height)
STRUCTURE_SETTER(Depth, const u32, depth)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_EXTENT3D_H_
