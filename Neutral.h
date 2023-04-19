#ifndef NEUTRAL_H
#define NEUTRAL_H

#include <chrono>
#include <thread>
#include <unistd.h>
#include <random>
#include <algorithm>

class Neutral{
public:
    static bool isAlwaysAdjacent;

    static  bool isNeighbour(int a, int b);

    static inline void sleepfor(int amount){
        std::this_thread::sleep_for((std::chrono::milliseconds)amount);
    }

    template <typename T>
    static void shuffle(T** list, int count){
        std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::shuffle(list, list + count, rng);
    }
};

#endif // !NEUTRAL_H
