#ifndef VULKAN_SRC_VULKAN_VULKANINSTANCE_H
#define VULKAN_SRC_VULKAN_VULKANINSTANCE_H

#include <vector>

#include "DebugUtilsMessenger.h"
#include "PhysicalDevice.h"
#include "Surface.h"
#include "structures/DebugUtilsMessengerCreateInfo.h"
#include "structures/InstanceCreateInfo.h"
#include "util/types.h"

class VulkanWindow;

class VulkanInstance {
  friend class ImGuiInstance;

 public:
  VulkanInstance();
  explicit VulkanInstance(const InstanceCreateInfoBuilder& infoBuilder);

  VulkanInstance(const VulkanInstance&) = delete;
  VulkanInstance(VulkanInstance&& other) noexcept;

  ~VulkanInstance();

  VulkanInstance& operator=(const VulkanInstance&) = delete;
  VulkanInstance& operator=(VulkanInstance&& other) noexcept;

  DebugUtilsMessenger CreateDebugUtilsMessenger(
      DebugUtilsMessengerCreateInfoExtBuilder& infoBuilder) const;
  Surface CreateSurface(const VulkanWindow& vulkanWindow) const;

  std::vector<PhysicalDevice> GetPhysicalDevices() const;

  static void LoadInstanceExtensionProperties(
      u32* count, VkExtensionProperties* properties);
  static void LoadInstanceLayerProperties(u32* count,
                                          VkLayerProperties* properties);

 private:
  VkInstance instance;
};

#endif  // VULKAN_SRC_VULKAN_VULKANINSTANCE_H
