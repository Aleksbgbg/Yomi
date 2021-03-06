#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORBUFFERINFO_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORBUFFERINFO_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER_NO_STYPE(DescriptorBufferInfoBuilder, VkDescriptorBufferInfo)
STRUCTURE_SETTER(Buffer, VkBuffer, buffer)
STRUCTURE_SETTER(Offset, VkDeviceSize, offset)
STRUCTURE_SETTER(Range, VkDeviceSize, range)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORBUFFERINFO_H_
