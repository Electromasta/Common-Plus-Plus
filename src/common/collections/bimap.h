#pragma once
#include "common/core.types.h"

namespace Common  {
    template <typename A, typename B>
    class BidirectionalMap {
        public:
            void insert(const A & a, const B & b)   {
                if (abMap.count(a)) {   baMap.erase(abMap[a]);  }
                if (baMap.count(b)) {   abMap.erase(baMap[b]);  }
                abMap[a] = b;
                baMap[b] = a;
            }

            Optional<A> getA(const B & b) const {
                auto ba = baMap.find(b);
                if (ba != baMap.end()) return ba->second;
                return std::nullopt;
            }

            Optional<B> getB(const A & a) const {
                auto ab = abMap.find(a);
                if (ab != abMap.end()) return ab->second;
                return std::nullopt;
            }

            bool containsA(const A & a) const {
                return abMap.count(a) > 0;
            }

            bool containsB(const B & b) const {
                return baMap.count(b) > 0;
            }

            void eraseA(const A & a)    {
                if (!containsA(a)) return;
                B b = abMap.at(a);
                abMap.erase(a);
                baMap.erase(b);
            }

            void eraseB(const B & b)    {
                if (!containsB(b)) return;
                A a = baMap.at(b);
                baMap.erase(b);
                abMap.erase(a);
            }

            size_t size() const {
                return abMap.size();
            }

            bool empty() const {
                return abMap.empty();
            }

            void clear()    {
                abMap.clear();
                baMap.clear();
            }
        private:
            Hashmap<A, B> abMap;
            Hashmap<B, A> baMap;
    };
}
