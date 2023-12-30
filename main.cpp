#include <iostream>

#include "antuco.hpp"
#include "logger.hpp"

int main() {
  Antuco *antuco = Antuco::get();

  // create window
  Engine::UI::Window *window = antuco->createWindow(800, 600, "hello world");

  while (!window->shouldClose()) {
    glfwPollEvents();
  }
}
