#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "memtrace.h"

class Player {
private:
	long money;
	int rerollers;
	int removers;
public:
	Player() :money(0), rerollers(1), removers(1) {}
	~Player() = default;

	long getMoney() const { return money; }
	int getToken(const std::string& token) const;

	void addToMoney(long _money) { money += _money; }
	void gainToken(const std::string& token, int amount = 1);

	void loseToken(const std::string& token, int amount = 1);
};

extern Player player;

#endif // !PLAYER_H
