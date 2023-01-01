#include "tracer.h"
#include <iostream>

coo::tracer::tracer()
{
}

coo::tracer::tracer(const coo::tracer& t)
{
	for (direction d : t.moveHistory) {
		this->moveHistory.push_back(d);
	}
}

coo::tracer::~tracer()
{
}

coo::tracer& coo::tracer::operator=(const coo::tracer& t)
{
	this->moveHistory.clear();
	for (direction d : t.moveHistory) {
		this->moveHistory.push_back(d);
	}
	return *this;
}

void coo::tracer::addMove(const direction& d)
{
	this->moveHistory.push_back(d);
}

void coo::tracer::printHistory() const
{
	std::string directionString;
	for (direction d : moveHistory) {
		switch (d) {
		case UP: directionString = "UP";
			break;
		case DOWN: directionString = "DOWN";
			break;
		case RIGHT: directionString = "RIGHT";
			break;
		case LEFT: directionString = "LEFT";
			break;
		}
		std::cout << "-> " << directionString << " ";
	}
	std::cout << std::endl;
}
