#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>
#include "memtrace.h"

enum Rarity {
	Special, VeryRare, Rare, Uncommon, Common
};

class Symbol {
protected:
	char icon;
	int baseMoney;
	int multiplier = 1;
	int bonus = 0;
	int id;
	Rarity rarity;

	int createId();
public:
	Symbol() :icon(' '), baseMoney(0), id(createId()), rarity(Special) {}
	Symbol(int _id) :icon(' '), baseMoney(0), id(_id), rarity(Special) {}
	virtual ~Symbol() {}

	virtual Symbol* clone() const { return new Symbol(); }
	virtual Symbol* copy() const { return new Symbol(this->id); }
	virtual void useSymbol();
	virtual void useSymbolWhenRemove();
	virtual std::string getAbility();

	void addToBaseMoney(int _baseMoney) { baseMoney += _baseMoney; }
	char getIcon() { return icon; }
	int getRarity() { return rarity; }
	int getBaseMoney() { return baseMoney; }
	long getMoney() { return (baseMoney + bonus) * multiplier; }
	int getId() { return id; }

	void addMultiplier(int amount) { multiplier *= amount; }
	void addBonus(int amount) { bonus += amount; }
};

#endif // !SYMBOL_H
