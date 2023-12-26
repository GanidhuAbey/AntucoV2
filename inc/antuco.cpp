#include "antuco.hpp"

Antuco Antuco::m_antuco;

Antuco *Antuco::get() { return &m_antuco; }

Antuco::Antuco() { m_render = Engine::Render::get(); }
