#include "surface.hpp"

#include "logger.hpp"

namespace v {

Surface::Surface(Instance &instance, GLFWwindow *window) {
	VkResult err = glfwCreateWindowSurface(instance.get(), window, NULL, &m_surface);
	if (err) {
		ERR("Error Code: {} Failed to create vulkan surface for window.", static_cast<int>(err));
	}
}

}  // namespace v
