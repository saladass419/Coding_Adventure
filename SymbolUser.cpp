#include "Board.h"
#include <iostream>

void Symbol::useSymbol() {
	int idx = boardList.find(this);
}
void Symbol_a::useSymbol() {
	int idx = boardList.find(this);
	
}
void Symbol_b::useSymbol() {
	int idx = boardList.find(this);
	for (int i = 0; i < 25; i++) {
		if (Neutral::isNeighbour(i, idx) && boardList.data[i]->getIcon() == 'a') {
			boardList.data[i]->addMultiplier(2);
			addBonus(2);
		}
	}
}
void Symbol_c::useSymbol() {
	int idx = boardList.find(this);
	if (idx == 0 || idx == 4 || idx == 20 || idx == 24) addBonus(4);
}
void Symbol_d::useSymbol() {
	int idx = boardList.find(this);

}
void Symbol_e::useSymbol() {
	int idx = boardList.find(this);
}
void Symbol_f::useSymbol() {
	int idx = boardList.find(this);
	for (int i = 0; i < 25; i++) {
		if (Neutral::isNeighbour(i, idx) && boardList.data[i]->getIcon() == ' ') {
			addBonus(1);
		}
	}
}
void Symbol_g::useSymbol() {
	int idx = boardList.find(this);
	useSymbolWhenRemove();
	symbolsList.remove(symbolsList.data[symbolsList.find(id)]);
}
void Symbol_h::useSymbol() {
	int idx = boardList.find(this);

}
void Symbol_i::useSymbol() {
	int idx = boardList.find(this);

}
void Symbol_j::useSymbol() {
	int idx = boardList.find(this);
	for (int i = 0; i < 25; i++) {
		if (Neutral::isNeighbour(i, idx) && boardList.data[i]->getIcon() == 'i') {
			int foundidx = symbolsList.find(boardList.data[i]->getId());
			if (foundidx == -1) return;
			boardList.data[i]->useSymbolWhenRemove(); // will need to fix this, so that it is called automatically
			symbolsList.remove(symbolsList.data[foundidx]);
			addMultiplier(2);
		}
	}
}
void Symbol_k::useSymbol() {
    int idx = boardList.find(this);
    for (int i = 0; i < 25; i++) {
        if (Neutral::isNeighbour(i, idx) && boardList.data[i]->getIcon() == 'a') {
            boardList.data[i]->addMultiplier(5);
        }
    }
}
void Symbol_l::useSymbol() {
    int idx = boardList.find(this);
    for (int i = 0; i < 25; i++) {
        if (Neutral::isNeighbour(i, idx) && boardList.data[i]->getIcon() == 'h') {
            if(dynamic_cast<Symbol_l*>(symbolsList.data[symbolsList.find(id)])->lifeSpan < 4){
                dynamic_cast<Symbol_l*>(symbolsList.data[symbolsList.find(id)])->lifeSpan++;
            }
        }
    }
    dynamic_cast<Symbol_l*>(symbolsList.data[symbolsList.find(id)])->lifeSpan--;
    if(dynamic_cast<Symbol_l*>(symbolsList.data[symbolsList.find(id)])->lifeSpan <= 0) symbolsList.remove(symbolsList.data[symbolsList.find(id)]);
}
void Symbol_m::useSymbol() {
    int idx = boardList.find(this);
    useSymbolWhenRemove();
    symbolsList.remove(symbolsList.data[symbolsList.find(id)]);
}
void Symbol_n::useSymbol() {
    int idx = boardList.find(this);
}