#ifndef DERIVEDSYMBOLS_H
#define DERIVEDSYMBOLS_H

#include "Symbol.h"
#include "memtrace.h"

class Symbol_a : public Symbol {
public:
	Symbol_a() { icon = 'a'; baseMoney = 1; id = createId(); rarity = Common; }
	Symbol_a(int _id) { icon = 'a', baseMoney = 1; id = _id; rarity = Common; }
	~Symbol_a() {}

	Symbol_a* clone() const { return new Symbol_a(); }
	Symbol_a* copy() const { return new Symbol_a(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_b : public Symbol {
public:
	Symbol_b() { icon = 'b'; baseMoney = 1; id = createId(); rarity = Uncommon; }
	Symbol_b(int _id) { icon = 'b', baseMoney = 1; id = _id; rarity = Uncommon; }
	~Symbol_b() {}

	Symbol_b* clone() const { return new Symbol_b(); }
	Symbol_b* copy() const { return new Symbol_b(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_c : public Symbol {
public:
	Symbol_c() { icon = 'c'; baseMoney = 2; id = createId(); rarity = Common; }
	Symbol_c(int _id) { icon = 'c', baseMoney = 2; id = _id; rarity = Common; }
	~Symbol_c() {}

	Symbol_c* clone() const { return new Symbol_c(); }
	Symbol_c* copy() const { return new Symbol_c(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_d : public Symbol {
public:
	Symbol_d() { icon = 'd'; baseMoney = 2; id = createId(); rarity = Uncommon; }
	Symbol_d(int _id) { icon = 'd', baseMoney = 2; id = _id; rarity = Uncommon; }
	~Symbol_d() {}

	Symbol_d* clone() const { return new Symbol_d(); }
	Symbol_d* copy() const { return new Symbol_d(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_e : public Symbol {
public:
	Symbol_e() { icon = 'e'; baseMoney = 1; id = createId(); rarity = Common; }
	Symbol_e(int _id) { icon = 'e', baseMoney = 1; id = _id; rarity = Common; }
	~Symbol_e() {}

	Symbol_e* clone() const { return new Symbol_e(); }
	Symbol_e* copy() const { return new Symbol_e(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_f : public Symbol {
public:
	Symbol_f() { icon = 'f'; baseMoney = 3; id = createId(); rarity = Rare; }
	Symbol_f(int _id) { icon = 'f', baseMoney = 3; id = _id; rarity = Rare; }
	~Symbol_f() {}

	Symbol_f* clone() const { return new Symbol_f(); }
	Symbol_f* copy() const { return new Symbol_f(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_g : public Symbol {
public:
	Symbol_g() { icon = 'g'; baseMoney = 4; id = createId(); rarity = Rare; }
	Symbol_g(int _id) { icon = 'g', baseMoney = 4; id = _id; rarity = Rare; }
	~Symbol_g() {}

	Symbol_g* clone() const { return new Symbol_g(); }
	Symbol_g* copy() const { return new Symbol_g(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_h : public Symbol {
public:
	Symbol_h() { icon = 'h'; baseMoney = 2; id = createId(); rarity = Uncommon; }
	Symbol_h(int _id) { icon = 'h', baseMoney = 2; id = _id; rarity = Uncommon; }
	~Symbol_h() {}

	Symbol_h* clone() const { return new Symbol_h(); }
	Symbol_h* copy() const { return new Symbol_h(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_i : public Symbol {
public:
	Symbol_i() { icon = 'i'; baseMoney = 5; id = createId(); rarity = Rare; }
	Symbol_i(int _id) { icon = 'i', baseMoney = 5; id = _id; rarity = Rare; }
	~Symbol_i() {}

	Symbol_i* clone() const { return new Symbol_i(); }
	Symbol_i* copy() const { return new Symbol_i(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};
class Symbol_j : public Symbol {
public:
	Symbol_j() { icon = 'j'; baseMoney = 3; id = createId(); rarity = Common; }
	Symbol_j(int _id) { icon = 'j', baseMoney = 3; id = _id; rarity = Common; }
	~Symbol_j() {}

	Symbol_j* clone() const { return new Symbol_j(); }
	Symbol_j* copy() const { return new Symbol_j(this->id); }
	void useSymbol();
	void useSymbolWhenRemove();
	std::string getAbility();
};

#endif // !DERIVEDSYMBOLS_H
