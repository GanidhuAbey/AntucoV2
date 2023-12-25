#include "instance.hpp"

#include "logger.hpp"

namespace v {

VkApplicationInfo Instance::createAppInfo() {
  VkApplicationInfo info{};
  info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  info.pNext = nullptr;
  info.pApplicationName = "Antuco";
  info.applicationVersion = 1;
  info.pEngineName = "Antuco";
  info.engineVersion = 1;
  info.apiVersion = VK_VERSION_1_3;

  return info;
}

bool Instance::instanceLayersSupported(std::vector<const char *> &layerNames) {
  // get all supported layers by hardware
  uint32_t supportedLayerCount = 0;
  vkEnumerateInstanceLayerProperties(&supportedLayerCount, nullptr);

  std::vector<VkLayerProperties> supportedLayers(supportedLayerCount);
  vkEnumerateInstanceLayerProperties(nullptr, supportedLayers.data());

  // check whether our required layers exist within the list of supported layers
  for (const auto &layerName : layerNames) {
    bool layerSupported = false;
    for (const auto &supportedLayer : supportedLayers) {
      if (strcmp(layerName, supportedLayer.layerName) == 0) {
        layerSupported = true;
        break;
      }
    }

    if (!layerSupported) {
      return false;
    }
  }

  return true;
}

Instance::Instance() {
  VkApplicationInfo app_info = createAppInfo();

  // add validation layers
  if (enableValidation) {
    instanceLayerNames.push_back(VULKAN_VALIDATION_LAYER_NAME);
  }

  // verify that required layers are present.
  if (!instanceLayersSupported(instanceLayerNames)) {
    ERR("Hardware cannot support required layers");
  }
}

}  // namespace v
