#include "ItemShop.h"
#include <iostream>

void ItemShop::printList() {
	for (int i = 0; i < count; i++) {
		std::cout << i + 1 << ": " << data[i]->getIcon()<<" | " << data[i]->getAbility() << std::endl;
	}
	std::cout << std::endl;
}
void ItemShop::fillShop(int turn) {
	clearShop();
	List temp;
	for (int i = 0; i < itemTypes.count; i++) {
        int amount = calculateChances(turn,itemTypes.data[i]->getRarity());
		for (int j = 0; j < amount; j++) {
			temp.add(itemTypes.data[i]->copy());
		}
	}
    Neutral::shuffle(temp.data, temp.count);
	int added = 0;
	for (int i = 0; i < temp.count; i++) {
		if (getSymbolIcon(temp.data[i]->getIcon()) == nullptr) {
			add(temp.data[i]->copy());
			added++;
		}
		if (added >= 3) break;
	}
}
void ItemShop::purchase(int idx) {
	itemsList.add(data[idx]->clone());
}

int ItemShop::calculateChances(int turn, int rarity) {
    int value;

    if (turn>7) value = (5-rarity)*2;
    else if(turn>3) value = abs(4-rarity)*2+2;
    else value = rarity*2+2;

    return value;
}