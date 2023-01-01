#include "yoloPlayer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace utility;

players::yoloPlayer::yoloPlayer(const std::string& fileName) : player(fileName)
{
}

void players::yoloPlayer::solve()
{
	while (!(this->x == maze.getSizeX() - 2 && this->y == maze.getSizeY() - 2)) {
		*this += getNextDirection();
		printPosition();
	}
}

direction players::yoloPlayer::getNextDirection()
{
	srand(time(NULL));
	do {
		this->currentDirection = static_cast<direction>(rand() % 4);
	} while (!(*this + currentDirection));

	return this->currentDirection;
}
