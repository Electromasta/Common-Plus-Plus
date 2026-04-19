#pragma once
#include <random>

namespace Common  {
    namespace Random {
        int hash(int seed, int faces)   {
            std::mt19937 hashbrowns(seed);
            std::uniform_int_distribution<> dice(0, faces-1);
            return std::abs(dice(hashbrowns));
        }
    };
};
