#ifndef SRC_RENDERER_VULKAN_RENDER_GRAPH_LAYOUT_DESCRIPTORSETSTRUCTURE_H_
#define SRC_RENDERER_VULKAN_RENDER_GRAPH_LAYOUT_DESCRIPTORSETSTRUCTURE_H_

#include <vector>

#include "Binding.h"

struct DescriptorSetStructure {
  std::vector<Binding> bindings;
};

#endif  // SRC_RENDERER_VULKAN_RENDER_GRAPH_LAYOUT_DESCRIPTORSETSTRUCTURE_H_
