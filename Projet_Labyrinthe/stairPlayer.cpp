#include <iostream>
#include "stairPlayer.h"

using namespace utility;

players::stairPlayer::stairPlayer(const grid& grid) : player(grid)
{
}

void players::stairPlayer::solve()
{
	printPosition();
	int playerBlockedCounter = 0;
	while (!(this->x == maze.getSizeX() - 2 && this->y == maze.getSizeY() - 2)) {
		if (*this + getNextDirection()) {
			*this += getNextDirection();
			printPosition();
			playerBlockedCounter = 0;
		}
		//Si le joueur n'a pas boug�, on augmente le compteur de tours bloqu�
		else {
			playerBlockedCounter++;
		}
		this->currentDirection = getNextDirection();
		//Si le joueur est bloqu� depuis 5 tours, arr�t du jeu
		if (playerBlockedCounter > 5) {
			break;
		}
	}
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