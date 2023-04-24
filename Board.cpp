#include "Board.h"
#include <iostream>

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
    Neutral::shuffle(tempSymbols.data, tempSymbols.count);
	for (int i = 0; i < (tempSymbols.count>count?count:tempSymbols.count); i++) {
		add(tempSymbols.data[i]->copy()); //fill with symbols from the list
	}
	auto* temp = new Symbol;
	for (int i = tempSymbols.count; i < count; i++) { //fill with empty symbols
		add(temp->clone());
	}
	delete temp;
    Neutral::shuffle(data, count);
}

void Board::clearBoard() {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() != ' ') remove(data[i]);
	}
}

/*List Board::getNeighbours(Symbol *symbol) {
    int idx = boardList.find(symbol);
    List result;
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(idx,i)){
            result.add(boardList.data[i]); //should add the clone, otherwise it deletes the list twice -> fix this damn thing
        }
    }
    return result;
}*/
