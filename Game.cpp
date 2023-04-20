#include "Game.h"

Player player;

List symbolTypes;
List symbolsList;

List itemTypes;
List itemsList;

SymbolShop symbolShopList;
ItemShop itemShopList;

Board boardList;

int main() {
	GameManager manager;
	manager.generateStartingSymbols();
	bool rentPayedSuccessfully;

	std::cout<<"Press any key to start"<<std::endl;
	for(int chances = 0; chances < 1; chances++){
		do {
			while ((getchar()) != '\n' && getchar() != EOF) {}
			manager.checkForRemove();

			manager.spinAnimation();
			manager.printInfo();
			manager.spin();
			Neutral::sleepfor(500);

			manager.gainItemMoney();
			manager.displayItemMoneyDistribution();

			manager.gainSymbolMoney();
			manager.displaySymbolMoneyDistribution();

			rentPayedSuccessfully = manager.payRent();

            std::getchar();

            if (rentPayedSuccessfully) {
				if (manager.getSpinCounter() == 5) {
					manager.itemShopping();
				}
				manager.symbolShopping();
                Neutral::sleepfor(750);
			}
			system("clear");
		} while (rentPayedSuccessfully&&manager.getRentCounter()!=0);
		if (!rentPayedSuccessfully) break;

		std::cout << "Congratulations! You finished the game!\nIf you want to continue in endless mode, type 'yes'" << std::endl;
		std::string input;
		std::cin >> input;
		if (input == "yes" || input == "Yes") { chances = 0; }
		else { chances = 1; }
	}
	return 0;
}

void GameManager::displayCurrentSymbols() {
	std::cout << "Your current symbols are: "; 
	for (int i = 0; i < symbolTypes.count; i++) {
		int amount = 0; 
		for (int j = 0; j < symbolsList.count; j++) { 
			if (symbolsList.data[j]->getIcon() == symbolTypes.data[i]->getIcon()) amount++; 
		}
		if (amount > 0) {
			std::cout << symbolTypes.data[i]->getIcon() << "(" << amount << ") ";
		}
	}
	int amount = 0;
	for (int j = 0; j < symbolsList.count; j++) {
		if (symbolsList.data[j]->getIcon() == ' ') amount++;
	}
	if (amount > 0) {
		std::cout << "empty(" << amount << ") ";
	}
	std::cout << std::endl<<std::endl;
}

void GameManager::displayCurrentItems() {
	std::cout << "Your current items are: ";
	for (int i = 0; i < itemsList.count; i++) {
		std::cout << itemsList.data[i]->getIcon() << " ";
	}
	std::cout << std::endl;
}

