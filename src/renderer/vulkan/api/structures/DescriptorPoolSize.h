#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORPOOLSIZE_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORPOOLSIZE_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER_NO_STYPE(DescriptorPoolSizeBuilder, VkDescriptorPoolSize)
STRUCTURE_SETTER(Type, VkDescriptorType, type)
STRUCTURE_SETTER(DescriptorCount, u32, descriptorCount)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORPOOLSIZE_H_
