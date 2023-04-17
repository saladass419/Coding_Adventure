#include "Symbol.h"
#include "memtrace.h"

int Symbol::createId() {
	if (icon == ' ') return -1;
	static int temp = 0;
	return temp++;
}

std::string Symbol::getAbility() {
	return "Absolutely nothing";
}