void GameManager::displaySymbolMoneyDistribution() {
	std::cout << std::endl;
	for (int x = 0; x < 5; x++) {
		std::cout << "| ";
		for (int y = 0; y < 5; y++) {
			std::cout << boardList.data[x * 5 + y]->getMoney() << "\t| ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void GameManager::displayItemMoneyDistribution() {
	if (countItemMoney() > 0) {
		std::cout << std::endl;
		for (int i = 0; i < itemsList.count; i++) {
			if(itemsList.data[i]->getMoney()>0) {
				std::cout << itemsList.data[i]->getIcon() << ": " << itemsList.data[i]->getMoney() << "$ | ";
			}
			itemsList.data[i]->resetSymbol();
		}
		std::cout << std::endl<<std::endl;
	}
}

long GameManager::countSymbolMoney() {
	long result = 0;
	for (int i = 0; i < boardList.count; i++) {
		if (boardList.data[i]->getIcon() != ' ') {
			result += boardList.data[i]->getMoney();
		}
	}
	return result;
}

long GameManager::countItemMoney() {
	long result = 0;
	for (int i = 0; i < itemsList.count; i++) {
		result += itemsList.data[i]->getMoney();
	}
	return result;
}

void GameManager::spinAnimation() const {
	system("clear");
	for (int i = 0; i < 5; i++) {
		printInfo();
		boardList.fillBoard();
		boardList.printList();
        Neutral::sleepfor(300);
		system("clear");
	}
}

void GameManager::spin() {
	boardList.fillBoard();
	boardList.printList();
	itemsList.useAll();
	boardList.useAll();
}

void GameManager::symbolShopping() {
	system("clear");
	printInfo();
	std::cout << "|SYMBOL SHOPPING|" << std::endl;
	displayCurrentSymbols();
	symbolShopList.fillShop(rentCounter);
	symbolShopList.printList();
	std::cout << "Select a symbol to add (0: none, r: reroll) | Reroll tokens: "<<player.getToken("reroll") << std::endl;
	char input;
	do {
		std::cin >> input;
		if (input == 'r') {
			if (player.getToken("reroll") > 0) {
				player.loseToken("reroll");
				symbolShopping();
				return;
			}
			else {
				std::cout << "You don't have enough reroll tokens!" << std::endl;
			}
		}
		if (input - '0' < 0 || input - '0' > symbolShopList.count) {
			std::cout << "Invalid number" << std::endl;
		}
	} while ((input - '0' < 0 || input - '0' > symbolShopList.count) || input == 'r');
	if (input - '0' == 0) return;
	symbolShopList.purchase(input - '0' - 1);
	std::cout << std::endl << "'" << symbolShopList.data[input - '0' - 1]->getIcon() << "' added to your symbols" << std::endl;
}

void GameManager::itemShopping() {
	system("clear");
	printInfo();
	std::cout << "|ITEM SHOPPING|" << std::endl;
	displayCurrentItems();
	itemShopList.fillShop(rentCounter);
	itemShopList.printList();
	std::cout << "Select an item to add (r: reroll) | Reroll tokens: " << player.getToken("reroll") << std::endl;
	char input;
	do {
		std::cin >> input;
		if (input == 'r') {
			if (player.getToken("reroll") > 0) {
				player.loseToken("reroll");
				itemShopping();
				return;
			}
			else {
				std::cout << "You don't have enoguh reroll tokens!" << std::endl;
			}
		}
		if (input - '0' < 1 || input - '0' > itemShopList.count) {
			std::cout << "Invalid number" << std::endl;
		}
	} while ((input - '0' < 1 || input - '0' > itemShopList.count) || input == 'r');
	itemShopList.purchase(input - '0' - 1);
	std::cout << std::endl << "'" << itemShopList.data[input - '0' - 1]->getIcon() << "' added to your symbols" << std::endl;
}

void GameManager::growRent() {
	rent += 25 * (int)pow(3, 10 - rentCounter);
	rentCounter--;
}

bool GameManager::payRent() {
	if (spinCounter > 0) { spinCounter--; return true; }

	player.addToMoney(-rent);
	if (player.getMoney() < 0) {
		std::cout << "You've failed to pay the rent, your landlord has kicked you out!" << std::endl;
		return false;
	}
	if (player.getMoney() == 0) player.addToMoney(1);
	growRent();
	spinCounter = 5;
	player.gainToken("reroll");
	player.gainToken("remove");
	std::cout << "Rent payed, next month's rent is "<<rent<<"$" << std::endl;
	return true;
}

void GameManager::checkForRemove() {
	system("clear");
	printInfo();
	std::cout << "Press 'enter' to continue..." << std::endl << std::endl;
	if (player.getToken("remove") > 0) std::cout << "Press 'r' to remove a symbol" << std::endl << std::endl;

    if(getchar()=='r') {
        if (player.getToken("remove") > 0) {
            displayCurrentSymbols();
            std::cout << "Input the symbol you wish to remove: ";
            char input;
            std::cin >> input;
            for (int i = 0; i < symbolsList.count; i++) {
                if (symbolsList.data[i]->getIcon() == input) {
                    player.loseToken("remove");
                    symbolsList.remove(symbolsList.data[i]);
                    std::cout << std::endl << "'" << input << "' has been removed" << std::endl;
                    Neutral::sleepfor(750);
                    break;
                }
            }
            while ((getchar()) != '\n' && getchar() != EOF) {}
            checkForRemove();
        }
    }
}

void GameManager::printInfo() const {
	std::cout << "Money in vault: " << player.getMoney() << "$ | Rent due in " << spinCounter << " spins ( " << rent << "$ ) | Payments left: " <<rentCounter<<" | Remover tokens : " << player.getToken("remove") << std::endl << std::endl;
}
