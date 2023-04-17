#ifndef SHOP_H
#define SHOP_H

#include "Neutral.h"
#include "List.h"
#include "memtrace.h"

class SymbolShop : public List {
public:
	SymbolShop() {
		count = 3;
		data = new Symbol * [count];
		for (int i = 0; i < count; i++) {
			data[i] = new Symbol;
		}
	}
	~SymbolShop() = default;

	void add(Symbol* newData) override;
	void remove(Symbol* oldData) override;
	void printList() override;

	void clearShop();
	virtual void fillShop();
	virtual void purchase(int idx);
};

extern SymbolShop symbolShopList;

#endif // !SHOP_H
