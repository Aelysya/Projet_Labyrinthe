#include <iostream>
#include "rightIfNotForwardPlayer.h"

using namespace utility;

void players::rightIfNotForwardPlayer::changeDirection()
{
	switch (currentDirection) {
	case UP:
		this->currentDirection = RIGHT;
		break;
	case RIGHT:
		this->currentDirection = DOWN;
		break;
	case DOWN:
		this->currentDirection = LEFT;
		break;
	case LEFT:
		this->currentDirection = UP;
		break;
	
	}
}

players::rightIfNotForwardPlayer::rightIfNotForwardPlayer(const grid& g) : player(g, g.getX(), g.getY(), "rightIfNotForwardPlayer")
{
}

int players::rightIfNotForwardPlayer::solve()
{
	while (!(this->x == maze.getX() - 2 && this->y == maze.getY() - 2)) {
		if (*this + currentDirection && this->moveHistory.isSeen(this->x, this->y) != this->currentDirection) {
			*this += currentDirection;
			//this->printHistory();
		}
		else {
			this->changeDirection();
		}
	}
	this->printHistory();
	return this->moveHistory.getMoves();
}