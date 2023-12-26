#include "instance.hpp"

#include "logger.hpp"

#define GLFW_USE_VULKAN
#include <GLFW/glfw3.h>

namespace v {

Instance::~Instance() { vkDestroyInstance(m_instance, nullptr); }

VkApplicationInfo Instance::createAppInfo() {
  VkApplicationInfo info{};
  info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  info.pNext = nullptr;
  info.pApplicationName = "Antuco";
  info.applicationVersion = 1;
  info.pEngineName = "Antuco";
  info.engineVersion = 1;
  info.apiVersion = VK_API_VERSION_1_3;

  return info;
}

bool Instance::extensionsSupported(std::vector<const char *> &extensions) {
  // get all supported extensions by hardware
  uint32_t supportedExtCount = 0;
  vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtCount, nullptr);

  if (supportedExtCount == 0) return false;

  std::vector<VkExtensionProperties> supportedExts(supportedExtCount);
  vkEnumerateInstanceExtensionProperties(nullptr, &supportedExtCount,
                                         supportedExts.data());

  // check whether our required layers exist within the list of supported layers
  for (const auto &requiredExt : extensions) {
    bool extSupported = false;
    for (const auto &supportedExt : supportedExts) {
      if (strcmp(requiredExt, supportedExt.extensionName) == 0) {
        extSupported = true;
        break;
      }
    }

    if (!extSupported) {
      return false;
    }
  }

  return true;
}

bool Instance::instanceLayersSupported(std::vector<const char *> &layerNames) {
  // get all supported layers by hardware
  uint32_t supportedLayerCount = 0;
  vkEnumerateInstanceLayerProperties(&supportedLayerCount, nullptr);

  std::vector<VkLayerProperties> supportedLayers(supportedLayerCount);
  vkEnumerateInstanceLayerProperties(&supportedLayerCount,
                                     supportedLayers.data());

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
  if (m_enableValidation) {
    m_instanceLayerNames.push_back(VULKAN_VALIDATION_LAYER_NAME);
  }

  // verify that required layers are present.
  if (!instanceLayersSupported(m_instanceLayerNames)) {
    ERR("Hardware cannot support required layers");
  }

  // add glfw extensions
  uint32_t extCount;
  const char **glfwExt = glfwGetRequiredInstanceExtensions(&extCount);
  m_extensionNames.resize(extCount);
  memcpy(m_extensionNames.data(), glfwExt, extCount);

  if (!extensionsSupported(m_extensionNames)) {
    ERR("Hardware cannot support required extensions");
  }

  VkInstanceCreateInfo info{};
  info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  info.pNext = nullptr;
  info.flags = {};
  info.pApplicationInfo = &app_info;
  info.enabledLayerCount = m_instanceLayerNames.size();
  info.ppEnabledLayerNames = m_instanceLayerNames.data();
  info.enabledExtensionCount = m_extensionNames.size();
  info.ppEnabledExtensionNames = m_extensionNames.data();

  if (vkCreateInstance(&info, nullptr, &m_instance) != VK_SUCCESS) {
    ERR("Failed to create instance");
  }
}

}  // namespace v
