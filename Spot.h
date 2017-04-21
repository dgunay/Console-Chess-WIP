#include "Board.h"



#ifndef SPOT_H
#define SPOT_H

class Piece;

struct rowColPair
{
	rowColPair() {}
	rowColPair(int r, int c) { row = r; col = c; }
	int row;
	int col;
	bool operator==(const rowColPair& rh)
	{
		return (row == rh.row && col == rh.col);
	}
};


class Spot
{
public:
	Spot();
	Spot(rowColPair coords);
	Spot(rowColPair coords, Piece* pc);

	void setCoords(rowColPair coords);
	void setPiece(Piece* pc);
	Piece* getPiece();
	void printSpot();

	~Spot();
private:
	Piece* piece; //USE A POINTER TO PIECE INSTEAD
	rowColPair coords;
};


#endif // !SPOT_H
