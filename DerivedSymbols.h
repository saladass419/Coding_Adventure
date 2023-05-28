#ifndef DERIVEDSYMBOLS_H
#define DERIVEDSYMBOLS_H

#include "Symbol.h"

class Symbol_Flower : public Symbol {
public:
	Symbol_Flower() { icon = "Fl"; baseMoney = 1; id = createId(); rarity = Common; }
	explicit Symbol_Flower(int _id) { icon = "Fl", baseMoney = 1; id = _id; rarity = Common; }
	~Symbol_Flower() override = default;

	Symbol_Flower* clone() const override { return new Symbol_Flower(); }
	Symbol_Flower* copy() const override { return new Symbol_Flower(this->id); }
	void useSymbol() override {}
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};
class Symbol_Wine : public Symbol {
public:
	Symbol_Wine() { icon = "Wi"; baseMoney = 1; id = createId(); rarity = Common; }
	explicit Symbol_Wine(int _id) { icon = "Wi", baseMoney = 1; id = _id; rarity = Common; }
	~Symbol_Wine() override = default;

	Symbol_Wine* clone() const override { return new Symbol_Wine(); }
	Symbol_Wine* copy() const override { return new Symbol_Wine(this->id); }
	void useSymbol() override {}
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};
class Symbol_Dog : public Symbol {
public:
	Symbol_Dog() { icon = "Do"; baseMoney = 1; id = createId(); rarity = Common; }
	explicit Symbol_Dog(int _id) { icon = "Do", baseMoney = 1; id = _id; rarity = Common; }
	~Symbol_Dog() override = default;

	Symbol_Dog* clone() const override { return new Symbol_Dog(); }
	Symbol_Dog* copy() const override { return new Symbol_Dog(this->id); }
	void useSymbol() override {}
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};

class Symbol_Bee : public Symbol {
public:
	Symbol_Bee() { icon = "Be"; baseMoney = 2; id = createId(); rarity = Uncommon; }
	explicit Symbol_Bee(int _id) { icon = "Be", baseMoney = 2; id = _id; rarity = Uncommon; }
	~Symbol_Bee() override = default;

