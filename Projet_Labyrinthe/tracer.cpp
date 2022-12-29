#include "tracer.h"
#include <iostream>

coo::tracer::tracer()
{
}

coo::tracer::~tracer()
{
}

void coo::tracer::addMove(const direction& d)
{
	this->moveHistory.push_back(d);
}

void coo::tracer::printHistory() const
{
	for (direction d : moveHistory) {
		std::cout << " -> " << directionToString(d);
	}
	std::cout <<std::endl;
}

const std::string coo::tracer::directionToString(const direction& d) const
{
	std::string s;

	switch (d) {
	case UP:
		s = "UP";
		break;
	case DOWN:
		s = "DOWN";
		break;
	case RIGHT:
		s = "RIGHT";
		break;
	case LEFT:
		s = "LEFT";
		break;
	default:
		return "";
	}

	return s;
}
