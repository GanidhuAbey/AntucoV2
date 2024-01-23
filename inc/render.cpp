#include "render.hpp"

namespace Engine {

Render* Render::m_render = nullptr;

Render::Render() : m_instance(), m_physicalDevice(m_instance) {}

Render::~Render() {
	vkDestroyInstance(m_instance.get(), nullptr);
}

void Render::createWindowSurface(UI::Window &window) {
  window.createSurface(m_instance);
}

};  // namespace Engine
