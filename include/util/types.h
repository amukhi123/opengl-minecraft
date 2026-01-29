#pragma once

#include <memory>
#include <string>
#include <cstdint>
#include <vector>

using SizeT = size_t;

template<typename T>
using UniquePtr = std::unique_ptr<T>;

template<typename T>
using SharedPtr = std::shared_ptr<T>;

template<typename T>
using List = std::vector<T>;

using String = std::string;

using uint8 = uint8_t;
using uint16 = uint16_t;
using uint32 = uint32_t;
