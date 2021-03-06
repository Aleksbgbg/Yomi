#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_PUSHCONSTANTRANGE_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_PUSHCONSTANTRANGE_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER_NO_STYPE(PushConstantRangeBuilder, VkPushConstantRange)
STRUCTURE_SETTER(StageFlags, VkShaderStageFlags, stageFlags)
STRUCTURE_SETTER(Offset, u32, offset)
STRUCTURE_SETTER(Size, u32, size)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_PUSHCONSTANTRANGE_H_
