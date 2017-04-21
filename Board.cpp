#include "Board.h"
#include "Rook.h"
#include <iostream>

using namespace std;
Board::Board()
{
	spots = new Spot*[ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		spots[i] = new Spot[COLS];
		for (int j = 0; j < COLS; j++)
		{
			spots[i][j].setCoords(rowColPair(i, j));
		}
	}
}

void Board::printBoard() const
{
	for (int i = 0; i < 100; i++)
		cout << "\n";

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			spots[i][j].printSpot();
			cout << " ";
		}

		cout << endl;
	}
		
			
}

void Board::setBoard()
{
	//populate the board with a standard chess board layout
	cout << "setBoard() NOT IMPLEMENTED YET" << endl;
	rowColPair rook1, rook2;
	rook1.row = 0;
	rook1.col = 0;

	rook2.row = 0;
	rook2.col = 5;
	spots[0][0].setPiece(new Rook(WHITE, rook1));
	spots[0][5].setPiece(new Rook(WHITE, rook2));
}

bool Board::inBounds(rowColPair coords) const
{
	return coords.row >= 0 && coords.row < 8 && coords.col >= 0 && coords.col < 8;
}

bool Board::isOccupied(rowColPair coords) const
{
	return this->getSpot(coords).getPiece() != nullptr;
}

Spot Board::getSpot(rowColPair coords) const
{
	return spots[coords.row][coords.col];
}

Spot Board::getSpot(int row, int col) const
{
	return spots[row][col];
}

Board::~Board()
{
	//delete the Spots
	for (int i = 0; i < ROWS; i++)
	{
		delete[] spots[i];
	}

	delete[] spots;
}
