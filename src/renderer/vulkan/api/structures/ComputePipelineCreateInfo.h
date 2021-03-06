#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_COMPUTEPIPELINECREATEINFO_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_COMPUTEPIPELINECREATEINFO_H_

#include <vulkan/vulkan.h>

#include "PipelineShaderStageCreateInfo.h"
#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(ComputePipelineCreateInfoBuilder, VkComputePipelineCreateInfo,
                  VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO)
STRUCTURE_SETTER(Flags, const VkPipelineCreateFlags, flags)
STRUCTURE_SETTER(Stage, const VkPipelineShaderStageCreateInfo, stage)
STRUCTURE_SETTER(Stage, const PipelineShaderStageCreateInfoBuilder, stage)
STRUCTURE_SETTER(Layout, const VkPipelineLayout, layout)
STRUCTURE_SETTER(BasePipelineHandle, const VkPipeline, basePipelineHandle)
STRUCTURE_SETTER(BasePipelineIndex, const i32, basePipelineIndex)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_COMPUTEPIPELINECREATEINFO_H_
