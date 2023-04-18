#include "DerivedSymbols.h"

std::string Symbol_a::getAbility() {
	return "";
}
std::string Symbol_b::getAbility() {
	return "Adjacent 'a' gain 2x money, gains 2$ more for every adjacent 'a'";
}
std::string Symbol_c::getAbility() {
	return "Gains 4$ more when it's in a corner";
}
std::string Symbol_d::getAbility() {
	return "";
}
std::string Symbol_e::getAbility() {
	return "";
}
std::string Symbol_f::getAbility() {
	return "Gains 1$ for every adjacent empty slot";
}
std::string Symbol_g::getAbility() {
	return "Destroys itself, gives 1 reroll and 1 remove token";
}
std::string Symbol_h::getAbility() {
	return "";
}
std::string Symbol_i::getAbility() {
	return "Adds 'a' when destroyed";
}
std::string Symbol_j::getAbility() {
	return "Destroys every adjacent 'i', gains 2x money for each";
}
