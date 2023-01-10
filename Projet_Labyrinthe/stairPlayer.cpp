#include <iostream>
#include "stairPlayer.h"

using namespace utility;

players::stairPlayer::stairPlayer(const grid& g) : player(g, g.getX(), g.getY(), "stairPlayer")
{
}

int players::stairPlayer::solve()
{
	int playerBlockedCounter = 0;
	while (!(this->x == maze.getX() - 2 && this->y == maze.getY() - 2)) {
		if (*this + getNextDirection()) {
			*this += this->currentDirection;
			playerBlockedCounter = 0;
		}
		//Si le joueur n'a pas boug�, on augmente le compteur de tours bloqu�
		else {
			playerBlockedCounter++;
		}
		//Si le joueur est bloqu� depuis 3 tours, arr�t de la r�solution
		if (playerBlockedCounter > 3) {
			return -1;
		}
	}
	this->printHistory();
	return this->moveHistory.getMoves();
}

direction players::stairPlayer::getNextDirection()
{
	switch (this->currentDirection) {
	case UP:
	case DOWN:
		this->currentDirection = RIGHT;
		break;
	case RIGHT:
	case LEFT:
		this->currentDirection = DOWN;
		break;
	}
	return this->currentDirection;
}