#include <iostream>
#include "leftIfNotForwardPlayer.h"

void coo::leftIfNotForwardPlayer::changeDirection()
{
	switch (currentDirection) {
	case UP:
		this->currentDirection = LEFT;
		break;
	case LEFT:
		this->currentDirection = DOWN;
		break;
	case DOWN:
		this->currentDirection = RIGHT;
		break;
	case RIGHT:
		this->currentDirection = UP;
		break;
	}
}

coo::leftIfNotForwardPlayer::leftIfNotForwardPlayer(const grid& g) : player(g, g.getX(), g.getY())
{
}

int coo::leftIfNotForwardPlayer::solve()
{
	while (!(this->x == maze.getX() - 2 && this->y == maze.getY() - 2)) {
		if (*this + currentDirection) {
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
