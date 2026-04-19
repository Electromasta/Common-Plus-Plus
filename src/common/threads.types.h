#pragma once
#include <thread>
#include <mutex>
#include <atomic>

using Thread = std::thread;
using Mutex = std::mutex;

template<typename T>
using Atomic = std::atomic<T>;