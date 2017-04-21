#include "Spot.h"

#ifndef PIECE_H
#define PIECE_H

#include <string>
#include "Board.h"


const std::string WHITE = "white";
const std::string BLACK = "black";

//class Board;

class Piece
{
public:
	Piece();
	Piece(std::string color, rowColPair coords);
	char getIcon();

	virtual bool isValidMove(Board& board, rowColPair coords) const;
	bool isFriendly(const Board& board, rowColPair coords) const;
	bool collidesOrthogonally(const Board& board, rowColPair moveTo) const;
	bool collidesDiagonally(const Board& board, rowColPair moveTo) const;
	virtual bool threatensSpace(const Board& board, std::string incomingColor, rowColPair incomingMove) const;

	~Piece(); //CONSIDER A VIRTUAL DESTRUCTOR

protected:
	std::string color;
	rowColPair coords; //where the piece currently is on the board
	char icon;
};
#endif // !PIECE_H
