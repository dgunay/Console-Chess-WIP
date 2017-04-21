#ifndef QUEEN_H
#define QUEEN_H



#include "Piece.h"

class Queen : public Piece
{
public:
	Queen();
	Queen(std::string color, rowColPair coords);

	bool isValidMove(Board& board, rowColPair moveTo) const;

private:
};

#endif // !QUEEN_H