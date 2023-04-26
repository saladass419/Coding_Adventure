#ifndef ITEMSHOP_H
#define ITEMSHOP_H

#include "Neutral.h"
#include "List.h"
#include "SymbolShop.h"

class ItemShop : public SymbolShop {
public:
	ItemShop() :SymbolShop() { }
	~ItemShop() = default;

	void printList() override;
	void fillShop(int turn) override;
	void purchase(int idx) override;

    static int calculateChances(int turn, int rarity);
};

extern ItemShop itemShopList;

#endif // !ITEMSHOP_H
