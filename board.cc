// Ming Yang

#include "board.h"
#include <iostream>

Board::Board() {
	spotsHit = new bool[SIZE];
	board = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		spotsHit[i] = false;
		board[i] = -1;
	}

	targets = new Target[TARGET_COUNT];
	setupTargets();
}

Board::~Board() {
	delete [] spotsHit;
	delete [] board;
	delete [] targets;
}

Board::Board(Board& original) {
	spotsHit = new bool[SIZE];
	board = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		spotsHit[i] = original.spotsHit[i];
		board[i] = original.board[i];
	}

	targets = new Target[TARGET_COUNT];
	for (int i = 0; i < TARGET_COUNT; i++) {
		int size = original.targets[i].getSize();
		int location = original.targets[i].getLocation();
		targets[i].setup(size, location); 
	}
}

Board
Board::operator=(const Board& right) {
	delete [] spotsHit;
	delete [] board;
	delete [] targets;

	spotsHit = new bool[SIZE];
	board = new int[SIZE];
	for (int i = 0; i < SIZE; i++) {
		spotsHit[i] = right.spotsHit[i];
		board[i] = right.board[i];
	}

	targets = new Target[TARGET_COUNT];
	for (int i = 0; i < TARGET_COUNT; i++) {
		int size = right.targets[i].getSize();
		int location = right.targets[i].getLocation();	
		targets[i].setup(size, location);
	}
	return *this;
}

void
Board::hitAt(int location) {
	int targetIndex = getTargetIndex(location);
	if (targetIndex != -1) 
	{	// if a target occupies that location
		targets[targetIndex].gotHit();
		std::cout << "Result: HIT" << std::endl;
		if (targets[targetIndex].isDead())
			std::cout << "You sunk my galleon!" << std::endl;
	}
	else {
		std::cout << "Result: MISS" << std::endl;
	}

	spotsHit[location] = true;
}

void
Board::displayBoard() {
	for (int location = 0; location < SIZE; location++) {
		if (isHitAlready(location)) {
		  if (getTargetIndex(location) != -1)	
			  std::cout << "x";
		  else
			  std::cout << "o";
		} else {
			std::cout << "-";
		}
	}
	std::cout << "\n\n" << std::endl;
}

bool
Board::isDefeated() {
	for (int i = 0; i < TARGET_COUNT; i++) 
		if (!(targets[i].isDead())) 
			return false;
	return true;
}

bool
Board::isHitAlready(int location) {
	return spotsHit[location];
}

void
Board::setupTargets() {
	int size = 2;
	for (int index = 0; index < TARGET_COUNT; index++) {	
		int location = getLocationInput(size);	
		
		targets[index].setup(size, location);
		for (int j = location; j < location + size; j++) 
		{	// board tracks which target object occupies any
			//	specific spot of the board
			board[j] = index;
		}

		size++;	// increment so each target is a different size
	}
}

int
Board::getLocationInput(int size) {
	int input;
	std::cout << "Please choose a location from 1 to 60 for " <<
		"your target of size " << size << ": ";
	while (!(std::cin >> input) || !isLocationValid(input, size)) {
		std::cout << "Not a valid location! Try again: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}

	// subtract 1 to match the location input to the board array
	return input - 1;
}

bool
Board::isLocationValid(int location, int size) {
	int maxLocation = location + size - 1;
	if (location >= 1 && maxLocation <= 60) {
		for (int i = location; i <= maxLocation; i++) 
		{	// would this new target be placed on any occupied locations?
			if (board[i-1] != -1) 
				return false;
		}
		return true;
	}else {
		return false;
	}
}

int
Board::getTargetIndex(int location) {
	return board[location];
}
