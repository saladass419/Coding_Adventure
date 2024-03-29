#include "memtrace.h"
#include "Game.h"

#define TESTING 1 ///0 = not testing, 1 = testing

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
#if TESTING == 1
    manager.testingGame();
    return 0;
#endif

	manager.generateStartingSymbols();
	bool rentPayedSuccessfully;

	std::cout<<"Press any key to start"<<std::endl;
    int ch;
	for(int chances = 0; chances < 1; chances++){
		do {
			while ((ch = getchar()) != '\n' && (ch = getchar()) != EOF) {}
			manager.checkForRemove();

			manager.spinAnimation();
			manager.printInfo();
			GameManager::spin();
			Neutral::sleepfor(500);

			GameManager::gainItemMoney();
			GameManager::displayItemMoneyDistribution();

			GameManager::gainSymbolMoney();
			GameManager::displaySymbolMoneyDistribution();

			rentPayedSuccessfully = manager.payRent();

            std::cout<<"Press any key to continue..."<<std::endl;
            std::getchar();

            if (rentPayedSuccessfully) {
				if (manager.getSpinCounter() == 5) {
					manager.itemShopping();
				}
				manager.symbolShopping();
                Neutral::sleepfor(750);
			}
			//system("clear");
		} while (rentPayedSuccessfully&&manager.getRentCounter()!=0);
		if (!rentPayedSuccessfully) break;

		std::cout << "Congratulations! You finished the game!\nIf you want to continue in endless mode, type 'yes'" << std::endl;
		std::string input;
		std::cin >> input;
		if (input == "yes" || input == "Yes") { chances = -1; }
		else { break; }
	}
	return 0;
}

void GameManager::displayCurrentSymbols() {
	std::cout << "Your current symbols are ["<<symbolsList.count<<"]: ";
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
		if (symbolsList.data[j]->getIcon() == "  ") amount++;
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
		if (boardList.data[i]->getIcon() != "  ") {
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
	//system("clear");
	for (int i = 0; i < 5; i++) {
		printInfo();
		boardList.fillBoard(symbolsList);
		boardList.printList();
        Neutral::sleepfor(300);
		//system("clear");
	}
}

void GameManager::spin() {
	boardList.fillBoard(symbolsList);
	boardList.printList();
	itemsList.useAll();
	boardList.useAll();
}

void GameManager::symbolShopping() {
	//system("clear");
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
	//system("clear");
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
	//system("clear");
	printInfo();
	std::cout << "Press 'enter' to continue..." << std::endl << std::endl;
	if (player.getToken("remove") > 0) std::cout << "Press 'r' to remove a symbol" << std::endl << std::endl;

    if(getchar()=='r') {
        if (player.getToken("remove") > 0) {
            displayCurrentSymbols();
            std::cout << "Input the symbol you wish to remove: ";
            std::string input;
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

///Testing the foundational functions of the game
void GameManager::testingGame() {
    List testSymbols;
    TEST(List,){
        Symbol* testSymbol = new Symbol;
        testSymbols.add(testSymbol);
        EXPECT_TRUE(testSymbols.data[0]->getIcon()=="  ") << "Symbol wasn't added";
        EXPECT_EQ(1,testSymbols.count) << "Count is not correct";
        EXPECT_EQ(0,testSymbols.find(testSymbol)) << "ID of symbol isn't correct";
        EXPECT_TRUE(testSymbols.contains(testSymbol)) << "Contains function doesn't work";
        testSymbols.remove(testSymbol);
        EXPECT_EQ(0,testSymbols.count) << "Count is not correct";
    }ENDM;
    TEST(Board,){
        Board testBoard;
        testBoard.fillBoard(testSymbols);
        int tempCounter = 0;
        for(int i = 0; i < testBoard.count; i++){
            if(testBoard.data[i]->getIcon()!="  ") tempCounter++;
        }
        EXPECT_EQ(tempCounter,testSymbols.count) << "FillBoard() didn't work";
        testBoard.clearBoard();
        tempCounter = 0;
        for(int i = 0; i < testBoard.count; i++){
            if(testBoard.data[i]->getIcon()!="  ") tempCounter++;
        }
        EXPECT_EQ(0,tempCounter) << "ClearBoard() didn't work";
    }ENDM;
    TEST(Symbol,){
        Symbol* tempSymbol = new Symbol(6);
        EXPECT_EQ(6,tempSymbol->getId()) << "Wrong ID";
        Symbol* otherTempSymbol = tempSymbol->copy();
        EXPECT_EQ(tempSymbol->getId(),otherTempSymbol->getId()) << "IDs don't match";
        EXPECT_EQ(tempSymbol->getIcon(),otherTempSymbol->getIcon()) << "Icons don't match";
        delete otherTempSymbol;
        otherTempSymbol = tempSymbol->clone();
        EXPECT_NE(tempSymbol->getId(),otherTempSymbol->getId()) << "IDs match";
        delete tempSymbol;
        delete otherTempSymbol;
    }ENDM;
}