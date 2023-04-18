#include "Item.h"

std::string Item_a::getAbility() {
	return "Gains 1$ for each empty slot";
}
std::string Item_b::getAbility() {
	return "Gains 1$ for every 'a' symbol";
}
std::string Item_c::getAbility() {
	return "Gains 3$ every 3 spins";
}
std::string Item_d::getAbility() {
	return "Gains 1$ for every non-empty slot";
}
std::string Item_e::getAbility() {
    return "Every symbol is adjacent to each other";
}