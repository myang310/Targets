// Ming Yang

#include "target.h"
#include "board.h"
#include <iostream>

// prototypes
void printRules();
bool askIfNewGame();
void printMoveInstructions();
int getValidLocation(Board* board);
void printErrorMessage();
void printPlayersTurn(int number);

int main() {
	bool keepPlaying = true;
	printRules();
	
	while (keepPlaying) {
	
		printPlayersTurn(1);
		Board* playerOneBoard = new Board();
		std::cout << std::endl;
	
		printPlayersTurn(2);
		Board* playerTwoBoard = new Board();
		bool playerOneTurn = true;
		std::cout << std::endl;

		while (!playerOneBoard->isDefeated() && !playerTwoBoard->isDefeated()) {
			int location;
			if (playerOneTurn) {
				printPlayersTurn(1);
				printMoveInstructions();

				location = Board::getLocationInput(*playerTwoBoard);
				playerTwoBoard->hitAt(location);
				playerTwoBoard->displayBoard();
			}else {
				printPlayersTurn(2);
				printMoveInstructions();

				location = Board::getLocationInput(*playerOneBoard);
				playerOneBoard->hitAt(location);
				playerOneBoard->displayBoard();
			}
			
			playerOneTurn = !playerOneTurn;
		}
		
		if (playerOneBoard->isDefeated() && playerTwoBoard->isDefeated())
			std::cout << "It's a tie! Good game to you both.\n" << std::endl;
		else if (playerOneBoard->isDefeated())
			std::cout << "Congratulations player 2. You win!\n" << std::endl;
		else
			std::cout << "Congratulations player 1. You win!\n" << std::endl;
		
		keepPlaying = askIfNewGame();	// asks user if they wish to play again
	}
}


void
printRules() {
	std::cout << "\nTargets is a game similar to the classic Battleship except on a\n"
		<< "one-dimensional board. In Targets, you will choose whether or not\n"
		<< "to assign your own targets/battleships or whether you want them\n"
		<< "randomly placed for you. Afterwards, you and your opponent alternate\n"
		<< "choosing spots on the board (1 to 60) to shoot. If you hit an\n"
		<< "opponent's target, the game will announce \"HIT\"; otherwise it will\n"
		<< "announce \"MISS\". Whoever destroys all of their opponent's targets\n"
		<< "first wins. Have fun!\n" << std::endl;
}

bool
askIfNewGame() {
	std::string playAgain;
	std::cout << "Would you like to play again? (yes or no): ";
	std::cin >> playAgain;
	while (playAgain != "yes" && playAgain != "no") {
		std::cout << "Invalid entry. Would you like to play again? (yes or no): ";
		std::cin >> playAgain;
	}
	if (playAgain == "yes") return true;
	else 			return false;
}

void
printMoveInstructions() {
}

void
printErrorMessage() {
	std::cout << "Not a valid location! Try again: ";
}

void
printPlayersTurn(int number) {
	std::cout << "Player " << number << "'s turn" << std::endl;
}
