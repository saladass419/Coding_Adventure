#include "Board.h"
#include "memtrace.h"

void Item_a::useSymbol() {
	int idx = boardList.find(this);
	for (int i = 0; i < boardList.count; i++) {
		if (boardList.data[i]->getIcon() == ' ') {
			addBonus(1);
		}
	}
}
void Item_b::useSymbol() {
	int idx = boardList.find(this);
	for (int i = 0; i < boardList.count; i++) {
		if (boardList.data[i]->getIcon() == 'a') {
			addBonus(1);
		}
	}
}
void Item_c::useSymbol() {
	int idx = boardList.find(this);
	static int turn = 3;
	if (turn == 0) { addBonus(3); turn = 3; }
	else { turn--; }
}
void Item_d::useSymbol() {
	int idx = boardList.find(this);
	for (int i = 0; i < boardList.count; i++) {
		if (boardList.data[i]->getIcon() != ' ') {
			addBonus(1);
		}
	}
}