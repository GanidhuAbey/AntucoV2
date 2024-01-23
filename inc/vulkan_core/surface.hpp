#pragma once

#include "vulkan_core/instance.hpp"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace v {

class Surface {
 public:
  Surface() = default;
  Surface(Instance &instance, GLFWwindow *window);

  Surface(Surface &) = delete;

  VkSurfaceKHR get() { return m_surface; }

 private:
  VkSurfaceKHR m_surface = nullptr;
};

}  // namespace v
