#include "Board.h"
#include <iostream>

void Symbol_Bee::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=="Fl"){
                boardList.data[i]->addMultiplier(2);
                addBonus(2);
            }
        }
    }
}
void Symbol_Sun::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++) {
        if (Neutral::isNeighbour(i, idx)) {
            if (boardList.data[i]->getIcon() == "Fl") {
                boardList.data[i]->addMultiplier(5);
                addBonus(3);
            }
        }
    }
}
void Symbol_BeeHive::useSymbol() {
    if(Neutral::chanceCalculator(10)){
        symbolsList.add(new Symbol_Bee);
    }
}
void Symbol_Rain::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=="Fl"){
                boardList.data[i]->addMultiplier(3);
            }
        }
    }
    if(Neutral::chanceCalculator(5)){
        symbolsList.add(new Symbol_Flower);
    }
    dynamic_cast<Symbol_Rain*>(symbolsList.find(id))->lifeSpan--;
    if(dynamic_cast<Symbol_Rain*>(symbolsList.find(id))->lifeSpan <= 0) symbolsList.remove(symbolsList.find(id));
}

void Symbol_Drunk::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=="Wi"||boardList.data[i]->getIcon()=="Fw"){
                boardList.data[i]->addMultiplier(2);
                addBonus(3);
                Symbol* foundSymbol = symbolsList.find(boardList.data[i]->getId());
                symbolsList.remove(foundSymbol);
            }
        }
    }
}
void Symbol_Bartender::useSymbol() {
    if(Neutral::chanceCalculator(15)){
        symbolsList.add(new Symbol_Wine);
    }
}
void Symbol_Grape::useSymbol() {
    if(Neutral::chanceCalculator(5)){
        symbolsList.add(new Symbol_FineWine);
        symbolsList.remove(symbolsList.find(id));
    } else if(Neutral::chanceCalculator(10)){
        symbolsList.add(new Symbol_Wine);
        symbolsList.remove(symbolsList.find(id));
    }
}
void Symbol_FineWine::useSymbol() {
    if(Neutral::chanceCalculator(20)){
        addBonus(5);
    }
}
void Symbol_Sommelier::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=="Wi"){
                addBonus(1);
                Symbol* foundSymbol = symbolsList.find(boardList.data[i]->getId());
                symbolsList.remove(foundSymbol);
            }
            if(boardList.data[i]->getIcon()=="Fw"){
                boardList.data[i]->addMultiplier(2);
                addBonus(20);
                Symbol* foundSymbol = symbolsList.find(boardList.data[i]->getId());
                symbolsList.remove(foundSymbol);
            }
        }
    }
}

void Symbol_Child::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++) {
        if (Neutral::isNeighbour(i, idx)) {
            if (boardList.data[i]->getIcon() == "Do") {
                boardList.data[i]->addMultiplier(2);
                addMultiplier(2);
            }
        }
    }
}
void Symbol_Vet::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++) {
        if (Neutral::isNeighbour(i, idx)) {
            if (boardList.data[i]->getIcon() == "Do") {
                boardList.data[i]->addBonus(5);
                addBonus(3);
            }
        }
    }
}
void Symbol_Owner::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++){
        if(Neutral::isNeighbour(i,idx)){
            if(boardList.data[i]->getIcon()=="Do"){
                boardList.data[i]->addBonus(2);
            }
            if(boardList.data[i]->getIcon()=="Ch"){
                addBonus(3);
            }
        }
    }
}
void Symbol_Stranger::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++) {
        if (Neutral::isNeighbour(i, idx)) {
            if (boardList.data[i]->getIcon() == "Do") {
                if(Neutral::chanceCalculator(80)){
                    boardList.data[i]->addBonus(4);
                    addMultiplier(2);
                }
                else{
                    boardList.data[i]->addBonus(-(int)INFINITY);
                }
            }
        }
    }
}
void Symbol_Insect::useSymbol() {
    int idx = boardList.find(this);
    for(int i = 0; i < boardList.count; i++) {
        if (Neutral::isNeighbour(i, idx)) {
            if (boardList.data[i]->getIcon() == "Fl") {
                if(Neutral::chanceCalculator(10)){
                    Symbol* foundSymbol = symbolsList.find(boardList.data[i]->getId());
                    symbolsList.remove(foundSymbol);
                }
                else {
                    boardList.data[i]->addBonus(-(int)INFINITY);
                }
            }
            if (boardList.data[i]->getIcon() == "In") {
                addBonus(5);
            }
        }
    }
}