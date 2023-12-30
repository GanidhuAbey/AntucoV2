#pragma once

#include <GLFW/glfw3.h>

#include "vulkan_core/instance.hpp"

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
