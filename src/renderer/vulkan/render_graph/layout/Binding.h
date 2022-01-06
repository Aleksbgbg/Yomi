#ifndef VULKAN_SRC_RENDERER_VULKAN_RENDER_GRAPH_LAYOUT_BINDING_H_
#define VULKAN_SRC_RENDERER_VULKAN_RENDER_GRAPH_LAYOUT_BINDING_H_

#include <vulkan/vulkan.h>

#include <cstddef>

#include "renderer/vulkan/api/Sampler.h"
#include "util/types.h"

struct Binding {
  u32 index;
  std::size_t size;
  bool instanced;
  bool hostAccessible;
  VkBufferUsageFlags bufferUsage;
  VkDescriptorType type;
  VkShaderStageFlags stageFlags;
  const Sampler* sampler;
};

#endif  // VULKAN_SRC_RENDERER_VULKAN_RENDER_GRAPH_LAYOUT_BINDING_H_