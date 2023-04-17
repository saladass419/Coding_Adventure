#include "ItemShop.h"
#include <iostream>
#include "memtrace.h"

void ItemShop::printList() {
	for (int i = 0; i < count; i++) {
		std::cout << i + 1 << ": " << data[i]->getIcon() << " | " << data[i]->getAbility() << std::endl;
	}
	std::cout << std::endl;
}
void ItemShop::fillShop() {
	clearShop();
	List temp;
	for (int i = 0; i < itemTypes.count; i++) {
		for (int j = 0; j < itemTypes.data[i]->getRarity() + 1; j++) {
			temp.add(itemTypes.data[i]->copy());
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
void ItemShop::purchase(int idx) {
	itemsList.add(data[idx]->clone());
}