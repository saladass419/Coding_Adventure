#include "DerivedSymbols.h"

std::string Symbol_a::getAbility() {
	return "";
}
std::string Symbol_b::getAbility() {
	return "";
}
std::string Symbol_c::getAbility() {
	return "";
}
std::string Symbol_d::getAbility() {
	return "Adjacent 'a' gain 2x money, gains 2$ more for every adjacent 'a'";
}
std::string Symbol_e::getAbility() {
	return "Gains 4$ more when it's in a corner";
}
std::string Symbol_f::getAbility() {
	return "Gains 1$ for every adjacent empty slot";
}
std::string Symbol_g::getAbility() {
	return "Destroys itself, gives 1 reroll and 1 remove token";
}
std::string Symbol_h::getAbility() {
	return "Adjacent 'b' and 'c' gain 2x money";
}
std::string Symbol_i::getAbility() {
	return "Adds 'a' when destroyed";
}
std::string Symbol_j::getAbility() {
	return "Destroys adjacent 'i', gains 2x money for each";
}
std::string Symbol_k::getAbility() {
    return "Adjacent 'a' gain 5x money";
}
std::string Symbol_l::getAbility() {
    return "Destroys itself after 3 spins, 1 spin later if adjacent to 'h'";
}
std::string Symbol_m::getAbility() {
    return "Destroys itself, adjacent symbols gain 2x money";
}
std::string Symbol_n::getAbility() {
    return "";
}
