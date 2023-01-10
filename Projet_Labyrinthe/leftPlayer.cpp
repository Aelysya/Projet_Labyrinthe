#include <iostream>
#include "leftPlayer.h"

using namespace utility;

direction players::leftPlayer::getNextDirection()
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
		else if (*this + LEFT) {
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

players::leftPlayer::leftPlayer(const grid& g) : player(g, g.getX(), g.getY(), "leftPlayer")
{
}

int players::leftPlayer::solve()
{
	while (!(this->x == maze.getX() - 2 && this->y == maze.getY() - 2)) {
		*this += getNextDirection();
	}
	this->printHistory();
	return this->moveHistory.getMoves();
}