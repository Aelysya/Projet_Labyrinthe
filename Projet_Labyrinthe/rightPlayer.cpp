#include <iostream>
#include "rightPlayer.h"

void coo::rightPlayer::changeDirection()
{
	switch (currentDirection) {
	case UP:
		this->currentDirection = RIGHT;
		break;
	case DOWN:
		this->currentDirection = LEFT;
		break;
	case RIGHT:
		this->currentDirection = DOWN;
		break;
	case LEFT:
		this->currentDirection = UP;
		break;
	}
}

coo::rightPlayer::rightPlayer(const grid& g) : player(g)
{
}

int coo::rightPlayer::solve()
{
	std::cout << "rightPlayer solve";
	return -1;
}
