#pragma once

#include <memory>
#include <string>
#include <cstdint>

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

using String = std::string;

using uint8 = uint8_t;
