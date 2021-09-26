#ifndef VULKAN_SRC_VULKAN_ERROR_H
#define VULKAN_SRC_VULKAN_ERROR_H

#include <vulkan/vulkan.h>
#include <string>

#include "build_definition.h"

class VulkanResultException : public std::exception {
private:
  std::string message;

public:
  VulkanResultException(
      const char* const file, const int line, const char* const invocation, const VkResult result)
      : message(
      std::string() + "[" + file + ":" + std::to_string(line) + "] " + invocation
      + ": VkResult was not success. Was: " + std::to_string(result)
      + " but expected VK_SUCCESS (0).") {}

  const char* what() const override {
    return message.c_str();
  }
};

#ifdef RELEASE
#define PROCEED_ON_VALID_RESULT(invocation) invocation;
#else
#define PROCEED_ON_VALID_RESULT(invocation)                                 \
  {                                                                         \
    const VkResult result = invocation;                                     \
    if (result != VK_SUCCESS) {                                             \
      throw VulkanResultException(__FILE__, __LINE__, #invocation, result); \
    }                                                                       \
  }
#endif

#endif // VULKAN_SRC_VULKAN_ERROR_H