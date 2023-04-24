#include "Board.h"
#include <iostream>

void Symbol_a::useSymbol() {
	//int idx = boardList.find(this);
}
void Symbol_b::useSymbol() {
	//int idx = boardList.find(this);
}
void Symbol_c::useSymbol() {

}
void Symbol_d::useSymbol() {
    List neighbours = boardList.getNeighbours(this);
    for(int i = 0; i < neighbours.count; i++){
        if(neighbours.data[i]->getIcon()=='a'){
            neighbours.data[i]->addMultiplier(2);
            addBonus(2);
        }
    }
}
void Symbol_e::useSymbol() {
	int idx = boardList.find(this);
    if (idx == 0 || idx == 4 || idx == 20 || idx == 24) addBonus(4);
}
void Symbol_f::useSymbol() {
    List neighbours = boardList.getNeighbours(this);
    for(int i = 0; i < neighbours.count; i++){
        if(neighbours.data[i]->getIcon()==' '){
            addBonus(1);
        }
    }
}
void Symbol_g::useSymbol() {
	int idx = boardList.find(this);
	useSymbolWhenRemove();
	symbolsList.remove(symbolsList.find(id));
}
void Symbol_h::useSymbol() {
    List neighbours = boardList.getNeighbours(this);
    for(int i = 0; i < neighbours.count; i++){
        if(neighbours.data[i]->getIcon()=='b'||neighbours.data[i]->getIcon()=='c'){
            neighbours.data[i]->addMultiplier(2);
        }
    }
}

void Symbol_i::useSymbol() {
	int idx = boardList.find(this);

}
void Symbol_j::useSymbol() {
    List neighbours = boardList.getNeighbours(this);
    for(int i = 0; i < neighbours.count; i++){
        if(neighbours.data[i]->getIcon()=='i'){
            Symbol* foundSymbol = symbolsList.find(neighbours.data[i]->getId());
            if (foundSymbol == nullptr) return;
            neighbours.data[i]->useSymbolWhenRemove();
            symbolsList.remove(foundSymbol);
            addMultiplier(2);
        }
    }
}
void Symbol_k::useSymbol() {
    List neighbours = boardList.getNeighbours(this);
    for(int i = 0; i < neighbours.count; i++){
        if(neighbours.data[i]->getIcon()=='a'){
            neighbours.data[i]->addMultiplier(5);
        }
    }
}
void Symbol_l::useSymbol() {
    List neighbours = boardList.getNeighbours(this);
    for(int i = 0; i < neighbours.count; i++){
        if(neighbours.data[i]->getIcon()=='h'){
            if(dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan < 4){
                dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan++;
            }
        }
    }
    dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan--;
    if(dynamic_cast<Symbol_l*>(symbolsList.find(id))->lifeSpan <= 0) symbolsList.remove(symbolsList.find(id));
}
void Symbol_m::useSymbol() {
    int idx = boardList.find(this);
    useSymbolWhenRemove();
    symbolsList.remove(symbolsList.find(id));
}
void Symbol_n::useSymbol() {
    int idx = boardList.find(this);
}