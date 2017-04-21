#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Board.h"

class Game
{
public:
	Game();

private:
	Player whitePlayer;
	Player blackPlayer;
	Board board;
};
#endif // !GAME_H
