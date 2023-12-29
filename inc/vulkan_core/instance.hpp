#pragma once

#include <vulkan/vulkan.h>

#include <vector>

#define VULKAN_VALIDATION_LAYER_NAME "VK_LAYER_KHRONOS_validation"

namespace v {

class Instance {
 public:
  Instance();
  ~Instance();

 private:
  VkApplicationInfo createAppInfo();
  bool instanceLayersSupported(std::vector<const char *> &layerNames);
  bool extensionsSupported(std::vector<const char *> &extensions);

  void populateDebugMessageData(VkDebugUtilsMessengerCreateInfoEXT &info);

 private:
  // set validation layer
#ifdef NDEBUG
  bool m_enableValidation = false;
#else
  bool m_enableValidation = true;
#endif

  std::vector<const char *> m_instanceLayerNames;
  std::vector<const char *> m_extensionNames;

  VkInstance m_instance;
};

}  // namespace v
