#include <iostream>
#include "rightPlayer.h"

using namespace utility;

players::rightPlayer::rightPlayer(const grid& g) : player(g, g.getX(), g.getY(), "rightPlayer")
{
}

int players::rightPlayer::solve()
{
	while (!(this->x == maze.getX() - 2 && this->y == maze.getY() - 2)) {
		*this += getNextDirection();
		//printPosition();
	}
	this->printHistory();
	return this->moveHistory.getMoves();
}

direction players::rightPlayer::getNextDirection()
{
	switch (this->currentDirection) {
	case UP:
		if (*this + RIGHT) {
			this->currentDirection = RIGHT;
		}
		else if (*this + UP) {
			this->currentDirection = UP;
		}
		else if (*this + LEFT) {
			this->currentDirection = LEFT;
		}
		else {
			this->currentDirection = DOWN;
		}
		break;
	case DOWN:
		if (*this + LEFT) {
			this->currentDirection = LEFT;
		}
		else if (*this + DOWN) {
			this->currentDirection = DOWN;
		}
		else if (*this + RIGHT) {
			this->currentDirection = RIGHT;
		}
		else {
			this->currentDirection = UP;
		}
		break;
	case RIGHT:
		if (*this + DOWN) {
			this->currentDirection = DOWN;
		}
		else if (*this + RIGHT) {
			this->currentDirection = RIGHT;
			break;
		}
		else if (*this + UP) {
			this->currentDirection = UP;
		}
		else {
			this->currentDirection = LEFT;
		}
		break;
	case LEFT:
		if (*this + UP) {
		this->currentDirection = UP;
		}
		else if (*this + LEFT) {
			this->currentDirection = LEFT;
		}
		else if (*this + DOWN) {
			this->currentDirection = DOWN;
		}
		else {
			this->currentDirection = RIGHT;
		}
		break;
	}

	return this->currentDirection;
}