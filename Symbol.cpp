#include "memtrace.h"
#include "Symbol.h"

int Symbol::createId() const {
	if (icon == "  " ) return -1;
	static int temp = 0;
	return temp++;
}

std::string Symbol::getAbility() {
	return "Absolutely nothing";
}