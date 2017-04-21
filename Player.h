#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player
{
public:
	Player();
	Player(std::string color);


private:
	std::string color;
};
#endif // !PLAYER_H
