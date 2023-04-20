#include "Board.h"
#include "Player.h"

void Symbol::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_a::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_b::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_c::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_d::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_e::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_f::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_g::useSymbolWhenRemove() {
	int idx = boardList.find(this);

	player.gainToken("reroll");
	player.gainToken("remove");
}
void Symbol_h::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_i::useSymbolWhenRemove() {
	int idx = boardList.find(this);

	symbolsList.add(new Symbol_a);
}
void Symbol_j::useSymbolWhenRemove() {
	//int idx = boardList.find(this);
}
void Symbol_k::useSymbolWhenRemove() {
    //int idx = boardList.find(this);
}
void Symbol_l::useSymbolWhenRemove() {
    //int idx = boardList.find(this);
}
void Symbol_m::useSymbolWhenRemove() {
    int idx = boardList.find(this);

    for(int i = 0; i < boardList.count; i++){
        if (Neutral::isNeighbour(i, idx) && boardList.data[i]->getIcon()!=' ') {
            boardList.data[i]->addMultiplier(2);
        }
    }
}
void Symbol_n::useSymbolWhenRemove() {
    //int idx = boardList.find(this);
}