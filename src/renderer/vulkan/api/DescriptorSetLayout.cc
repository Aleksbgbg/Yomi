#include "DescriptorSetLayout.h"

#include <utility>

#include "error.h"

namespace vk {

DescriptorSetLayout::DescriptorSetLayout() : descriptorSetLayout(nullptr) {}

DescriptorSetLayout::DescriptorSetLayout(
    VkDevice device, const DescriptorSetLayoutCreateInfoBuilder& infoBuilder)
    : device(device) {
  PROCEED_ON_VALID_RESULT(vkCreateDescriptorSetLayout(
      device, infoBuilder.Build(), nullptr, &descriptorSetLayout));
}

DescriptorSetLayout::DescriptorSetLayout(DescriptorSetLayout&& other) noexcept
    : device(other.device), descriptorSetLayout(other.descriptorSetLayout) {
  other.descriptorSetLayout = nullptr;
}

DescriptorSetLayout::~DescriptorSetLayout() {
  if (descriptorSetLayout != nullptr) {
    vkDestroyDescriptorSetLayout(device, descriptorSetLayout, nullptr);
  }
}

DescriptorSetLayout& DescriptorSetLayout::operator=(
    DescriptorSetLayout&& other) noexcept {
  this->~DescriptorSetLayout();
  new (this) DescriptorSetLayout(std::move(other));
  return *this;
}

}  // namespace vk
