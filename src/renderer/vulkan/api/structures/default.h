#ifndef SRC_RENDERER_VULKAN_API_STRUCTURES_DEFAULT_H_
#define SRC_RENDERER_VULKAN_API_STRUCTURES_DEFAULT_H_

#include <vulkan/vulkan.h>

#include "BufferCreateInfo.h"
#include "BufferMemoryBarrier.h"
#include "Extent3D.h"
#include "ImageCreateInfo.h"
#include "ImageMemoryBarrier.h"
#include "ImageSubresourceRange.h"
#include "ImageViewCreateInfo.h"
#include "Viewport.h"

inline constexpr const VkBufferCreateInfo BUFFER_EXCLUSIVE =
    BufferCreateInfoBuilder().SetSharingMode(VK_SHARING_MODE_EXCLUSIVE);

inline constexpr const VkImageCreateInfo IMAGE_2D =
    ImageCreateInfoBuilder()
        .SetImageType(VK_IMAGE_TYPE_2D)
        .SetMipLevels(1)
        .SetArrayLayers(1)
        .SetSamples(VK_SAMPLE_COUNT_1_BIT)
        .SetTiling(VK_IMAGE_TILING_OPTIMAL)
        .SetSharingMode(VK_SHARING_MODE_EXCLUSIVE)
        .SetInitialLayout(VK_IMAGE_LAYOUT_UNDEFINED);

inline constexpr const VkViewport VIEWPORT_BASE =
    ViewportBuilder().SetMaxDepth(1.0f);

inline constexpr const VkOffset2D OFFSET2D_ZERO = {};

inline constexpr const VkExtent3D EXTENT3D_SINGLE_DEPTH = {.depth = 1};

inline constexpr const VkImageSubresourceLayers
    SUBRESOURCE_LAYERS_COLOR_SINGLE_LAYER =
        ImageSubresourceLayersBuilder()
            .SetAspectMask(VK_IMAGE_ASPECT_COLOR_BIT)
            .SetLayerCount(1);

inline constexpr const VkImageSubresourceRange
    SUBRESOURCE_RANGE_COLOR_SINGLE_LAYER =
        ImageSubresourceRangeBuilder()
            .SetAspectMask(VK_IMAGE_ASPECT_COLOR_BIT)
            .SetLayerCount(1)
            .SetLevelCount(1);

inline constexpr const VkImageMemoryBarrier
    IMAGE_MEMORY_BARRIER_NO_OWNERSHIP_TRANSFER =
        ImageMemoryBarrierBuilder()
            .SetSrcQueueFamilyIndex(VK_QUEUE_FAMILY_IGNORED)
            .SetDstQueueFamilyIndex(VK_QUEUE_FAMILY_IGNORED);

inline constexpr VkCommandBufferInheritanceInfo
    COMMAND_BUFFER_INHERITANCE_EMPTY = CommandBufferInheritanceInfoBuilder();

inline constexpr VkCommandBufferBeginInfo COMMAND_BUFFER_ONE_TIME_SUBMIT =
    CommandBufferBeginInfoBuilder().SetFlags(
        VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);

inline constexpr VkCommandBufferBeginInfo
    COMMAND_BUFFER_ONE_TIME_SUBMIT_RENDER_PASS_CONTINUE =
        CommandBufferBeginInfoBuilder().SetFlags(
            VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT |
            VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT);

inline constexpr VkCommandBufferBeginInfo
    COMMAND_BUFFER_ONE_TIME_SUBMIT_SECONDARY =
        CommandBufferBeginInfoBuilder()
            .SetFlags(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT)
            .SetPInheritanceInfo(&COMMAND_BUFFER_INHERITANCE_EMPTY);

#endif  // SRC_RENDERER_VULKAN_API_STRUCTURES_DEFAULT_H_
