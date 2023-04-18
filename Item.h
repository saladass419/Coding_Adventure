#ifndef ITEM_H
#define ITEM_H

#include "Symbol.h"
#include <string>

class Item_a : public Symbol {
public:
	Item_a() { icon = 'a'; baseMoney = 0; id = createId(); rarity = Common; }
	explicit Item_a(int _id) { icon = 'a', baseMoney = 0; id = _id; rarity = Common; }
	~Item_a() override = default;

	Item_a* clone() const override { return new Item_a(); }
	Item_a* copy() const override { return new Item_a(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};
class Item_b : public Symbol {
public:
	Item_b() { icon = 'b'; baseMoney = 0; id = createId(); rarity = Uncommon; }
	explicit Item_b(int _id) { icon = 'b', baseMoney = 0; id = _id; rarity = Uncommon; }
	~Item_b() override = default;

	Item_b* clone() const override { return new Item_b(); }
	Item_b* copy() const override { return new Item_b(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};

class Item_c : public Symbol {
    int spins = 3;
public:
	Item_c() { icon = 'c'; baseMoney = 0; id = createId(); rarity = Common; }
	explicit Item_c(int _id) { icon = 'c', baseMoney = 0; id = _id; rarity = Common; }
	~Item_c() override = default;

	Item_c* clone() const override { return new Item_c(); }
	Item_c* copy() const override { return new Item_c(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};
class Item_d : public Symbol {
public:
	Item_d() { icon = 'd'; baseMoney = 0; id = createId(); rarity = Common; }
	explicit Item_d(int _id) { icon = 'd', baseMoney = 0; id = _id; rarity = Common; }
	~Item_d() override = default;

	Item_d* clone() const override { return new Item_d(); }
	Item_d* copy() const override { return new Item_d(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};
class Item_e : public Symbol {
public:
    Item_e() { icon = 'e'; baseMoney = 0; id = createId(); rarity = Special; }
    explicit Item_e(int _id) { icon = 'e', baseMoney = 0; id = _id; rarity = Special; }
    ~Item_e() override = default;

    Item_e* clone() const override { return new Item_e(); }
    Item_e* copy() const override { return new Item_e(this->id); }
    void useSymbol() override;
    std::string getAbility() override;
};

#endif // !ITEM_H
