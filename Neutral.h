#ifndef NEUTRAL_H
#define NEUTRAL_H

#include <algorithm>
#include <chrono>
#include <random>
#include <unistd.h>
#include<thread>

template <typename T>
static void shuffle(T** list, int count) {
	std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::shuffle(list, list + count, rng);
}

static inline void sleepfor(int amount){
	std::this_thread::sleep_for((std::chrono::milliseconds)amount);
}

#endif // !NEUTRAL_H
