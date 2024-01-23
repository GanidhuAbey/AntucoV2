#pragma once

#include <fmt/color.h>
#include <fmt/core.h>

#ifndef NDEBUG

#include <cassert>

#define WARN(...)                                                        \
  fmt::print(fg(fmt::color::yellow), "[WARNING ( {}() )] - ", __func__); \
  fmt::print(__VA_ARGS__);                                               \
  fmt::print("\n")
#define ERR(...)                                                    \
  fmt::print(stderr, fg(fmt::color::crimson) | fmt::emphasis::bold, \
             "[ERROR ( {}() )] - ", __func__);                      \
  fmt::print(stderr, fg(fmt::color::crimson) | fmt::emphasis::bold, __VA_ARGS__);                                          \
  fmt::print("\n");                                                 \
  assert(false)

#define ERR_LOG(...)                                                \
  fmt::print(stderr, fg(fmt::color::crimson) | fmt::emphasis::bold, \
             "[ERROR ( {}() )] - ", __func__);                      \
  fmt::print(stderr, fg(fmt::color::crimson) | fmt::emphasis::bold, __VA_ARGS__);                                          \
  fmt::print("\n")

#define INFO(...)                             \
  fmt::print("[INFO ( {}() )] - ", __func__); \
  fmt::print(__VA_ARGS__);                    \
  fmt::print("\n")
#else
#define WARN(...)  // nothing
#define ERR(...)   // nothing
#define INFO(...)  // nothing
#endif
