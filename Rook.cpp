#include "Rook.h"

Rook::Rook()
{
}

Rook::Rook(std::string color, rowColPair coords) : Piece(color, coords)
{
	if (color == WHITE) //I only check for white or nonwhite. White pieces are uppercase too. Is that racist?
		icon = 'R';
	else
		icon = 'r';
}

bool Rook::isValidMove(Board & board, rowColPair moveTo) const
{
	if (Piece::isValidMove(board, moveTo)) //basic move rules (in bounds, not on friendly piece)
	{
		//rook move rules
		if (straightLine(board, moveTo)) //is it an orthogonal line from the rook?
		{
			if (!this->collidesOrthogonally(board, moveTo)) //is there a piece in the way?
				return true;
		}
	}
	return false;
}

//TODO: rewrite logic with XOR ( != )
bool Rook::straightLine(const Board& board, rowColPair coords) const
{
	//(same row && different col) || (different row && same col)
	return ((this->coords.row == coords.row && this->coords.col != coords.col)
		|| this->coords.row != coords.row && this->coords.col == coords.col);
}

bool Rook::threatensSpace(const Board & board, std::string incomingColor, rowColPair incomingMove) const
{
	if (incomingColor == color) //don't threaten friendly pieces
		return false;
	else if (coords.row == incomingMove.row || coords.col == incomingMove.col) //will the rook be orthogonal to the incoming piece?
	{			
		if (!collidesOrthogonally(board, incomingMove)) //if nothing is between the rook and the piece
			return true; //the rook threatens it
	}

	return false;
}


