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

int coo::yoloPlayer::solve()
{
	std::cout << "yoloPlayer solve" << std::endl;
	while (x != maze.getX() - 1 && y != maze.getY() - 1) {
		if (*this + currentDirection) {
			std::cout << "yoloPlayer solving :) " << this->currentDirection << std::endl;
			*this += currentDirection;
			this->printPosition();
		}
		else {
			std::cout << "tournicotis, tournicotons" << this->currentDirection << std::endl;
			this->changeDirection();
			this->printPosition();
		}
	}
	return -1;
}
