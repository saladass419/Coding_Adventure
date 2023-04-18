#ifndef NEUTRAL_H
#define NEUTRAL_H

#include <algorithm>
#include <chrono>
#include <random>
#include <unistd.h>
#include <thread>

class Neutral{
public:
    static bool isAlwaysAdjacent;

    template <typename T>
    static void shuffle(T** list, int count) {
        std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::shuffle(list, list + count, rng);
    }

    static inline void sleepfor(int amount){
        std::this_thread::sleep_for((std::chrono::milliseconds)amount);
    }

   static  bool isNeighbour(int a, int b){
        if (a == b) return false;
        if(isAlwaysAdjacent) return true;

        int xa = a / 5;
        int ya = a % 5;
        int xb = b / 5;
        int yb = b % 5;

        if (xa < 0 || xa>4 || ya < 0 || ya>4 || xb < 0 || xb>4 || yb < 0 || yb>4) return false;
        if (ya == yb) {
            if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
        }
        if (ya == yb+1) {
            if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
        }
        if (ya == yb-1) {
            if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
        }
        return false;
    }
};

#endif // !NEUTRAL_H
