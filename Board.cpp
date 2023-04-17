#include "Board.h"
#include <iostream>
#include "memtrace.h"


void Board::add(Symbol* newData) {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon()==' ') {
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
		if (data[i]->getIcon() != ' ') data[i]->useSymbol();
	}
}

void Board::fillBoard() {
	clearBoard();
	List tempSymbols(symbolsList.data, symbolsList.count);
	shuffle(tempSymbols.data, tempSymbols.count);
	for (int i = 0; i < tempSymbols.count; i++) {
		add(tempSymbols.data[i]->copy());
	}
	Symbol* temp = new Symbol;
	for (int i = tempSymbols.count; i < count; i++) {
		add(temp->clone());
	}
	delete temp;
	shuffle(data, count);
}

void Board::clearBoard() {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() != ' ') remove(data[i]);
	}
}

bool Board::isNeighbour(int a, int b) {
	if (a == b) return false;
	int xa = a / 5;
	int ya = a % 5;
	int xb = b / 5;
	int yb = b % 5;
	if (xa < 0 || xa>4 || ya < 0 || ya>4 || xb < 0 || xb>4 || yb < 0 || yb>4) return false;
	if (ya == yb) {
		if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
	}
	if (ya == yb+1) {
		if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
	}
	if (ya == yb-1) {
		if (xa - 1 == xb || xa == xb || xa + 1 == xb)return true;
	}
	return false;
}