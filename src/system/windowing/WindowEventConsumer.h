#ifndef VULKAN_SRC_SYSTEM_WINDOWING_WINDOWEVENTCONSUMER_H_
#define VULKAN_SRC_SYSTEM_WINDOWING_WINDOWEVENTCONSUMER_H_

#include "util/include/sdl.h"

class WindowEventConsumer {
 public:
  virtual ~WindowEventConsumer() = default;

  virtual void Consume(const SDL_Event& event) = 0;
};

#endif  // VULKAN_SRC_SYSTEM_WINDOWING_WINDOWEVENTCONSUMER_H_
