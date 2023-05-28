#include "Board.h"

void Item_a::useSymbol() {
	for (int i = 0; i < boardList.count; i++) {
		if (boardList.data[i]->getIcon() == "  ") {
			addBonus(1);
		}
	}
}
void Item_b::useSymbol() {
	for (int i = 0; i < boardList.count; i++) {
		if (boardList.data[i]->getIcon() == "Fl") {
			addBonus(1);
		}
	}
}
void Item_c::useSymbol() {
    if(dynamic_cast<Item_c*>(itemsList.find(id))->spins == 3) {
        addBonus(3);
    }
    if(dynamic_cast<Item_c*>(itemsList.find(id))->spins > 0)
        dynamic_cast<Item_c*>(itemsList.find(id))->spins--;
    else{
        dynamic_cast<Item_c*>(itemsList.find(id))->spins = 3;
        addBonus(3);
    }
}
void Item_d::useSymbol() {
	for (int i = 0; i < boardList.count; i++) {
		if (boardList.data[i]->getIcon() != "  ") {
			addBonus(1);
		}
	}
}
void Item_e::useSymbol() {
    Neutral::isAlwaysAdjacent = true;
}