#ifndef ITEMSHOP_H
#define ITEMSHOP_H

#include "Neutral.h"
#include "List.h"
#include "SymbolShop.h"
#include "memtrace.h"

class ItemShop : public SymbolShop {
public:
	ItemShop() {
		count = 3;
		data = new Symbol * [count];
		for (int i = 0; i < count; i++) {
			data[i] = new Symbol;
		}
	}
	~ItemShop() = default;

	void printList() override;
	void fillShop() override;
	void purchase(int idx) override;
};

extern ItemShop itemShopList;

#endif // !ITEMSHOP_H
