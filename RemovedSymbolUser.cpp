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