	Symbol_Bee* clone() const override { return new Symbol_Bee(); }
	Symbol_Bee* copy() const override { return new Symbol_Bee(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};
class Symbol_Sun : public Symbol {
public:
	Symbol_Sun() { icon = "Su"; baseMoney = 3; id = createId(); rarity = VeryRare; }
	explicit Symbol_Sun(int _id) { icon = "Su", baseMoney = 3; id = _id; rarity = VeryRare; }
	~Symbol_Sun() override = default;

	Symbol_Sun* clone() const override { return new Symbol_Sun(); }
	Symbol_Sun* copy() const override { return new Symbol_Sun(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};
class Symbol_BeeHive : public Symbol {
public:
	Symbol_BeeHive() { icon = "Bh"; baseMoney = 3; id = createId(); rarity = Rare; }
	explicit Symbol_BeeHive(int _id) { icon = "Bh", baseMoney = 3; id = _id; rarity = Rare; }
	~Symbol_BeeHive() override = default;

	Symbol_BeeHive* clone() const override { return new Symbol_BeeHive(); }
	Symbol_BeeHive* copy() const override { return new Symbol_BeeHive(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};
class Symbol_Rain : public Symbol {
    int lifeSpan = 3;
public:
	Symbol_Rain() { icon = "Ra"; baseMoney = 3; id = createId(); rarity = Rare; }
	explicit Symbol_Rain(int _id) { icon = "Ra", baseMoney = 3; id = _id; rarity = Rare; }
	~Symbol_Rain() override = default;

	Symbol_Rain* clone() const override { return new Symbol_Rain(); }
	Symbol_Rain* copy() const override { return new Symbol_Rain(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};

class Symbol_Drunk : public Symbol {
public:
	Symbol_Drunk() { icon = "Dr"; baseMoney = 2; id = createId(); rarity = Uncommon; }
	explicit Symbol_Drunk(int _id) { icon = "Dr", baseMoney = 2; id = _id; rarity = Uncommon; }
	~Symbol_Drunk() override = default;

	Symbol_Drunk* clone() const override { return new Symbol_Drunk(); }
	Symbol_Drunk* copy() const override { return new Symbol_Drunk(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};
class Symbol_Bartender : public Symbol {
public:
	Symbol_Bartender() { icon = "Bt"; baseMoney = 3; id = createId(); rarity = Rare; }
	explicit Symbol_Bartender(int _id) { icon = "Bt", baseMoney = 3; id = _id; rarity = Rare; }
	~Symbol_Bartender() override = default;

	Symbol_Bartender* clone() const override { return new Symbol_Bartender(); }
	Symbol_Bartender* copy() const override { return new Symbol_Bartender(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_Grape : public Symbol {
public:
	Symbol_Grape() { icon = "Gr"; baseMoney = 2; id = createId(); rarity = Uncommon; }
	explicit Symbol_Grape(int _id) { icon = "Gr", baseMoney = 2; id = _id; rarity = Uncommon; }
	~Symbol_Grape() override = default;

	Symbol_Grape* clone() const override { return new Symbol_Grape(); }
	Symbol_Grape* copy() const override { return new Symbol_Grape(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override {}
	std::string getAbility() override;
};
class Symbol_FineWine : public Symbol {
public:
    Symbol_FineWine() { icon = "Fw"; baseMoney = 6; id = createId(); rarity = VeryRare; }
    explicit Symbol_FineWine(int _id) { icon = "Fw", baseMoney = 6; id = _id; rarity = VeryRare; }
    ~Symbol_FineWine() override = default;

    Symbol_FineWine* clone() const override { return new Symbol_FineWine(); }
    Symbol_FineWine* copy() const override { return new Symbol_FineWine(this->id); }
    void useSymbol() override;
    void useSymbolWhenRemove() override {}
    std::string getAbility() override;
};
class Symbol_Sommelier : public Symbol {
public:
    Symbol_Sommelier() { icon = "So"; baseMoney = 4; id = createId(); rarity = Rare; }
    explicit Symbol_Sommelier(int _id) { icon = "So", baseMoney = 4; id = _id; rarity = Rare; }
    ~Symbol_Sommelier() override = default;

    Symbol_Sommelier* clone() const override { return new Symbol_Sommelier(); }
    Symbol_Sommelier* copy() const override { return new Symbol_Sommelier(this->id); }
    void useSymbol() override;
    void useSymbolWhenRemove() override;
    std::string getAbility() override;
};

class Symbol_Child : public Symbol {
public:
    Symbol_Child() { icon = "Ch"; baseMoney = 2; id = createId(); rarity = Uncommon; }
    explicit Symbol_Child(int _id) { icon = "Ch", baseMoney = 2; id = _id; rarity = Uncommon; }
    ~Symbol_Child() override = default;

    Symbol_Child* clone() const override { return new Symbol_Child(); }
    Symbol_Child* copy() const override { return new Symbol_Child(this->id); }
    void useSymbol() override;
    void useSymbolWhenRemove() override {}
    std::string getAbility() override;
};
class Symbol_Vet : public Symbol {
public:
    Symbol_Vet() { icon = "Ve"; baseMoney = 4; id = createId(); rarity = Rare; }
    explicit Symbol_Vet(int _id) { icon = "Ve", baseMoney = 4; id = _id; rarity = Rare; }
    ~Symbol_Vet() override = default;

    Symbol_Vet* clone() const override { return new Symbol_Vet(); }
    Symbol_Vet* copy() const override { return new Symbol_Vet(this->id); }
    void useSymbol() override;
    void useSymbolWhenRemove() override {}
    std::string getAbility() override;
};
class Symbol_Owner : public Symbol {
public:
    Symbol_Owner() { icon = "Ow"; baseMoney = 2; id = createId(); rarity = Uncommon; }
    explicit Symbol_Owner(int _id) { icon = "Ow", baseMoney = 2; id = _id; rarity = Uncommon; }
    ~Symbol_Owner() override = default;

    Symbol_Owner* clone() const override { return new Symbol_Owner(); }
    Symbol_Owner* copy() const override { return new Symbol_Owner(this->id); }
    void useSymbol() override;
    void useSymbolWhenRemove() override {}
    std::string getAbility() override;
};
class Symbol_Stranger : public Symbol {
public:
    Symbol_Stranger() { icon = "St"; baseMoney = 4; id = createId(); rarity = VeryRare; }
    explicit Symbol_Stranger(int _id) { icon = "St", baseMoney = 4; id = _id; rarity = VeryRare; }
    ~Symbol_Stranger() override = default;

    Symbol_Stranger* clone() const override { return new Symbol_Stranger(); }
    Symbol_Stranger* copy() const override { return new Symbol_Stranger(this->id); }
    void useSymbol() override;
    void useSymbolWhenRemove() override {}
    std::string getAbility() override;
};

class Symbol_Insect : public Symbol {
public:
    Symbol_Insect() { icon = "In"; baseMoney = 8; id = createId(); rarity = Uncommon; }
    explicit Symbol_Insect(int _id) { icon = "In", baseMoney = 8; id = _id; rarity = Uncommon; }
    ~Symbol_Insect() override = default;

    Symbol_Insect* clone() const override { return new Symbol_Insect(); }
    Symbol_Insect* copy() const override { return new Symbol_Insect(this->id); }
    void useSymbol() override;
    void useSymbolWhenRemove() override {}
    std::string getAbility() override;
};
class Symbol_c : public Symbol {
public:
    Symbol_c() { icon = 'p'; baseMoney = 6; id = createId(); rarity = VeryRare; }
    explicit Symbol_c(int _id) { icon = 'p', baseMoney = 6; id = _id; rarity = VeryRare; }
    ~Symbol_c() override = default;

    Symbol_c* clone() const override { return new Symbol_c(); }
    Symbol_c* copy() const override { return new Symbol_c(this->id); }
    void useSymbol() override {}
    void useSymbolWhenRemove() override {}
    //std::string getAbility() override;
};
class Symbol_d : public Symbol {
public:
    Symbol_d() { icon = 'p'; baseMoney = 6; id = createId(); rarity = VeryRare; }
    explicit Symbol_d(int _id) { icon = 'p', baseMoney = 6; id = _id; rarity = VeryRare; }
    ~Symbol_d() override = default;

    Symbol_d* clone() const override { return new Symbol_d(); }
    Symbol_d* copy() const override { return new Symbol_d(this->id); }
    void useSymbol() override {}
    void useSymbolWhenRemove() override {}
    //std::string getAbility() override;
};
class Symbol_e : public Symbol {
public:
    Symbol_e() { icon = 'p'; baseMoney = 6; id = createId(); rarity = VeryRare; }
    explicit Symbol_e(int _id) { icon = 'p', baseMoney = 6; id = _id; rarity = VeryRare; }
    ~Symbol_e() override = default;

    Symbol_e* clone() const override { return new Symbol_e(); }
    Symbol_e* copy() const override { return new Symbol_e(this->id); }
    void useSymbol() override {}
    void useSymbolWhenRemove() override {}
    //std::string getAbility() override;
};

#endif // !DERIVEDSYMBOLS_H
