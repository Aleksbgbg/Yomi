#ifndef VULKAN_SRC_VULKAN_STRUCTURES_FRAMEBUFFERCREATEINFO_H
#define VULKAN_SRC_VULKAN_STRUCTURES_FRAMEBUFFERCREATEINFO_H

#include <vulkan/vulkan_core.h>

#include "types.h"
#include "define_structure.h"

STRUCTURE_BUILDER(FramebufferCreateInfoBuilder, VkFramebufferCreateInfo, VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO)
  STRUCTURE_SETTER(FramebufferCreateInfoBuilder, Flags, VkFramebufferCreateFlags, flags)
  STRUCTURE_SETTER(FramebufferCreateInfoBuilder, RenderPass, VkRenderPass, renderPass)
  STRUCTURE_SETTER(FramebufferCreateInfoBuilder, AttachmentCount, u32, attachmentCount)
  STRUCTURE_SETTER(FramebufferCreateInfoBuilder, PAttachments, const VkImageView*, pAttachments)
  STRUCTURE_SETTER(FramebufferCreateInfoBuilder, Width, u32, width)
  STRUCTURE_SETTER(FramebufferCreateInfoBuilder, Height, u32, height)
  STRUCTURE_SETTER(FramebufferCreateInfoBuilder, Layers, u32, layers)
END_STRUCTURE_BUILDER

#endif // VULKAN_SRC_VULKAN_STRUCTURES_FRAMEBUFFERCREATEINFO_H