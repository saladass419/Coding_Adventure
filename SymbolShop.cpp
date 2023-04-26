#include "SymbolShop.h"
#include <iostream>

void SymbolShop::add(Symbol* newData) {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() == ' ') {
			delete data[i];
			data[i] = newData;
			return;
		}
	}
}

void SymbolShop::remove(Symbol* oldData) {
	if (!contains(oldData)) return;
	for (int i = 0; i < count; i++) {
		if (data[i] == oldData) {
			delete data[i];
			data[i] = new Symbol;
			return;
		}
	}
}

void SymbolShop::clearShop() {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() != ' ') remove(data[i]);
	}
}

void SymbolShop::purchase(int idx) {
	symbolsList.add(data[idx]->clone());
}

void SymbolShop::printList() {
	for (int i = 0; i < count; i++) {
		std::cout << i + 1 << ": "<< data[i]->getIcon() << " - " << data[i]->getBaseMoney() << "$ | " << data[i]->getAbility() << std::endl;
	}
	std::cout << std::endl;
}

void SymbolShop::fillShop(int turn) {
	clearShop();
	List temp;
	for (int i = 0; i < symbolTypes.count; i++) {
        int amount = calculateChances(turn,symbolTypes.data[i]->getRarity());
		for (int j = 0; j < amount; j++) {
			temp.add(symbolTypes.data[i]->copy());
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

int SymbolShop::calculateChances(int turn, int rarity) {
    int value;

    if (turn>7) value = (4-rarity)*2;
    else if(turn>3) value = (5-rarity)*2+2;
    else value = rarity*2+2;

    return value;
}
