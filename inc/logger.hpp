#pragma once

#include <fmt/color.h>
#include <fmt/core.h>

#ifndef NDEBUG
#define WARN(...)                                                            \
  fmt::print(fg(fmt::color::yellow), "[WARNING ( {}() )] - {} \n", __func__, \
             __VA_ARGS__)
#define ERR(...)                                                    \
  fmt::print(stderr, fg(fmt::color::crimson) | fmt::emphasis::bold, \
             "[ERROR ( {}() )] - {} \n", __func__, __VA_ARGS__);    \
  assert(false)

#define ERR_LOG(...)                                                \
  fmt::print(stderr, fg(fmt::color::crimson) | fmt::emphasis::bold, \
             "[ERROR ( {}() )] - {} \n", __func__, __VA_ARGS__)

#define INFO(...) fmt::print("[INFO ( {}() )] - {} \n", __func__, __VA_ARGS__)
#else
#define WARN(...)  // nothing
#define ERR(...)   // nothing
#define INFO(...)  // nothing
#endif
