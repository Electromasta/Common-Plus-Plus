#pragma once
#include <cstdint>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <utility>
#include <tuple>
#include <optional>
#include <memory>
#include <expected>

using i8 = std::int8_t;
using i16 = std::int16_t;
using i32 = std::int32_t;
using i64 = std::int64_t;
using u8 = std::uint8_t;
using u16 = std::uint16_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;

using String = std::string;
using Bytes = std::vector<u8>;

template<typename T, size_t N>
using Array = std::array<T, N>;

template<typename T>
using ArrayList = std::vector<T>;

template<typename T>
using Queue = std::queue<T>;

template<typename T>
using SortSet = std::set<T>;

template<typename T>
using Set = std::unordered_set<T>;

template<typename T, typename U>
using Hashmap = std::unordered_map<T, U>;

template<typename T, typename U>
using TreeMap = std::map<T, U>;

template<typename T, typename U>
using Pair = std::pair<T, U>;

template<typename T, typename U, typename V>
using Tuple = std::tuple<T, U, V>;

template<typename T>
using Optional = std::optional<T>;

template<typename T>
using Unique = std::unique_ptr<T>;

template<typename T>
using Pointer = std::shared_ptr<T>;

template<typename T>
using Shared = std::shared_ptr<T>;

template<typename T, typename E>
using Result = std::expected<T, E>;
