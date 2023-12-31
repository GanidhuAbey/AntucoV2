#include "render.hpp"

namespace Engine {

Render Render::m_render;

Render::Render() : m_instance(), m_physicalDevice(m_instance) {}

void Render::createWindowSurface(UI::Window &window) {
  window.createSurface(m_instance);
}

};  // namespace Engine
