#include "Symbol.h"

int Symbol::createId() const {
	if (icon == ' ') return -1;
	static int temp = 0;
	return temp++;
}

std::string Symbol::getAbility() {
	return "Absolutely nothing";
}

void Symbol::useSymbol() {
    //int idx = boardList.find(this);
}

std::string Symbol::getRarityString() {
    switch (rarity) {
        case Common:
            return "Common";
        case Uncommon:
            return"Uncommon";
        case Rare:
            return"Rare";
        case VeryRare:
            return"Very Rare";
        case Special:
            return "Special";
    }
    return "";
}
