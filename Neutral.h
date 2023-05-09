#ifndef NEUTRAL_H
#define NEUTRAL_H

#include <chrono>
#include <thread>
#include <unistd.h>
#include <random>
#include <algorithm>

class Neutral{
public:
    static bool isAlwaysAdjacent; ///< A boolean that tells if all symbols should be counted as adjacent or not

    ///Checks if two indexes in a list a adjacent to each other in a 5x5
    ///@param a - index no.1 (int)
    ///@param b - index no.2 (int)
    ///@return whether the two indexes are adjacent or not (bool)
    static bool isNeighbour(int a, int b);

    ///Pauses the screen for some time
    ///@param amount - time in milliseconds (int)
    static inline void sleepfor(int amount){
        std::this_thread::sleep_for((std::chrono::milliseconds)amount);
    }

    ///Template to a shuffle function that shuffles the pointers of any array
    ///@param list - array of pointers (<typename>**)
    ///@param count - length of the array (int)
    template <typename T>
    static void shuffle(T** list, int count){
        std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
        std::shuffle(list, list + count, rng);
    }
};

#endif // !NEUTRAL_H
