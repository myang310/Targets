// Ming Yang

#ifndef BOARD_H
#define BOARD_H

#include "target.h"

class Board {
	public:
		Board();
		~Board();
		Board(Board& original);
		Board operator=(const Board& right);
		void hitAt(int location);
		void displayBoard();
		bool isDefeated();
		bool isHitAlready(int location);
		static int getLocationInput(Board board);  // allows client to ask player 
							   // for location to shoot
	private:
		int getLocationInput(int size); // asks player for location to place target
		void setupTargets();
		void selfSetupTargets();
		void randomSetupTargets();
		bool isLocationValid(int location, int size);  // checks if the location is between 1-60
		static bool isLocationValid(int location, Board board);
		int getTargetIndex(int location);  // returns the index of the target if it
														// occupies that location, else returns -1

		const static int SIZE = 60;
		const static int TARGET_COUNT = 5;
		bool* spotsHit;
		int* board;		// holds location of targets  with its index in targets
							//	as identifier
		Target* targets;
};

#endif
