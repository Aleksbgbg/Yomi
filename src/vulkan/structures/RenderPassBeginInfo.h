#ifndef VULKAN_SRC_VULKAN_STRUCTURES_RENDERPASSBEGININFO_H
#define VULKAN_SRC_VULKAN_STRUCTURES_RENDERPASSBEGININFO_H

#include <vulkan/vulkan_core.h>

#include "Rect2D.h"
#include "define_structure.h"
#include "types.h"

STRUCTURE_BUILDER(RenderPassBeginInfoBuilder, VkRenderPassBeginInfo,
                  VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO)
STRUCTURE_SETTER(RenderPass, VkRenderPass, renderPass)
STRUCTURE_SETTER(Framebuffer, VkFramebuffer, framebuffer)
STRUCTURE_SETTER(RenderArea, VkRect2D, renderArea)
STRUCTURE_SETTER(ClearValueCount, u32, clearValueCount)
STRUCTURE_SETTER(PClearValues, const VkClearValue*, pClearValues)
END_STRUCTURE_BUILDER

#endif  // VULKAN_SRC_VULKAN_STRUCTURES_RENDERPASSBEGININFO_H
