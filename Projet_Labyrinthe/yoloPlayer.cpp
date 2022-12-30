#include "yoloPlayer.h"
#include <iostream>

void coo::yoloPlayer::changeDirection()
{
	int RandIndex = rand() % 4;
	switch (RandIndex) {
	case 0:
		this->currentDirection = UP;
		break;
	case 1:
		this->currentDirection = DOWN;
		break;
	case 2:
		this->currentDirection = RIGHT;
		break;
	case 3:
		this->currentDirection = LEFT;
		break;
	}
}

coo::yoloPlayer::yoloPlayer(const grid& g) : player(g)
{
}

bool coo::yoloPlayer::solve()
{
	std::cout << "yoloPlayer solve" << std::endl;
	while (positionX != maze.getSizeX() - 1 && positionY != maze.getSizeY() - 1) {
		if (*this + currentDirection) {
			std::cout << "yoloPlayer solving :) " << this->currentDirection << std::endl;
			*this += currentDirection;
			this->printMaze();
		}
		else {
			std::cout << "tournicotis, tournicotons" << this->currentDirection << std::endl;
			this->changeDirection();
			this->printMaze();
		}
	}
	return true;
}
