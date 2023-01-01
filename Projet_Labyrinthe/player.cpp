#include <iostream>
#include "player.h"

coo::player::player(const std::string& fileName) : x(1), y(1), maze(fileName, 2), currentDirection(RIGHT)
{
}

void coo::player::printHistory() const
{
	this->moveHistory.printHistory();
}

bool coo::player::operator+(const direction& d) const
{
	bool canMove = false;
	switch (d) {
	case UP:
		canMove = this->maze.isAccessible(this->y - 1, this->x);
		break;
	case DOWN:
		canMove = this->maze.isAccessible(this->y + 1, this->x);
		break;
	case RIGHT:
		canMove = this->maze.isAccessible(this->y, this->x + 1);
		break;
	case LEFT:
		canMove = this->maze.isAccessible(this->y, this->x - 1);
		break;
	}
	return canMove;
}

void coo::player::operator+=(const direction& d)
{
	switch (d) {
	case UP :
		this->y -= 2;
		break;
	case DOWN :
		this->y += 2;
		break;
	case RIGHT :
		this->x += 2;
		break;
	case LEFT :
		this->x -= 2;
		break;
	}
	this->moveHistory.addMove(d);
}

void coo::player::printPosition() const
{
	this->maze.printMaze(this->x, this->y);
}