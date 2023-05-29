#include "memtrace.h"
#include "Item.h"

std::string Item_TinyPlace::getAbility() {
	return "TinyPlace: Every symbol is adjacent to each other";
}
std::string Item_LeafClover::getAbility() {
	return "LeafClover: Every symbol has a 2% chance to gain 2x money";
}
std::string Item_Timer::getAbility() {
	return "Timer: Gains 6$ every 3 turns";
}
std::string Item_CoinCollector::getAbility() {
	return "CoinCollector: Consumes every 'Coin', gain 1$ after each 'Coin' in it";
}
std::string Item_MailMan::getAbility() {
    return "MailMan";
}
std::string Item_LovingMother::getAbility() {
    return "LovingMother: Has a 5% chance to add a 'Child'";
}