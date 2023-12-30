#pragma once

#include "vulkan_core/instance.hpp"
#include "window.hpp"

namespace Engine {

class Render {
 public:
  ~Render() = default;
  static Render *get() { return &m_render; };

  void createWindowSurface(UI::Window &window);

 private:
  Render();
  Render(const Render &) = delete;

  static Render m_render;

 private:
  v::Instance m_instance;
};

}  // namespace Engine
