#ifndef VULKAN_SRC_VULKAN_STRUCTURES_PIPELINESHADERSTAGECREATEINFO_H
#define VULKAN_SRC_VULKAN_STRUCTURES_PIPELINESHADERSTAGECREATEINFO_H

#include <vulkan/vulkan_core.h>

#include "define_structure.h"
#include "types.h"

STRUCTURE_BUILDER(PipelineShaderStageCreateInfoBuilder,
                  VkPipelineShaderStageCreateInfo,
                  VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO)
STRUCTURE_SETTER(Flags, const VkPipelineShaderStageCreateFlags, flags)
STRUCTURE_SETTER(Stage, const VkShaderStageFlagBits, stage)
STRUCTURE_SETTER(Module, VkShaderModule, module)
STRUCTURE_SETTER(PName, const char*, pName)
STRUCTURE_SETTER(PSpecializationInfo, const VkSpecializationInfo*,
                 pSpecializationInfo)
END_STRUCTURE_BUILDER

#endif  // VULKAN_SRC_VULKAN_STRUCTURES_PIPELINESHADERSTAGECREATEINFO_H
