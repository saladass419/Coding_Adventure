#ifndef ITEM_H
#define ITEM_H

#include "memtrace.h"
#include "Symbol.h"
#include <string>

class Item_TinyPlace : public Symbol {
public:
	Item_TinyPlace() { icon = "Tp"; baseMoney = 0; id = createId(); rarity = Special; }
	explicit Item_TinyPlace(int _id) { icon = "Tp", baseMoney = 0; id = _id; rarity = Special; }
	~Item_TinyPlace() override = default;

	Item_TinyPlace* clone() const override { return new Item_TinyPlace(); }
	Item_TinyPlace* copy() const override { return new Item_TinyPlace(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};
class Item_LeafClover : public Symbol {
public:
	Item_LeafClover() { icon = "Lc"; baseMoney = 0; id = createId(); rarity = Uncommon; }
	explicit Item_LeafClover(int _id) { icon = "Lc", baseMoney = 0; id = _id; rarity = Uncommon; }
	~Item_LeafClover() override = default;

	Item_LeafClover* clone() const override { return new Item_LeafClover(); }
	Item_LeafClover* copy() const override { return new Item_LeafClover(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};
class Item_Timer : public Symbol {
public:
	Item_Timer() { icon = "Ti"; baseMoney = 0; id = createId(); rarity = Common; value = 3; }
	explicit Item_Timer(int _id) { icon = "Ti", baseMoney = 0; id = _id; rarity = Common; value = 3; }
	~Item_Timer() override = default;

	Item_Timer* clone() const override { return new Item_Timer(); }
	Item_Timer* copy() const override { return new Item_Timer(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};
class Item_CoinCollector : public Symbol {
public:
	Item_CoinCollector() { icon = "Cc"; baseMoney = 0; id = createId(); rarity = Rare; }
	explicit Item_CoinCollector(int _id) { icon = "Cc", baseMoney = 0; id = _id; rarity = Rare; }
	~Item_CoinCollector() override = default;

	Item_CoinCollector* clone() const override { return new Item_CoinCollector(); }
	Item_CoinCollector* copy() const override { return new Item_CoinCollector(this->id); }
	void useSymbol() override;
	std::string getAbility() override;
};
class Item_MailMan : public Symbol {
public:
    Item_MailMan() { icon = "Mm"; baseMoney = 3; id = createId(); rarity = Uncommon; }
    explicit Item_MailMan(int _id) { icon = "Mm", baseMoney = 3; id = _id; rarity = Uncommon; }
    ~Item_MailMan() override = default;

    Item_MailMan* clone() const override { return new Item_MailMan(); }
    Item_MailMan* copy() const override { return new Item_MailMan(this->id); }
    void useSymbol() override {}
    std::string getAbility() override;
};
class Item_LovingMother : public Symbol {
public:
    Item_LovingMother() { icon = "Lm"; baseMoney = 0; id = createId(); rarity = Rare; }
    explicit Item_LovingMother(int _id) { icon = "Lm", baseMoney = 0; id = _id; rarity = Rare; }
    ~Item_LovingMother() override = default;

    Item_LovingMother* clone() const override { return new Item_LovingMother(); }
    Item_LovingMother* copy() const override { return new Item_LovingMother(this->id); }
    void useSymbol() override;
    std::string getAbility() override;
};

#endif // !ITEM_H
