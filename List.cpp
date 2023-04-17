#include "List.h"
#include <iostream>
#include "memtrace.h" 

void List::add(Symbol* newData) {
	if (newData == nullptr) return;
	
	Symbol** temp = new Symbol * [count + 1];
	for (int i = 0; i < count; i++) {
		temp[i] = data[i];
	}
	temp[count] = newData;
	delete[]data;
	count++;
	data = new Symbol * [count];
	for (int i = 0; i < count; i++) {
		data[i] = temp[i];
	}
	delete[]temp;
}

void List::remove(Symbol* oldData) {
	if (!contains(oldData)) return;

	Symbol** temp = new Symbol * [count - 1];
	int o = 0;
	for (int i = 0; i < count; i++) {
		if(data[i]!=oldData)
			temp[o++] = data[i];
	}
	delete oldData;
	delete[]data;
	count--;
	data = new Symbol * [count];
	for (int i = 0; i < count; i++) {
		data[i] = temp[i];
	}
	delete[]temp;
}

void List::printList() {
	for (int i = 0; i < count; i++) std::cout << data[i]->getId()<<" ";
	std::cout << std::endl;
}

void List::useAll() {
	for (int i = 0; i < count; i++) {
		data[i]->useSymbol();
	}
}

bool List::contains(Symbol* other) {
	for (int i = 0; i < count; i++) {
		if (data[i] == other) return true;
	}
	return false;
}

int List::find(Symbol* other) {
	for (int i = 0; i < count; i++) {
		if (data[i] == other) return i;
	}
	return -1;
}

int List::find(int id) {
	for (int i = 0; i < count; i++) {
		if (data[i]->getId() == id) return i;
	}
	return -1;
}

Symbol* List::getSymbolbyIcon(char _icon) {
	for (int i = 0; i < count; i++) {
		if (data[i]->getIcon() == _icon) return data[i];
	}
	return nullptr;
}




