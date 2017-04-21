#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include <string>
class Rook : public Piece
{
public:
	Rook();
	Rook(std::string color, rowColPair coords);
	bool isValidMove(Board& board, rowColPair moveTo) const;
	bool straightLine(const Board & board, rowColPair coords) const;
	bool threatensSpace(const Board & board, std::string incomingColor, rowColPair incomingMove) const;
};
#endif // !ROOK_H
