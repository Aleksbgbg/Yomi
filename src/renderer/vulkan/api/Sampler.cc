#include "Sampler.h"

#include <utility>

#include "error.h"

namespace vk {

Sampler::Sampler() : sampler(nullptr) {}

Sampler::Sampler(VkDevice device, SamplerCreateInfoBuilder& infoBuilder)
    : device(device) {
  PROCEED_ON_VALID_RESULT(
      vkCreateSampler(device, infoBuilder.Build(), nullptr, &sampler));
}

Sampler::Sampler(Sampler&& other) noexcept
    : device(other.device), sampler(other.sampler) {
  other.sampler = nullptr;
}

Sampler::~Sampler() {
  if (sampler != nullptr) {
    vkDestroySampler(device, sampler, nullptr);
  }
}

Sampler& Sampler::operator=(Sampler&& other) noexcept {
  this->~Sampler();
  new (this) Sampler(std::move(other));
  return *this;
}

}  // namespace vk
