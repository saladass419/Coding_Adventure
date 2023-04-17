#ifndef BOARD_H
#define BOARD_H

#include "Neutral.h"
#include "List.h"
#include "memtrace.h"

class Board : public List {
public:
	Board() {
		count = 25;
		data = new Symbol * [count];
		for (int i = 0; i < count; i++) {
			data[i] = new Symbol;
		}
	}
	~Board() {}

	void add(Symbol* newData) override;
	void remove(Symbol* oldData) override;
	void printList() override;
	void useAll() override;

	void clearBoard();
	void fillBoard();
	bool isNeighbour(int a, int b);
	int adjacentSymbols(int idx, char icon);
};

extern Board boardList;

#endif // !BOARD_H
