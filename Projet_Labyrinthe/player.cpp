#include <iostream>
#include "player.h"

using namespace utility;

players::player::player(const grid& g, const int& x, const int& y, const std::string& name) : x(1), y(1), maze(g), moveHistory(x, y), currentDirection(RIGHT), name(name)
{
}

players::player::~player()
{
}

bool players::player::operator+(const direction& d) const
{
	bool isAccW = false;
	bool isAccB = false;
	switch (d) {
	case UP:
		isAccW = this->maze.isAccessible(this->x, this->y - 1);
		isAccB = this->moveHistory.isAccessible(this->x, this->y - 1);
		break;
	case LEFT:
		isAccW = this->maze.isAccessible(this->x - 1, this->y);
		isAccB = this->moveHistory.isAccessible(this->x - 1, this->y);
		break;
	case DOWN:
		isAccW = this->maze.isAccessible(this->x, this->y + 1);
		isAccB = this->moveHistory.isAccessible(this->x, this->y + 1);
		break;
	case RIGHT:
		isAccW = this->maze.isAccessible(this->x + 1, this->y);
		isAccB = this->moveHistory.isAccessible(this->x + 1, this->y);
		break;
	}
	bool canMove = isAccW && isAccB;
	return canMove;
}

bool players::player::operator+=(const direction& d)
{
	if (this + d) {
		this->moveHistory.checkBlocked(this->x, this->y, d, this->maze);
		this->moveHistory.addMove(this->x, this->y, d);
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
		return true;
	}
	else {
		return false;
	}
}

void players::player::printHistory() const
{
	for (size_t i = 0; i < this->maze.getY(); ++i) {
		for (size_t j = 0; j < this->maze.getX(); ++j) {
			if (this->maze.isAccessible(j,i)) {
				if (j == x && i == y) {
					std::cout << "X";
				}
				else {
					if (this->moveHistory.isSeen(j,i) != NONE) {
						std::cout << "-";
					}
					else {
						std::cout << " ";
					}
					
				}
			}
			else {
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void players::player::printPosition() const
{
	this->maze.printMaze(this->x, this->y);
}

std::string players::player::getName()
{
	return this->name;
}
