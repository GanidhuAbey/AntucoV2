#include "window.hpp"

#include "logger.hpp"

namespace Engine {

namespace UI {

Window::~Window() { glfwTerminate(); }

static void glfwError(int id, const char *description) { ERR_LOG(description); }

void Window::initialize() {
    glfwSetErrorCallback(&glfwError);

    if (!glfwInit())
    {
        ERR("GLFW failed to initialize");
    }
}

void Window::create(int width, int height, const char *title) {
  m_width = width;
  m_height = height;
  m_title = title;

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

void Window::close() { glfwSetWindowShouldClose(m_window, GLFW_TRUE); }
bool Window::shouldClose() { return glfwWindowShouldClose(m_window); }
void Window::pollEvents() { glfwPollEvents(); }
bool Window::isKeyPressed(KeyInput key) {
  return glfwGetKey(m_window, key) == GLFW_PRESS;
}

}  // namespace UI

}  // namespace Engine
