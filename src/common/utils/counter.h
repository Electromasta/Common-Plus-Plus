#pragma once
#include "common/core.types.h"

namespace Common  {
    class Counter {
        public:
            Counter() : count(0)  {}

            u32 next()    {
                return count++;
            }
        private:
            u32 count;
    };
};