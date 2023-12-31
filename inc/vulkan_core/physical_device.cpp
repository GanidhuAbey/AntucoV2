#include "physical_device.hpp"

#include "logger.hpp"

namespace v {

PhysicalDevice::PhysicalDevice(Instance &instance) {
  uint32_t deviceCount = 0;
  vkEnumeratePhysicalDevices(instance.get(), &deviceCount, nullptr);
  if (deviceCount == 0) {
    ERR("failed to find any suitable devices");
  }

  std::vector<VkPhysicalDevice> devices(deviceCount);
  vkEnumeratePhysicalDevices(instance.get(), &deviceCount, devices.data());

  uint32_t bestDeviceIndex = 0;
  uint32_t bestDeviceScore = 0;

  for (int i = 0; i < devices.size(); i++) {
    uint32_t deviceScore = scorePhysicalDevice(devices[i]);
    if (deviceScore > bestDeviceScore) {
      bestDeviceIndex = i;
      bestDeviceScore = deviceScore;
    }
  }

  m_physicalDevice = devices[bestDeviceIndex];

#ifdef VALIDATION_ENABLED
  VkPhysicalDeviceProperties deviceProperties{};
  vkGetPhysicalDeviceProperties(m_physicalDevice, &deviceProperties);

  INFO("Selected GPU: {}", deviceProperties.deviceName);
#endif
}

// The scoring of a physical device can be done on many different properties to
// select the truly best For now though, we will just select the the discrete
// GPU (if the system has it)
uint32_t PhysicalDevice::scorePhysicalDevice(VkPhysicalDevice &physicalDevice) {
  VkPhysicalDeviceProperties deviceProperties{};
  vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);

  if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU) {
    return 500;
  }

  return 1;
}

}  // namespace v
