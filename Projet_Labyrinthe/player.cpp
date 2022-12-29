#include "player.h"

coo::player::player(const tracer& t) : positionX(0), positionY(0), moveHistory(t)
{
}

coo::player::~player()
{
}

void coo::player::operator+(const direction& d)
{
	switch (d) {
	case UP :
		this->positionY++;
		break;
	case DOWN :
		this->positionY--;
		break;
	case RIGHT :
		this->positionX++;
		break;
	case LEFT :
		this->positionX--;
		break;
	default :
		return;
	}
	this->moveHistory.addMove(d);
}

void coo::player::printHistory() const
{
	this->moveHistory.printHistory();
}
