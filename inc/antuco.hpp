#pragma once

#include "render.hpp"
#include "window.hpp"

class Antuco {
 public:
  ~Antuco() = default;
  static Antuco *get();

  Engine::UI::Window *createWindow(int width, int height, const char *title);

 private:
  Antuco();
  Antuco(const Antuco &) = delete;
  static Antuco m_antuco;

 private:
  Engine::Render *m_render;
  Engine::UI::Window m_window;
};
