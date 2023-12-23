#pragma once

#include <vulkan/vulkan.h>

#include <vector>

#define VULKAN_VALIDATION_LAYER_NAME "VK_LAYER_KHRONOS_validation"

namespace v {

class Instance {
 public:
  Instance();
  ~Instance() = default;

 private:
  VkApplicationInfo createAppInfo();
  bool instanceLayersSupported(std::vector<const char *> &layerNames);

 private:
  // set validation layer
#ifdef NDEBUG
  bool enableValidation = false;
#else
  bool enableValidation = true;
#endif

  std::vector<const char *> instanceLayerNames;
};

}  // namespace v
