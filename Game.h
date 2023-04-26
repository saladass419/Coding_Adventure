#ifndef GAME_H
#define GAME_H

#include "Neutral.h"
#include "Player.h"
#include "Item.h"
#include "Symbol.h"
#include "DerivedSymbols.h"
#include "List.h"
#include "Board.h"
#include "ItemShop.h"
#include "SymbolShop.h"
#include "ReadFile.h"
#include <iostream>
#include <limits>

class GameManager {
private:
	int rent;
	int rentCounter;
	int spinCounter;
public:
	GameManager() : rent(50), rentCounter(10), spinCounter(5) { setSymbolTypes(); setItemTypes(); }
	~GameManager() = default;

	int getSpinCounter() const { return spinCounter; }
	int getRentCounter() const { return rentCounter; }

	static void gainItemMoney() { player.addToMoney(countItemMoney()); if (countItemMoney() > 0) { std::cout << countItemMoney() << "$ gained this spin from items" << std::endl; } }
	static void gainSymbolMoney() { player.addToMoney(countSymbolMoney()); std::cout << countSymbolMoney() << "$ gained this spin from symbols" << std::endl; }

	void printInfo() const;
	static void setSymbolTypes();
	static void setItemTypes();
	static void generateStartingSymbols();
	static void displayCurrentSymbols();
	static void displayCurrentItems();
	static void displaySymbolMoneyDistribution();
	static long countSymbolMoney();
	static void displayItemMoneyDistribution();
	static long countItemMoney();
	void symbolShopping();
	void itemShopping();
	void spinAnimation() const;
	static void spin();
	void growRent();
	bool payRent();
	void checkForRemove();
};

void GameManager::setSymbolTypes() {
	symbolTypes.add(new Symbol_a); 
	symbolTypes.add(new Symbol_b);
	symbolTypes.add(new Symbol_c);
	symbolTypes.add(new Symbol_d);
	symbolTypes.add(new Symbol_e);
	symbolTypes.add(new Symbol_f);
	symbolTypes.add(new Symbol_g);
	symbolTypes.add(new Symbol_h);
	symbolTypes.add(new Symbol_i);
	symbolTypes.add(new Symbol_j);
    symbolTypes.add(new Symbol_k);
    symbolTypes.add(new Symbol_l);
    symbolTypes.add(new Symbol_m);
    symbolTypes.add(new Symbol_n);
}

void GameManager::setItemTypes() {
	itemTypes.add(new Item_a);
	itemTypes.add(new Item_b);
	itemTypes.add(new Item_c);
	itemTypes.add(new Item_d);
    itemTypes.add(new Item_e);
}

void GameManager::generateStartingSymbols() {
	symbolsList.add(symbolTypes.getSymbolIcon('a')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('b')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('c')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('d')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('e')->clone());
}

#endif // !GAME_H
