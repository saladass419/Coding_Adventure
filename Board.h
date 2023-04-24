#ifndef BOARD_H
#define BOARD_H

#include "Neutral.h"
#include "List.h"

class Board : public List {
public:
	Board() {
		count = 25;
		data = new Symbol * [count];
		for (int i = 0; i < count; i++) {
			data[i] = new Symbol;
		}
	}
	~Board() = default;

	void add(Symbol* newData) override;
	void remove(Symbol* oldData) override;
	void printList() override;
	void useAll() override;

	void clearBoard();
	void fillBoard();
};

extern Board boardList;

#endif // !BOARD_H
