#include "Queen.h"

Queen::Queen()
{
}

Queen::Queen(std::string color, rowColPair coords) : Piece(color, coords)
{
	if (color == WHITE)
		icon = 'Q';
	else
		icon = 'q';
}

bool Queen::isValidMove(Board & board, rowColPair moveTo) const
{
	if (Piece::isValidMove(board, moveTo)) //basic move rules
	{
		if ((coords.row == moveTo.row) != (coords.col == moveTo.col)) //orthogonal move (XOR logically equiv to !=)
			return !collidesOrthogonally(board, moveTo);

		else if (coords.row != moveTo.row && coords.col != moveTo.col) //diagonal move
			return !collidesDiagonally(board, moveTo);
	}

	return false;
}
