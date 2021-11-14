#include "Surface.h"

Surface::Surface() : surface(nullptr) {}

Surface::Surface(VkInstance instance, VkSurfaceKHR surface)
    : instance(instance), surface(surface) {}

Surface::Surface(Surface&& other) noexcept
    : instance(other.instance), surface(other.surface) {
  other.surface = nullptr;
}

Surface::~Surface() {
  if (surface != nullptr) {
    vkDestroySurfaceKHR(instance, surface, nullptr);
  }
}

Surface& Surface::operator=(Surface&& other) noexcept {
  std::swap(instance, other.instance);
  std::swap(surface, other.surface);
  return *this;
}

bool Surface::IsSupportedByPhysicalDevice(const PhysicalDevice& physicalDevice,
                                          const u32 queueFamilyIndex) const {
  return physicalDevice.SupportsSurface(queueFamilyIndex, surface);
}

VkSurfaceCapabilitiesKHR Surface::GetCapabilities(
    const PhysicalDevice& physicalDevice) const {
  return physicalDevice.GetCapabilities(surface);
}

std::vector<VkSurfaceFormatKHR> Surface::GetFormats(
    const PhysicalDevice& physicalDevice) const {
  return physicalDevice.GetFormats(surface);
}

std::vector<VkPresentModeKHR> Surface::GetPresentModes(
    const PhysicalDevice& physicalDevice) const {
  return physicalDevice.GetPresentModes(surface);
}
