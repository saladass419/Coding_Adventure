#ifndef LIST_H
#define LIST_H

#include "Symbol.h"
#include "Item.h"
#include "DerivedSymbols.h"

class List {
public:
	Symbol** data;
	int count;

	List() : data(nullptr), count(0) {}
	List(Symbol** _data, int _count) : data(new Symbol* [_count]), count(_count) {
		for (int i = 0; i < count; i++) {
			data[i] = _data[i]->copy();
		}
	}
	~List() {
		for (int i = 0; i < count; i++) {
			delete data[i];
		}
		delete[]data;
	}

	virtual void add(Symbol* newData);
	virtual void remove(Symbol* oldData);

	virtual void printList();
	virtual void useAll();

	int find(Symbol* other) const;
	int find(int id) const;

	bool contains(Symbol* other) const;
	Symbol* getSymbolIcon(char _icon) const;
};

extern List symbolTypes;
extern List symbolsList;
extern List itemTypes;
extern List itemsList;

#endif // !LIST_H
