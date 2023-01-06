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
			*this += getNextDirection();
			//printPosition();
			playerBlockedCounter = 0;
		}
		//Si le joueur n'a pas bougé, on augmente le compteur de tours bloqué
		else {
			playerBlockedCounter++;
		}
		this->currentDirection = getNextDirection();
		//Si le joueur est bloqué depuis 5 tours, arrêt du jeu
		if (playerBlockedCounter > 5) {
			return -1;
		}
	}
	this->printHistory();
	return this->moveHistory.getMoves();
}

direction players::stairPlayer::getNextDirection()
{
	direction nextDirection;
	switch (this->currentDirection) {
	case UP:
	case DOWN:
		nextDirection = RIGHT;
		break;
	case RIGHT:
	case LEFT:
		nextDirection = DOWN;
		break;
	}

	return nextDirection;
}