#pragma once

#include <fmt/color.h>
#include <fmt/core.h>

#ifndef NDEBUG
#define WARN(...)                                                     \
  fmt::print(fg(fmt::color::yellow), "[WARNING ({})] - {}", __func__, \
             __VA_ARGS__)
#define ERR(...)                                            \
  fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold, \
             "[ERROR ({})] - {}", __func__, __VA_ARGS__)
#else
#define WARN(...)  // nothing
#define ERR(...)   // nothing
#endif
