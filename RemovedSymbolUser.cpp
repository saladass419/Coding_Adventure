#include "Board.h"
#include "Player.h"

void Symbol_Bartender::useSymbolWhenRemove() {
	symbolsList.add(new Symbol_Flower);
}
void Symbol_Sommelier::useSymbolWhenRemove() {
    int idx = boardList.find(this);

    for(int i = 0; i < boardList.count; i++){
        if (Neutral::isNeighbour(i, idx) && boardList.data[i]->getIcon()!="  ") {
            boardList.data[i]->addMultiplier(2);
        }
    }
}
void Symbol_Granny::useSymbolWhenRemove() {
    addBonus(getValue());
    for(int i = 0; i < boardList.count; i++) {
        if (boardList.data[i]->getIcon() == "Ow") {
            if (Neutral::chanceCalculator(50)) {
                symbolsList.remove(symbolsList.find(boardList.data[i]->getId()));
                symbolsList.add(new Symbol_Drunk);
            }
            break;
        }
    }
}
void Symbol_TreasureChest::useSymbolWhenRemove() {
    addBonus(29);
}