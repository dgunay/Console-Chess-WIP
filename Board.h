#ifndef BOARD_H
#define BOARD_H

#include "Spot.h"

const int ROWS = 8;
const int COLS = 8;

class Board
{
public:
	Board();

	void printBoard() const;
	void setBoard();
	bool inBounds(rowColPair coords) const;
	bool isOccupied(rowColPair coords) const;
	Spot getSpot(rowColPair coords) const;
	Spot getSpot(int row, int col) const;

	~Board();

private:
	Spot** spots;
};
#endif // !BOARD_H
