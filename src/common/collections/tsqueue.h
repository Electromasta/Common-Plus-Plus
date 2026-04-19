#pragma once
#include "common/core.types.h"
#include "common/threads.types.h"
#include <condition_variable>

namespace Common  {
    template <typename T>
    class ThreadSafeQueue {
        public:
            void push(const T & value) {
                std::lock_guard<Mutex> lock(mutex);
                queue.push(value);
                condition.notify_one();
            }

            Optional<T> pop() {
                std::unique_lock<Mutex> lock(mutex);
                if (queue.empty()) return std::nullopt;
                T value = queue.front();
                queue.pop();
                return value;
            }

            bool empty() const {
                std::lock_guard<Mutex> lock(mutex);
                return queue.empty();
            }

            int size() const {
                std::lock_guard<Mutex> lock(mutex);
                return queue.size();
            }

        private:
            Queue<T> queue;
            mutable Mutex mutex;
            std::condition_variable condition;
    };
}
