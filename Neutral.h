#ifndef NEUTRAL_H
#define NEUTRAL_H

#include <algorithm>
#include <chrono>
#include <random>
#include "memtrace.h"

template <typename T>
static void shuffle(T** list, int count) {
	std::mt19937_64 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count());
	std::shuffle(list, list + count, rng);
}

#endif // !NEUTRAL_H
