#ifndef BOARD_H
#define BOARD_H

#include "memtrace.h"
#include "Neutral.h"
#include "List.h"

class Board : public List {
public:
    ///Default Constructor:
    ///Initializes the board with 25 pointers
	Board() {
		count = 25;
		data = new Symbol * [count];
		for (int i = 0; i < count; i++) {
			data[i] = new Symbol;
		}
	}
	~Board() = default;

    ///Adds a symbol to the list
    ///@param newData - pointer to the Symbol
	void add(Symbol* newData) override;

    ///Removes a symbol from the list
    ///@param oldData - pointer to the Symbol
	void remove(Symbol* oldData) override;

    ///Prints the list
	void printList() override;

    ///Calls the useSymbol() function of each Symbol in the list
	void useAll() override;

    ///Clears the list
	void clearBoard();

    ///Fills the list randomly from the player's symbolsList
	void fillBoard(List& sourceList);
};

extern Board boardList;

#endif // !BOARD_H
