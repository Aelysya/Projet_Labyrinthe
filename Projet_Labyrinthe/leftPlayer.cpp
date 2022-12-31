#include <iostream>
#include "leftPlayer.h"

coo::leftPlayer::leftPlayer(const std::string& fileName) : player(fileName)
{
}

void coo::leftPlayer::solve()
{
	std::cout << "leftPlayer solve" << std::endl;
	while (!(this->x == maze.getSizeX() - 2 && this->y == maze.getSizeY() - 2)) {
		*this += getNextDirection();
		printPosition();
	}
}

coo::direction coo::leftPlayer::getNextDirection()
{
	switch (this->currentDirection) {
	case UP:
		if (*this + LEFT) {
			this->currentDirection = LEFT;
		}
		else if (*this + UP) {
			this->currentDirection = UP;
		}
		else if (*this + RIGHT) {
			this->currentDirection = RIGHT;
		}
		else {
			this->currentDirection = DOWN;
		}
		break;
	case DOWN:
		if (*this + RIGHT) {
			this->currentDirection = RIGHT;
		}
		else if (*this + DOWN) {
			this->currentDirection = DOWN;
		}
		else if (*this + LEFT){
			this->currentDirection = LEFT;
		}
		else {
			this->currentDirection = UP;
		}
		break;
	case RIGHT:
		if (*this + UP) {
			this->currentDirection = UP;
		}
		else if (*this + RIGHT) {
			this->currentDirection = RIGHT;
			break;
		}
		else if (*this + DOWN) {
			this->currentDirection = DOWN;
		}
		else {
			this->currentDirection = LEFT;
		}
		break;
	case LEFT:
		if (*this + DOWN) {
			this->currentDirection = DOWN;
		}
		else if (*this + LEFT) {
			this->currentDirection = LEFT;
		}
		else if (*this + UP) {
			this->currentDirection = UP;
		}
		else {
			this->currentDirection = RIGHT;
		}
		break;
	}

	return this->currentDirection;
}
