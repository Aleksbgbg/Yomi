#include "PipelineCache.h"

#include "error.h"

namespace vk {

PipelineCache::PipelineCache() : pipelineCache(nullptr) {}

PipelineCache::PipelineCache(VkDevice device,
                             const PipelineCacheCreateInfoBuilder& infoBuilder)
    : device(device) {
  PROCEED_ON_VALID_RESULT(vkCreatePipelineCache(device, infoBuilder.Build(),
                                                nullptr, &pipelineCache));
}

PipelineCache::PipelineCache(PipelineCache&& other) noexcept
    : device(other.device), pipelineCache(other.pipelineCache) {
  other.pipelineCache = nullptr;
}

PipelineCache::~PipelineCache() {
  if (pipelineCache != nullptr) {
    vkDestroyPipelineCache(device, pipelineCache, nullptr);
  }
}

PipelineCache& PipelineCache::operator=(PipelineCache&& other) noexcept {
  this->~PipelineCache();
  new (this) PipelineCache(std::move(other));
  return *this;
}

std::vector<u8> PipelineCache::GetPipelineCacheData() const {
  size_t dataSize;
  PROCEED_ON_VALID_RESULT(
      vkGetPipelineCacheData(device, pipelineCache, &dataSize, nullptr));
  std::vector<u8> data(dataSize);
  PROCEED_ON_VALID_RESULT(
      vkGetPipelineCacheData(device, pipelineCache, &dataSize, data.data()));
  return data;
}

}  // namespace vk
