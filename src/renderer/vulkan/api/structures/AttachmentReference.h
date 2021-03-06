#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_ATTACHMENTREFERENCE_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_ATTACHMENTREFERENCE_H_

#include <vulkan/vulkan.h>

#include "core/types.h"
#include "define_structure.h"

STRUCTURE_BUILDER_NO_STYPE(AttachmentReferenceBuilder, VkAttachmentReference)
STRUCTURE_SETTER(Attachment, u32, attachment)
STRUCTURE_SETTER(Layout, VkImageLayout, layout)
END_STRUCTURE_BUILDER

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_ATTACHMENTREFERENCE_H_
