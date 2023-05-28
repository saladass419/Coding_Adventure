#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

///Rarity of a symbol/item
enum Rarity {
    Common,Uncommon, Rare, VeryRare, Special
};

class Symbol {
protected:
	std::string icon; ///< Icon of a symbol that show up on the screen (char)
	int baseMoney; ///< Amount of money this symbol makes each spin by default (int)
	int multiplier = 1; ///< The amount that the baseMoney is multiplied this spin (int) (default = 1)
	int bonus = 0; ///< The amount that is added to the baseMoney this spin (int) (default = 0)
	int id; ///< Unique ID of this symbol (int)
	Rarity rarity; ///< Rarity of the symbol (Rarity)

    ///Creates a unique ID for the symbol
    ///@return the created ID (int)
	int createId() const;
public:
    ///Default Constructor:
    ///icon = icon of this symbol, baseMoney = baseMoney of this symbol, id = new ID, rarity = rarity of this symbol
	Symbol() :icon("  "), baseMoney(0), id(createId()), rarity(Special) {}
    ///Constructor with an id:
    ///id = _id
    ///@param _id - ID of the symbol (int)
	explicit Symbol(int _id) :icon("  "), baseMoney(0), id(_id), rarity(Special) {}
	virtual ~Symbol() = default;

    ///Creates a symbol with a new ID
    ///@return pointer to the new symbol (Symbol*)
	virtual Symbol* clone() const { return new Symbol(); }
    ///Creates a symbol with the same ID
    ///@return pointer to the new symbol (Symbol*)
	virtual Symbol* copy() const { return new Symbol(this->id); }
    ///Uses the ability of this symbol
	virtual void useSymbol() {}
    ///Uses the ability of this symbol when removed
	virtual void useSymbolWhenRemove() {}
    ///Returns what this symbol can do
    ///@return the descriptions of this symbol's abilities (std::string)
	virtual std::string getAbility();

	std::string getIcon() const { return icon; }
	int getRarity() { return rarity; }
	int getBaseMoney() const { return baseMoney; }
    ///Return the amount of money made this spin by this symbol
    ///@return (baseMoney + bonus) * multiplier (long)
	long getMoney() const { return 0 >= ((baseMoney + bonus) * multiplier) ? 0 : (baseMoney + bonus) * multiplier; }
	int getId() const { return id; }

	void addMultiplier(int amount) { multiplier *= amount; }
	void addBonus(int amount) { bonus += amount; }
    ///Resets the symbol's bonus and multiplier values
	void resetSymbol() { bonus = 0; multiplier = 1; }
};

#endif // !SYMBOL_H
