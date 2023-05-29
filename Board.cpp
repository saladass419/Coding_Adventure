#include "Board.h"
#include "memtrace.h"
#include <iostream>

void Board::add(Symbol* newData) {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() == "  ") {
			delete data[i];
			data[i] = newData;
			return;
		}
	}
}

void Board::remove(Symbol* oldData) {
	if (!contains(oldData)) return;
	for (int i = 0; i < count; i++) {
		if (data[i] == oldData) {
			delete data[i];
			data[i] = new Symbol; 
			return;
		}
	}
}

void Board::printList() {
	for (int x = 0; x < 5; x++) {
		std::cout << "\t|";
		for (int y = 0; y < 5; y++) {
			std::cout << data[x * 5 + y]->getIcon()<<"|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Board::useAll() {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() != "  ") data[i]->useSymbol();
	}
}

void Board::fillBoard(List& sourceList) {
	clearBoard();
	List tempSymbols(sourceList.data, sourceList.count);
    Neutral::shuffle(tempSymbols.data, tempSymbols.count);
	for (int i = 0; i < (tempSymbols.count>count?count:tempSymbols.count); i++) {
		add(tempSymbols.data[i]->copy());
	}
	auto* temp = new Symbol;
	for (int i = tempSymbols.count; i < count; i++) {
		add(temp->clone());
	}
	delete temp;
    Neutral::shuffle(data, count);
}

void Board::clearBoard() {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() != "  ") remove(data[i]);
	}
}

