#pragma once

#include <GLFW/glfw3.h>

#include "vulkan_core/surface.hpp"

namespace Engine {

namespace UI {

class Window {
 public:
  Window() { m_window = nullptr; };
  void create(int width, int height, const char *title);
  ~Window();

  Window(Window &) = delete;

  void createSurface(v::Instance &instance);

  bool shouldClose();

 private:
  GLFWwindow *m_window;

  v::Surface m_surface;

  int m_width;
  int m_height;
  const char *m_title;
};

}  // namespace UI

}  // namespace Engine
