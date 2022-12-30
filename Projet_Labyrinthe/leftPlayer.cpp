#include <iostream>
#include "leftPlayer.h"

void coo::leftPlayer::changeDirection()
{
	switch (currentDirection) {
	case UP:
		this->currentDirection = LEFT;
		break;
	case DOWN:
		this->currentDirection = RIGHT;
		break;
	case RIGHT:
		this->currentDirection = UP;
		break;
	case LEFT:
		this->currentDirection = DOWN;
		break;
	}
}

coo::leftPlayer::leftPlayer(const grid& g) : player(g)
{
}

bool coo::leftPlayer::solve()
{
    std::cout << "leftPlayer solve" << std::endl;
	while (positionX != maze.getSizeX() - 1 && positionY != maze.getSizeY() - 1) {
		if (*this + currentDirection) {
			std::cout << "leftPlayer solving :) " << this->currentDirection << std::endl;
			*this += currentDirection;
			this->printMaze();
		}
		else {
			std::cout << "tournicotis, tournicotons" << std::endl;
			this->changeDirection();
		}
	}
    return true;
}
