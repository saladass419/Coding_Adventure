#include "SymbolShop.h"
#include <iostream>
#include "memtrace.h"

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
		std::cout << i + 1 << ": " << data[i]->getIcon() << " - " << data[i]->getBaseMoney() << "$ | " << data[i]->getAbility() << std::endl;
	}
	std::cout << std::endl;
}

void SymbolShop::fillShop() {
	clearShop();
	List temp;
	for (int i = 0; i < symbolTypes.count; i++) {
		for (int j = 0; j < symbolTypes.data[i]->getRarity()+1; j++) {
			temp.add(symbolTypes.data[i]->copy());
		}
	}
	shuffle(temp.data, temp.count);
	int added = 0;
	for (int i = 0; i < temp.count; i++) {
		if (getSymbolIcon(temp.data[i]->getIcon()) == nullptr) {
			add(temp.data[i]->copy());
			added++;
		}
		if (added >= 3) break;
	}
}