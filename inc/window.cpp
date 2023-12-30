#include "window.hpp"

#include "logger.hpp"

namespace Engine {

namespace UI {

Window::~Window() { glfwTerminate(); }

static void glfwError(int id, const char *description) { ERR(description); }

void Window::create(int width, int height, const char *title) {
  m_width = width;
  m_height = height;
  m_title = title;

  glfwSetErrorCallback(&glfwError);

  if (!glfwInit()) {
    ERR("GLFW failed to initialize");
  }

  // disable opengl
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

  m_window = glfwCreateWindow(width, height, title, NULL, NULL);

  if (!m_window) {
    ERR("Window did not successfully create");
  }
}

void Window::createSurface(v::Instance &instance) {
  m_surface = v::Surface(instance, m_window);
}

bool Window::shouldClose() { return glfwWindowShouldClose(m_window); }

}  // namespace UI

}  // namespace Engine
