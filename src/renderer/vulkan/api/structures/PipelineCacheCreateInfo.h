#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_PIPELINECACHECREATEINFO_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_PIPELINECACHECREATEINFO_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(PipelineCacheCreateInfoBuilder, VkPipelineCacheCreateInfo,
                  VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO)
STRUCTURE_SETTER(Flags, VkPipelineCacheCreateFlags, flags)
STRUCTURE_SETTER(InitialDataSize, size_t, initialDataSize)
STRUCTURE_SETTER(PInitialData, const void*, pInitialData)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_PIPELINECACHECREATEINFO_H_
