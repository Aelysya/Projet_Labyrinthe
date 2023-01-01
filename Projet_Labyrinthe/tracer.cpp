#include "tracer.h"
#include <iostream>

utility::tracer::tracer()
{
}

utility::tracer::tracer(const utility::tracer& t)
{
	for (direction d : t.moveHistory) {
		this->moveHistory.push_back(d);
	}
}

utility::tracer::~tracer()
{
}

utility::tracer& utility::tracer::operator=(const utility::tracer& t)
{
	this->moveHistory.clear();
	for (direction d : t.moveHistory) {
		this->moveHistory.push_back(d);
	}
	return *this;
}

void utility::tracer::addMove(const direction& d)
{
	this->moveHistory.push_back(d);
}

void utility::tracer::printHistory() const
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
