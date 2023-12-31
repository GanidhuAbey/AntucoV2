#pragma once

#include <vulkan/vulkan.h>

#include "instance.hpp"

namespace v {

class PhysicalDevice {
 public:
  PhysicalDevice() = default;
  ~PhysicalDevice() = default;
  PhysicalDevice(Instance &instance);

  PhysicalDevice(PhysicalDevice &) = delete;

 private:
  uint32_t scorePhysicalDevice(VkPhysicalDevice &physicalDevice);

  VkPhysicalDevice m_physicalDevice;
};

}  // namespace v
