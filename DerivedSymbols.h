#ifndef DERIVEDSYMBOLS_H
#define DERIVEDSYMBOLS_H

#include "Symbol.h"
#include "memtrace.h"

class Symbol_a : public Symbol {
public:
	Symbol_a() { icon = 'a'; baseMoney = 1; id = createId(); rarity = Common; }
	explicit Symbol_a(int _id) { icon = 'a', baseMoney = 1; id = _id; rarity = Common; }
	~Symbol_a() override = default;

	Symbol_a* clone() const override { return new Symbol_a(); }
	Symbol_a* copy() const override { return new Symbol_a(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_b : public Symbol {
public:
	Symbol_b() { icon = 'b'; baseMoney = 1; id = createId(); rarity = Uncommon; }
	explicit Symbol_b(int _id) { icon = 'b', baseMoney = 1; id = _id; rarity = Uncommon; }
	~Symbol_b() override = default;

	Symbol_b* clone() const override { return new Symbol_b(); }
	Symbol_b* copy() const override { return new Symbol_b(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_c : public Symbol {
public:
	Symbol_c() { icon = 'c'; baseMoney = 2; id = createId(); rarity = Common; }
	explicit Symbol_c(int _id) { icon = 'c', baseMoney = 2; id = _id; rarity = Common; }
	~Symbol_c() override = default;

	Symbol_c* clone() const override { return new Symbol_c(); }
	Symbol_c* copy() const override { return new Symbol_c(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_d : public Symbol {
public:
	Symbol_d() { icon = 'd'; baseMoney = 2; id = createId(); rarity = Uncommon; }
	explicit Symbol_d(int _id) { icon = 'd', baseMoney = 2; id = _id; rarity = Uncommon; }
	~Symbol_d() override = default;

	Symbol_d* clone() const override { return new Symbol_d(); }
	Symbol_d* copy() const override { return new Symbol_d(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_e : public Symbol {
public:
	Symbol_e() { icon = 'e'; baseMoney = 1; id = createId(); rarity = Common; }
	explicit Symbol_e(int _id) { icon = 'e', baseMoney = 1; id = _id; rarity = Common; }
	~Symbol_e() override = default;

	Symbol_e* clone() const override { return new Symbol_e(); }
	Symbol_e* copy() const override { return new Symbol_e(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_f : public Symbol {
public:
	Symbol_f() { icon = 'f'; baseMoney = 3; id = createId(); rarity = Rare; }
	explicit Symbol_f(int _id) { icon = 'f', baseMoney = 3; id = _id; rarity = Rare; }
	~Symbol_f() override = default;

	Symbol_f* clone() const override { return new Symbol_f(); }
	Symbol_f* copy() const override { return new Symbol_f(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_g : public Symbol {
public:
	Symbol_g() { icon = 'g'; baseMoney = 4; id = createId(); rarity = Rare; }
	explicit Symbol_g(int _id) { icon = 'g', baseMoney = 4; id = _id; rarity = Rare; }
	~Symbol_g() override = default;

	Symbol_g* clone() const override { return new Symbol_g(); }
	Symbol_g* copy() const override { return new Symbol_g(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_h : public Symbol {
public:
	Symbol_h() { icon = 'h'; baseMoney = 2; id = createId(); rarity = Uncommon; }
	explicit Symbol_h(int _id) { icon = 'h', baseMoney = 2; id = _id; rarity = Uncommon; }
	~Symbol_h() override = default;

	Symbol_h* clone() const override { return new Symbol_h(); }
	Symbol_h* copy() const override { return new Symbol_h(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_i : public Symbol {
public:
	Symbol_i() { icon = 'i'; baseMoney = 5; id = createId(); rarity = Rare; }
	explicit Symbol_i(int _id) { icon = 'i', baseMoney = 5; id = _id; rarity = Rare; }
	~Symbol_i() override = default;

	Symbol_i* clone() const override { return new Symbol_i(); }
	Symbol_i* copy() const override { return new Symbol_i(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};
class Symbol_j : public Symbol {
public:
	Symbol_j() { icon = 'j'; baseMoney = 3; id = createId(); rarity = Common; }
	explicit Symbol_j(int _id) { icon = 'j', baseMoney = 3; id = _id; rarity = Common; }
	~Symbol_j() override = default;

	Symbol_j* clone() const override { return new Symbol_j(); }
	Symbol_j* copy() const override { return new Symbol_j(this->id); }
	void useSymbol() override;
	void useSymbolWhenRemove() override;
	std::string getAbility() override;
};

#endif // !DERIVEDSYMBOLS_H
