#include "antuco.hpp"

Antuco Antuco::m_antuco;

Antuco *Antuco::get() { return &m_antuco; }

Antuco::Antuco() { 
    m_window.initialize();
    m_render = Engine::Render::get(); 
}

Engine::UI::Window *Antuco::createWindow(int width, int height,
                                         const char *title) {
  m_window.create(width, height, title);
  m_render->createWindowSurface(m_window);
  return &m_window;
}
