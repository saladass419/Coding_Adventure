#include "memtrace.h"
#include "Board.h"

void Item_TinyPlace::useSymbol() {
    Neutral::isAlwaysAdjacent = true;
}
void Item_LeafClover::useSymbol() {
	for (int i = 0; i < boardList.count; i++) {
		if(Neutral::chanceCalculator(2)){
            boardList.data[i]->addMultiplier(2);
        }
	}
}
void Item_Timer::useSymbol() {
    if(itemsList.find(id)->getValue() == 3) {
        addBonus(6);
    }

    if(itemsList.find(id)->getValue() > 0)
        itemsList.find(id)->addToValue(-1);
    else{
        itemsList.find(id)->setValue(3);
        addBonus(6);
    }
}
void Item_CoinCollector::useSymbol() {
	for(int i = 0; i < boardList.count; i++){
        if(boardList.data[i]->getIcon()=="Co"){
            symbolsList.remove(symbolsList.find(boardList.data[i]->getId()));
            addToValue(1);
        }
    }
    addBonus(getValue());
}
void Item_LovingMother::useSymbol() {
    if(Neutral::chanceCalculator(5)){
        symbolsList.add(new Symbol_Child);
    }
}