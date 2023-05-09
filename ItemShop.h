#ifndef ITEMSHOP_H
#define ITEMSHOP_H

#include "Neutral.h"
#include "List.h"
#include "SymbolShop.h"

class ItemShop : public SymbolShop {
public:
	ItemShop() :SymbolShop() { }
	~ItemShop() = default;

    ///Prints the contents of the shop
	void printList() override;
    ///Fills the shop with random items from itemTypes
    ///@param turn - state of the game in turns
	void fillShop(int turn) override;
    ///Adds an item from the shop to the itemsList
    ///@param idx - the index of the item that needs to be added
	void purchase(int idx) override;

    ///Calculates the chances of an item successfully landing in the store
    ///@param turn - state of the game in turns
    ///@param rarity - rarity of the item
    ///@return chances of this item landing in the store (int)
    static int calculateChances(int turn, int rarity);
};

extern ItemShop itemShopList;

#endif // !ITEMSHOP_H
