#ifndef ITEM_H
#define ITEM_H

#include "Symbol.h"
#include <string>
#include "memtrace.h"

class Item_a : public Symbol {
public:
	Item_a() { icon = 'a'; baseMoney = 0; id = createId(); rarity = Common; }
	Item_a(int _id) { icon = 'a', baseMoney = 0; id = _id; rarity = Common; }
	~Item_a() {}

	Item_a* clone() const { return new Item_a(); }
	Item_a* copy() const { return new Item_a(this->id); }
	void useSymbol();
	std::string getAbility();
};
class Item_b : public Symbol {
public:
	Item_b() { icon = 'b'; baseMoney = 0; id = createId(); rarity = Uncommon; }
	Item_b(int _id) { icon = 'b', baseMoney = 0; id = _id; rarity = Uncommon; }
	~Item_b() {}

	Item_b* clone() const { return new Item_b(); }
	Item_b* copy() const { return new Item_b(this->id); }
	void useSymbol();
	std::string getAbility();
};

class Item_c : public Symbol {
public:
	Item_c() { icon = 'c'; baseMoney = 0; id = createId(); rarity = Common; }
	Item_c(int _id) { icon = 'c', baseMoney = 0; id = _id; rarity = Common; }
	~Item_c() {}

	Item_c* clone() const { return new Item_c(); }
	Item_c* copy() const { return new Item_c(this->id); }
	void useSymbol();
	std::string getAbility();
};
class Item_d : public Symbol {
public:
	Item_d() { icon = 'd'; baseMoney = 0; id = createId(); rarity = Common; }
	Item_d(int _id) { icon = 'd', baseMoney = 0; id = _id; rarity = Common; }
	~Item_d() {}

	Item_d* clone() const { return new Item_d(); }
	Item_d* copy() const { return new Item_d(this->id); }
	void useSymbol();
	std::string getAbility();
};


#endif // !ITEM_H
