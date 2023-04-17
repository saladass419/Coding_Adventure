#include "Player.h"
#include <windows.h>
#include <iostream>
#include "memtrace.h"

int Player::getToken(std::string token) {
	if (token.compare("reroll") == 0) {
		return rerollers;
	}
	else if (token.compare("remove") == 0) {
		return removers;
	}
	else {
		std::cout << "Invalid token type" << std::endl;
		return 0;
	}
}

void Player::gainToken(std::string token, int amount) {
	if (token.compare("reroll") == 0) {
		rerollers += amount;
		std::cout << amount << " reroll tokens gained" << std::endl;
	}
	else if (token.compare("remove") == 0) {
		removers += amount;
		std::cout << amount << " remove tokens gained" << std::endl;
	}
	else {
		std::cout << "Invalid token type" << std::endl;
	}
}

void Player::loseToken(std::string token, int amount) {
	if (token.compare("reroll") == 0) {
		rerollers -= amount;
		std::cout << amount << " reroll tokens used" << std::endl;
		Sleep(500);
	}
	else if (token.compare("remove") == 0) {
		removers -= amount;
		std::cout << amount << " remove tokens used" << std::endl;
		Sleep(500);
	}
	else {
		std::cout << "Invalid token type" << std::endl;
	}
}