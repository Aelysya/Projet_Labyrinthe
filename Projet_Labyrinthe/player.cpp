#include "player.h"

coo::player::player(const grid& g) : positionX(1), positionY(1), moveHistory(*new tracer), maze(g), currentDirection(RIGHT)
{

}

bool coo::player::operator+(const direction& d) const
{
	bool canMove;
	switch (d) {
	case UP:
		canMove = this->maze.getTiles()[this->positionY - 1][this->positionX];
		break;
	case DOWN:
		canMove = this->maze.getTiles()[this->positionY + 1][this->positionX];
		break;
	case RIGHT:
		canMove = this->maze.getTiles()[this->positionY][this->positionX + 1];
		break;
	case LEFT:
		canMove = this->maze.getTiles()[this->positionY][this->positionX - 1];
		break;
	default:
		canMove = false;
	}
	return canMove;
}

bool coo::player::operator++() const {
	return this + this->currentDirection;
}

bool coo::player::operator+=(const direction& d)
{
	if (this + d) {
		switch (d) {
		case UP :
			this->positionY -= 2;
			break;
		case DOWN :
			this->positionY += 2;
			break;
		case RIGHT :
			this->positionX += 2;
			break;
		case LEFT :
			this->positionX -= 2;
			break;
		}
		this->moveHistory.addMove(d);
		return true;
	}
	else {
		return false;
	}
}

void coo::player::printHistory() const
{
	this->moveHistory.printHistory();
}

void coo::player::printMaze() const
{
	this->maze.printMaze(this->positionX, this->positionY);
}