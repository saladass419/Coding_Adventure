#ifndef GAME_H
#define GAME_H

#include "Neutral.h"
#include "Player.h"
#include "Symbol.h"
#include "DerivedSymbols.h"
#include "Item.h"
#include "List.h"
#include "Board.h"
#include "SymbolShop.h"
#include "ItemShop.h"
#include "ReadFile.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include "memtrace.h"

class GameManager {
private:
	int rent;
	int rentCounter;
	int spinCounter;
public:
	GameManager() : rent(25), rentCounter(10), spinCounter(5) { setSymbolTypes(); setItemTypes(); }
	~GameManager() = default;

	int getSpinCounter() const { return spinCounter; }
	int getRentCounter() const { return rentCounter; }

	void gainItemMoney() { player.addToMoney(countItemMoney()); if (countItemMoney() > 0) { std::cout << countItemMoney() << "$ gained this spin from items" << std::endl; } }
	void gainSymbolMoney() { player.addToMoney(countSymbolMoney()); std::cout << countSymbolMoney() << "$ gained this spin from symbols" << std::endl; }

	void printInfo() const;
	void setSymbolTypes();
	void setItemTypes();
	void generateStartingSymbols();
	void displayCurrentSymbols();
	void displayCurrentItems();
	void displaySymbolMoneyDistribution();
	long countSymbolMoney();
	void displayItemMoneyDistribution();
	long countItemMoney();
	void symbolShopping();
	void itemShopping();
	void spinAnimation();
	void spin();
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
}

void GameManager::setItemTypes() {
	itemTypes.add(new Item_a);
	itemTypes.add(new Item_b);
	itemTypes.add(new Item_c);
	itemTypes.add(new Item_d);
}

void GameManager::generateStartingSymbols() {
	symbolsList.add(symbolTypes.getSymbolIcon('a')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('b')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('c')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('d')->clone());
	symbolsList.add(symbolTypes.getSymbolIcon('e')->clone());
}

void clearScreen(char fill = ' ') {
	COORD tl = { 0,0 };
	CONSOLE_SCREEN_BUFFER_INFO s;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(console, &s);
	DWORD written, cells = s.dwSize.X * s.dwSize.Y;
	FillConsoleOutputCharacter(console, fill, cells, tl, &written);
	FillConsoleOutputAttribute(console, s.wAttributes, cells, tl, &written);
	SetConsoleCursorPosition(console, tl);
}

#endif // !GAME_H
