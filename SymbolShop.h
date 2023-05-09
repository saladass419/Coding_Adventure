#ifndef SHOP_H
#define SHOP_H

#include "Neutral.h"
#include "List.h"

class SymbolShop : public List {
public:
    ///Default Constructor:
    ///Initializes the list of 3 symbols
	SymbolShop() {
		count = 3;
		data = new Symbol * [count];
		for (int i = 0; i < count; i++) {
			data[i] = new Symbol;
		}
	}
	~SymbolShop() = default;

    ///Adds a symbol to the list
    ///@param newData - pointer to the desired symbol (Symbol*)
	void add(Symbol* newData) override;
    ///Removes a symbol from the list
    ///@param oldData - pointer to the desired symbol (Symbol*)
	void remove(Symbol* oldData) override;
    ///Prints out the contents of the store
	void printList() override;

    ///Calculates the chances of a symbol successfully landing in the store
    ///@param turn - state of the game in turns
    ///@param rarity - rarity of the symbol
    ///@return chances of this symbol landing in the store (int)
    static int calculateChances(int turn, int rarity);

    ///Clears the elements of the list
	void clearShop();
    ///Fills the shop with random symbols from symbolTypes
    ///@param turn - state of the game in turns
	virtual void fillShop(int turn);
    ///Adds a symbol from the shop to the symbolsList
    ///@param idx - the index of the symbol that needs to be added
	virtual void purchase(int idx);
};

extern SymbolShop symbolShopList;

#endif // !SHOP_H
