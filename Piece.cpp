#include "Piece.h"
#include "MoveToException.h"
#include <cmath>

//Initialize uppercase char for WHITE, lowercase for BLACK
Piece::Piece()
{
	icon = '_';
}

Piece::Piece(std::string color, rowColPair coords)
{
	this->color = color;
	this->coords = coords;
	icon = '_';
}

char Piece::getIcon()
{
	return icon;
}

bool Piece::isValidMove(Board& board, rowColPair moveTo) const
{
	//did the piece move at all?
	if (coords.row != moveTo.row || coords.col != moveTo.col)
	{
		if (board.inBounds(moveTo)) //is the move on the board?
		{
			//is the destination an enemy (capturable) piece or unoccupied?
			if (!isFriendly(board, moveTo) || !board.isOccupied(moveTo))
				return true;
		}
	}

	return false;
}

bool Piece::isFriendly(const Board & board, rowColPair coords) const
{
	if (board.inBounds(coords))
	{
		return this->color == board.getSpot(coords).getPiece()->color;
	}

	return true; //CONSIDER an exception for out_of_range, and an exception for an empty space
}


//WRITE EXCEPTION FOR non-orthogonal moves
bool Piece::collidesOrthogonally(const Board & board, rowColPair moveTo) const
{
	if (moveTo.row != coords.row && moveTo.col != coords.col) //throw exception for non-orthogonal move
	{
		MoveToException m;
		throw m;
	}

	rowColPair check = coords;

	if (moveTo.row < coords.row && moveTo.col == coords.col) //move north
	{
		for (int i = 0; i < coords.row - moveTo.row; i++)
		{
			check.row--;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}
	else if (moveTo.row > coords.row && moveTo.col == coords.col) //move south
	{
		for (int i = 0; i < moveTo.row - coords.row; i++)
		{
			check.row++;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}
	else if (moveTo.row == coords.row && moveTo.col > coords.col) //move east
	{
		for (int i = 0; i < moveTo.col - coords.col; i++)
		{
			check.col++;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}
	else if (moveTo.row == coords.row && moveTo.col < coords.col) //move west
	{
		for (int i = 0; i < coords.col - moveTo.col; i++)
		{
			check.col--;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}

	return true;
}


bool Piece::collidesDiagonally(const Board & board, rowColPair moveTo) const
{
	if ()
	{
		MoveToException m;
		throw m;
	}

	rowColPair check = coords;

	if (moveTo.row < coords.row && moveTo.col > coords.col) //move northeast (-,+)
	{
		for (int i = 0; i < coords.row - moveTo.row; i++)
		{
			check.row--;
			check.col++;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}
	else if (moveTo.row < coords.row && moveTo.col < coords.col) //move northwest (-,-)
	{
		for (int i = 0; i < moveTo.row - coords.row; i++)
		{
			check.row--;
			check.col--;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}
	else if (moveTo.row > coords.row && moveTo.col > coords.col) //move southeast(+,+)
	{
		for (int i = 0; i < moveTo.col - coords.col; i++)
		{
			check.row++;
			check.col++;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}
	else if (moveTo.row > coords.row && moveTo.col < coords.col) //move southwest(+,-)
	{
		for (int i = 0; i < coords.col - moveTo.col; i++)
		{
			check.row++;
			check.col++;
			if (check == moveTo && board.isOccupied(check)) //check final space for capturable piece
				return !isFriendly(board, check); //no collision for capturable piece on last spot
			else if (board.isOccupied(check))
				return false;
		}

		return true;
	}

	return true; //this return is a formality - consider an exception for invalid moveTo?
}

bool Piece::threatensSpace(const Board & board, std::string incomingColor, rowColPair incomingMove) const
{
	return false;
}


Piece::~Piece()
{
}
