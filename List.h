#ifndef LIST_H
#define LIST_H

#include "memtrace.h"
#include "Symbol.h"
#include "Item.h"
#include "DerivedSymbols.h"

class List {
public:
	Symbol** data; ///< An array of pointers that point to Symbols (Symbol**)
	int count; ///< The length of the symbol array (int)

    ///Default Constructor:
    ///data = NULL, count = 0
	List() : data(NULL), count(0) {}
    ///Constructor that initializes both variables with new ones
    ///@param _data - an array of Symbol pointers
    ///@param _count - the length of the array
	List(Symbol** _data, int _count) : data(new Symbol* [_count]), count(_count) {
		for (int i = 0; i < count; i++) {
			data[i] = _data[i]->copy();
		}
	}
    ///Destructor that deletes the array and all of it's elements
	~List() {
		for (int i = 0; i < count; i++) {
            delete data[i];
		}
        delete[]data;
	}

    ///Adds a Symbol to the list
    ///@param newData - pointer to the new Symbol (Symbol*)
	virtual void add(Symbol* newData);
    ///Removes a Symbol from the list
    ///@param oldData - pointer to the old Symbol (Symbol*)
	virtual void remove(Symbol* oldData);

    ///Prints out the content of the list
	virtual void printList();
    ///Calls the useSymbol function for each element in the list
	virtual void useAll();

    ///Finds a symbol in the list
    ///@param other - pointer to the symbol that needs to be found (Symbol*)
    ///@return index of the found symbol (int)
	int find(Symbol* other) const;
    ///Finds a symbol in the list
    ///@param id - the ID of the symbol that needs to be found (int)
    ///@return pointer to the found symbol (Symbol*)
	Symbol* find(int id) const;
    ///Check whether a symbol is in the list or not
    ///@param other - pointer to the symbol (Symbol*)
    ///@return true if it is, false if it isn't (bool)
	bool contains(Symbol* other) const;
    ///Returns a symbol by an icon
    ///@param _icon - icon of the desired symbol (char)
    ///@return pointer to the found symbol (Symbol*)
	Symbol* getSymbolIcon(const std::string& _icon) const;
};

extern List symbolTypes;
extern List symbolsList;
extern List itemTypes;
extern List itemsList;

#endif // !LIST_H
