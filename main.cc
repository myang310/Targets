// Ming Yang

#include "target.h"
#include "board.h"
#include <iostream>

// prototypes
void printRules();
void requestMove();
void getValidInput(int& location, Board* board);
void printErrorMessage();
void printCurrentPlayer(int number);

int main() {
	printRules();
	
	printCurrentPlayer(1);
	Board* playerOneBoard = new Board();
	std::cout << std::endl;

	printCurrentPlayer(2);
	Board* playerTwoBoard = new Board();
	bool playerOneTurn = true;
	std::cout << std::endl;

	while (!playerOneBoard->isDefeated() && !playerTwoBoard->isDefeated()) {
		int location;
		if (playerOneTurn) {
			printCurrentPlayer(1);
			requestMove();
			getValidInput(location, playerTwoBoard);
			playerTwoBoard->hitAt(location);
			playerTwoBoard->displayBoard();
		}
		else {
			printCurrentPlayer(2);
			requestMove();
			getValidInput(location, playerOneBoard);
			playerOneBoard->hitAt(location);
			playerOneBoard->displayBoard();
		}
		playerOneTurn = !playerOneTurn;
	}
	if (playerOneBoard->isDefeated()) {
		std::cout << "Congratulations player 2. You win!\n" << std::endl;
	}else {
		std::cout << "Congratulations player 1. You win!\n" << std::endl;
	}
}


void
printRules() {

}

void
requestMove() {
	std::cout << "Please enter the location you'd like to "
		<< "shoot (1 - 60): ";
}

void
getValidInput(int& location, Board* board) {
	while (!(std::cin >> location) || 
			location > 60 || 
			location < 1 ||
			board->isHitAlready(location-1)) {
		printErrorMessage();
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	location--;
}

void
printErrorMessage() {
	std::cout << "Not a valid location! Try again: ";
}

void
printCurrentPlayer(int number) {
	std::cout << "Player " << number << "'s turn" << std::endl;
}
