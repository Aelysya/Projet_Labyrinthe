#include "yoloPlayer.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace utility;

players::yoloPlayer::yoloPlayer(const grid& g) : player(g, g.getX(), g.getY(), "yoloPlayer")
{
}

int players::yoloPlayer::solve()
{
	while (!(this->x == maze.getX() - 2 && this->y == maze.getY() - 2)) {
		*this += this->getNextDirection();
		//this->printHistory();
	}
	this->printHistory();
	return this->moveHistory.getMoves();
}

direction players::yoloPlayer::getNextDirection()
{
	srand(time(NULL));
	std::vector<int> movesP;
	for (int i = 0; i < 4; i++)
	{
		if (*this + static_cast<direction>(i) && this->moveHistory.isSeen(this->x, this->y) != static_cast<direction>(i)) {
			movesP.push_back(i);
		}
	}
	this->currentDirection = static_cast<direction>(movesP.at(rand() % movesP.size()));
	return this->currentDirection;
}
