#include "yoloPlayer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

coo::yoloPlayer::yoloPlayer(const std::string& fileName) : player(fileName)
{
}

void coo::yoloPlayer::solve()
{
	while (!(this->x == maze.getSizeX() - 2 && this->y == maze.getSizeY() - 2)) {
		*this += getNextDirection();
		printPosition();
	}
}

coo::direction coo::yoloPlayer::getNextDirection()
{
	srand(time(NULL));
	do {
		this->currentDirection = static_cast<direction>(rand() % 4);
	} while (!(*this + currentDirection));

	return this->currentDirection;
}
