#ifndef PLAYER_H
#define PLAYER_H

#include "memtrace.h"
#include <string>

class Player {
private:
	long money; ///< Amount of money the player has (long)
	int rerollers; ///< Amount of re-roll tokens the player has (int)
	int removers; ///< Amount of remove tokens the player has (int)
public:
    ///Default Constructor:
    ///money = 0, rerolles = 1, removers = 1
	Player() :money(0), rerollers(1), removers(1) {}
	~Player() = default;

    ///Returns the amount of money the player has
    ///@return amount of money (long)
	long getMoney() const { return money; }
    ///Returns the amount of tokens the player has based on the name of the token
    ///@param token - name of the desired token (const std::string)
    ///@return amount of token (int)
	int getToken(const std::string& token) const;

    ///Adds money to the player's stash
    ///@param _money - amount of money (long)
	void addToMoney(long _money) { money += _money; }
    ///Adds tokens to the player's stash
    ///@param token - name of the desired token (const std::string)
    ///@param amount - amount of token to be added (int) (default = 1)
	void gainToken(const std::string& token, int amount = 1);
    ///Removes tokens from the player's stash
    ///@param token - name of the desired token (const std::string)
    ///@param amount - amount of token to be removed (int) (default = 1)
	void loseToken(const std::string& token, int amount = 1);
};

extern Player player;

#endif // !PLAYER_H
