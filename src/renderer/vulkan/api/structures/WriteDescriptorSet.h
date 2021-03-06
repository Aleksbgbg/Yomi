#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_WRITEDESCRIPTORSET_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_WRITEDESCRIPTORSET_H_

#include <vulkan/vulkan.h>

#include "DescriptorBufferInfo.h"
#include "DescriptorImageInfo.h"
#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(WriteDescriptorSetBuilder, VkWriteDescriptorSet,
                  VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET)
STRUCTURE_SETTER(DstSet, VkDescriptorSet, dstSet)
STRUCTURE_SETTER(DstBinding, u32, dstBinding)
STRUCTURE_SETTER(DstArrayElement, u32, dstArrayElement)
STRUCTURE_SETTER(DescriptorCount, u32, descriptorCount)
STRUCTURE_SETTER(DescriptorType, VkDescriptorType, descriptorType)
STRUCTURE_SETTER(PImageInfo, const VkDescriptorImageInfo*, pImageInfo)
STRUCTURE_SETTER_POINTER_FROM_BUILDER(PImageInfo, DescriptorImageInfoBuilder,
                                      pImageInfo)
STRUCTURE_SETTER(PBufferInfo, const VkDescriptorBufferInfo*, pBufferInfo)
STRUCTURE_SETTER_POINTER_FROM_BUILDER(PBufferInfo, DescriptorBufferInfoBuilder,
                                      pBufferInfo)
STRUCTURE_SETTER(PTexelBufferView, const VkBufferView*, pTexelBufferView)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_WRITEDESCRIPTORSET_H_
