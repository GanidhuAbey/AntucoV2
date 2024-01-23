#pragma once

#include <GLFW/glfw3.h>

#include "vulkan_core/surface.hpp"

namespace Engine {

namespace UI {

enum KeyInput {
	W = GLFW_KEY_W,
	A = GLFW_KEY_A,
	S = GLFW_KEY_S,
	D = GLFW_KEY_D,
	Q = GLFW_KEY_Q,
};

class Window {
 public:
	Window() { m_window = nullptr; m_height = 0; m_width = 0; m_title = ""; };
	void create(int width, int height, const char *title);
	void initialize();
	~Window();

	Window(Window &) = delete;

	void createSurface(v::Instance &instance);

	void close();
	bool shouldClose();
	void pollEvents();

	bool isKeyPressed(KeyInput key);

	private:
	GLFWwindow *m_window;

	v::Surface m_surface;

	int m_width;
	int m_height;
	const char *m_title;
};

}  // namespace UI

}  // namespace Engine
