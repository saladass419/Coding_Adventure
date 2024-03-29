#ifndef GAME_H
#define GAME_H

#include "memtrace.h"
#include "gtest_lite.h"
#include "Neutral.h"
#include "Player.h"
#include "Item.h"
#include "Symbol.h"
#include "DerivedSymbols.h"
#include "List.h"
#include "Board.h"
#include "ItemShop.h"
#include "SymbolShop.h"
#include <iostream>
#include <limits>

class GameManager {
private:
	int rent; ///< The amount of money needed at the end of the month (int)
	int rentCounter; ///< The amount of payments left (int)
	int spinCounter; ///< The amount of spins left (int)
public:
    ///Default Constructor:
    ///rent = 50, rentCounter = 10, spinCounter = 5
    ///sets the symbolTypes list, sets the itemTypes list
	GameManager() : rent(50), rentCounter(10), spinCounter(5) { setSymbolTypes(); setItemTypes(); }
	~GameManager() = default;

    void testingGame();
    ///Returns the spinCounter value
    ///@return amount of spins left (int)
	int getSpinCounter() const { return spinCounter; }
    ///Return the rentCounter value
    ///@return amount of payments left (int)
	int getRentCounter() const { return rentCounter; }

    ///Adds money to the player's account from the items
	static void gainItemMoney() { player.addToMoney(countItemMoney()); if (countItemMoney() > 0) { std::cout << countItemMoney() << "$ gained this spin from items" << std::endl; } }
    ///Adds money to the player's account from the symbols
	static void gainSymbolMoney() { player.addToMoney(countSymbolMoney()); std::cout << countSymbolMoney() << "$ gained this spin from symbols" << std::endl; }

    ///Prints out some basic information
	void printInfo() const;
    ///Sets the basic symbol types in the symbolTypes list
	static void setSymbolTypes();
    ///Sets the basic item types in the itemTypes list
	static void setItemTypes();
    ///Generates the starting symbols and puts them in the symbolsList
	static void generateStartingSymbols();
    ///Displays every symbol in the symbolsList
	static void displayCurrentSymbols();
    ///Displays every item in the itemsList
	static void displayCurrentItems();
    ///Displays the amount of money each symbol made this spin
	static void displaySymbolMoneyDistribution();
    ///Counts the amount of money the symbols earned in total this spin
    ///@return amount of money in total (long)
	static long countSymbolMoney();
    ///Displays the amount of money each item made this spin
	static void displayItemMoneyDistribution();
    ///Counts the amount of money the items earned in total this spin
    ///@return amount of money in total (long)
	static long countItemMoney();
    ///Opens the symbol shop and allows the player to use it
	void symbolShopping();
    ///Opens the item shop and allows the player to use it
	void itemShopping();
    ///Animation for spin effect
	void spinAnimation() const;
    ///Randomly fill the board with symbols from the symbolsList
	static void spin();
    ///Increases the amount of rent that needs to be payed
	void growRent();
    ///The player pays the rent
    ///@return whether the player successfully payed the rent or not (bool)
	bool payRent();
    ///Allows the player to remove a symbol from the symbolsList
	void checkForRemove();
};

void GameManager::setSymbolTypes() {
	symbolTypes.add(new Symbol_Flower);
	symbolTypes.add(new Symbol_Wine);
	symbolTypes.add(new Symbol_Dog);
	symbolTypes.add(new Symbol_Bee);
	symbolTypes.add(new Symbol_Sun);
	symbolTypes.add(new Symbol_BeeHive);
	symbolTypes.add(new Symbol_Rain);
	symbolTypes.add(new Symbol_Drunk);
	symbolTypes.add(new Symbol_Bartender);
	symbolTypes.add(new Symbol_Grape);
    symbolTypes.add(new Symbol_FineWine);
    symbolTypes.add(new Symbol_Child);
    symbolTypes.add(new Symbol_Sommelier);
    symbolTypes.add(new Symbol_Vet);
    symbolTypes.add(new Symbol_Owner);
    symbolTypes.add(new Symbol_Stranger);
    symbolTypes.add(new Symbol_Insect);
    symbolTypes.add(new Symbol_Granny);
    symbolTypes.add(new Symbol_TreasureChest);
    symbolTypes.add(new Symbol_TreasureKey);
    symbolTypes.add(new Symbol_Coin);

}

void GameManager::setItemTypes() {
	itemTypes.add(new Item_TinyPlace);
	itemTypes.add(new Item_LeafClover);
	itemTypes.add(new Item_Timer);
	itemTypes.add(new Item_CoinCollector);
    itemTypes.add(new Item_MailMan);
    itemTypes.add(new Item_LovingMother);

}

void GameManager::generateStartingSymbols() {
	symbolsList.add(symbolTypes.getSymbolIcon("Fl")->clone());
	symbolsList.add(symbolTypes.getSymbolIcon("Wi")->clone());
	symbolsList.add(symbolTypes.getSymbolIcon("Do")->clone());
	symbolsList.add(symbolTypes.getSymbolIcon("Co")->clone());
	symbolsList.add(symbolTypes.getSymbolIcon("Tk")->clone());
}

#endif // !GAME_H
