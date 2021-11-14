#ifndef VULKAN_SRC_VULKAN_STRUCTURES_SEMAPHORECREATEINFO_H
#define VULKAN_SRC_VULKAN_STRUCTURES_SEMAPHORECREATEINFO_H

#include <vulkan/vulkan.h>

#include "define_structure.h"
#include "util/types.h"

STRUCTURE_BUILDER(SemaphoreCreateInfoBuilder, VkSemaphoreCreateInfo,
                  VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO)
END_STRUCTURE_BUILDER

#endif  // VULKAN_SRC_VULKAN_STRUCTURES_SEMAPHORECREATEINFO_H
