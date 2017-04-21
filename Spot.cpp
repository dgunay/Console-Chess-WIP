#include "Spot.h"
#include <iostream>


#include "Piece.h"

using namespace std;

Spot::Spot()
{
	piece = nullptr;
}

Spot::Spot(rowColPair coords)
{
	this->coords = coords;
	piece = nullptr;
}

Spot::Spot(rowColPair coords, Piece* pc)
{
	this->coords = coords;
	piece = pc;
}

void Spot::setCoords(rowColPair coords)
{
	this->coords = coords;
}

void Spot::setPiece(Piece* pc)
{
	if (piece != nullptr)
		delete piece;
	piece = pc;
}

Piece* Spot::getPiece()
{
	return piece;
}

void Spot::printSpot()
{
	cout << "[ ";
	if (piece != nullptr)
		cout << piece->getIcon() << " ]";
	else
		cout << "  ]";
}

Spot::~Spot()
{
	delete piece;
	piece = nullptr;
}
