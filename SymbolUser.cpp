#include "Board.h"
#include <iostream>

void Symbol_a::useSymbol() {

}
void Symbol_b::useSymbol() {

}
void Symbol_c::useSymbol() {

}
void Symbol_d::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=='a'){
                boardList.data[i]->addMultiplier(2);
                addBonus(2);
            }
        }
    }
}
void Symbol_e::useSymbol() {
	int idx = boardList.find(this);
    if (idx == 0 || idx == 4 || idx == 20 || idx == 24) addBonus(4);
}
void Symbol_f::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()==' '){
                addBonus(1);
            }
        }
    }
}
void Symbol_g::useSymbol() {
	useSymbolWhenRemove();
	symbolsList.remove(symbolsList.find(id));
}
void Symbol_h::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=='b'||boardList.data[i]->getIcon()=='c'){
                boardList.data[i]->addMultiplier(2);
            }
        }
    }
}

void Symbol_i::useSymbol() {
    if(Neutral::chanceCalculator(10)){
        symbolsList.add(new Symbol_c());
    }
}
void Symbol_j::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=='i'){
                Symbol* foundSymbol = symbolsList.find(boardList.data[i]->getId());
                if (foundSymbol == nullptr) return;
                boardList.data[i]->useSymbolWhenRemove();
                symbolsList.remove(foundSymbol);
                addMultiplier(2);
            }
        }
    }
}
void Symbol_k::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++) {
        if (Neutral::isNeighbour(i, idx)) {
            if (boardList.data[i]->getIcon() == 'a') {
                boardList.data[i]->addMultiplier(5);
            }
        }
    }
}
void Symbol_l::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++) {
        if (Neutral::isNeighbour(i, idx)) {
            if (boardList.data[i]->getIcon() == 'h') {
                if(dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan < 4){
                    dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan++;
                }
            }
        }
    }
    dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan--;
    if(dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan <= 0) symbolsList.remove(symbolsList.find(id));
}
void Symbol_m::useSymbol() {
    useSymbolWhenRemove();
    symbolsList.remove(symbolsList.find(id));
}
void Symbol_n::useSymbol() {
    int idx = boardList.find(this);
}