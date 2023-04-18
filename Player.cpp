#include "Player.h"
//#include <windows.h>
#include <iostream>

int Player::getToken(const std::string& token) const {
	if (token == "reroll") {
		return rerollers;
	}
	else if (token == "remove") {
		return removers;
	}
	else {
		std::cout << "Invalid token type" << std::endl;
		return 0;
	}
}

void Player::gainToken(const std::string& token, int amount) {
	if (token == "reroll") {
		rerollers += amount;
		std::cout << amount << " reroll tokens gained" << std::endl;
	}
	else if (token == "remove") {
		removers += amount;
		std::cout << amount << " remove tokens gained" << std::endl;
	}
	else {
		std::cout << "Invalid token type" << std::endl;
	}
}

void Player::loseToken(const std::string& token, int amount) {
	if (token == "reroll") {
		rerollers -= amount;
		std::cout << amount << " reroll tokens used" << std::endl;
		//Sleep(500);
	}
	else if (token == "remove") {
		removers -= amount;
		std::cout << amount << " remove tokens used" << std::endl;
		//Sleep(500);
	}
	else {
		std::cout << "Invalid token type" << std::endl;
	}
}