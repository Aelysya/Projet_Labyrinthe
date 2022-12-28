#include "tracer.h"

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