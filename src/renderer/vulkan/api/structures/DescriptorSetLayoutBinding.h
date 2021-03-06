#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORSETLAYOUTBINDING_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORSETLAYOUTBINDING_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER_NO_STYPE(DescriptorSetLayoutBindingBuilder,
                           VkDescriptorSetLayoutBinding)
STRUCTURE_SETTER(Binding, const u32, binding)
STRUCTURE_SETTER(DescriptorType, const VkDescriptorType, descriptorType)
STRUCTURE_SETTER(DescriptorCount, const u32, descriptorCount)
STRUCTURE_SETTER(StageFlags, const VkShaderStageFlags, stageFlags)
STRUCTURE_SETTER(PImmutableSamplers, const VkSampler*, pImmutableSamplers)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_DESCRIPTORSETLAYOUTBINDING_H_
