#pragma once

#include "render.hpp"

class Antuco {
 public:
  ~Antuco() = default;
  static Antuco *get();

 private:
  Antuco();
  Antuco(const Antuco &) = delete;
  static Antuco m_antuco;

 private:
  Engine::Render *m_render;
};
