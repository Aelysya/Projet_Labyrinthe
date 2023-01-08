#include "tracer.h"
#include <iostream>

utility::tracer::tracer(const int& x, const int& y) : moves(0), sizex(x), sizey(y)
{
	this->seenTiles = new direction*[y];
	this->blockedTiles = new bool*[y];
	for (size_t i = 0; i < y; ++i) {
		this->seenTiles[i] = new direction[x];
		this->blockedTiles[i] = new bool[x];
		for (size_t j = 0; j < x; j++) {
			this->seenTiles[i][j] = NONE;
			this->blockedTiles[i][j] = true;
		}
	}
}

utility::tracer::tracer(const utility::tracer& t) : moves(t.moves), sizex(t.sizex), sizey(t.sizey)
{
	this->seenTiles = new direction *[this->sizey];
	this->blockedTiles = new bool*[this->sizey];
	for (size_t i = 0; i < this->sizey; ++i) {
		this->seenTiles[i] = new direction[this->sizex];
		this->blockedTiles[i] = new bool[this->sizex];
		for (size_t j = 0; j < this->sizex; j++) {
			this->seenTiles[i][j] = t.seenTiles[i][j];
			this->blockedTiles[i][j] = t.blockedTiles[i][j];
		}
	}
}

utility::tracer::~tracer()
{
	for (size_t i = 0; i < this->sizey; ++i) {
		delete[] this->seenTiles[i];
		delete[] this->blockedTiles[i];
	}
	delete[] this->seenTiles;
	delete[] this->blockedTiles;
}

utility::tracer& utility::tracer::operator=(const utility::tracer& t)
{
	if (this != &t) {
		this->sizex = t.sizex;
		this->sizey = t.sizey;
		for (size_t i = 0; i < this->sizey; ++i) {
			delete[] this->seenTiles[i];
			delete[] this->blockedTiles[i];
		}
		delete[] this->seenTiles;
		delete[] this->blockedTiles;

		this->seenTiles = new direction *[this->sizey];
		this->blockedTiles = new bool*[this->sizey];
		for (size_t i = 0; i < this->sizey; ++i) {
			this->seenTiles[i] = new direction[this->sizex];
			this->blockedTiles[i] = new bool[this->sizex];
			for (size_t j = 0; j < this->sizex; j++) {
				this->seenTiles[i][j] = t.seenTiles[i][j];
				this->blockedTiles[i][j] = t.blockedTiles[i][j];
			}
		}
	}
	return *this;
}

int utility::tracer::getMoves()
{
	return this->moves;
}

void utility::tracer::addMove(const int& x, const int& y, const direction& d)
{
	this->seenTiles[y][x] = d;
	switch (d) {
	case UP:
		this->seenTiles[y - 1][x] = d;
		break;
	case DOWN:
		this->seenTiles[y + 1][x] = d;
		break;
	case RIGHT:
		this->seenTiles[y][x + 1] = d;
		break;
	case LEFT:
		this->seenTiles[y][x - 1] = d;
		break;
	}
	this->moves++;
}

void utility::tracer::checkBlocked(const int& x, const int& y, const direction& d, const utility::grid& g)
{
	bool blckup = this->isAccessible(x, y - 1) && g.isAccessible(x, y - 1);
	bool blckdown = this->isAccessible(x, y + 1) && g.isAccessible(x, y + 1);
	bool blckleft = this->isAccessible(x - 1, y) && g.isAccessible(x - 1, y);
	bool blckright = this->isAccessible(x + 1, y) && g.isAccessible(x + 1, y);

	switch (d) {
	case UP:
		this->blockedTiles[y - 1][x] = blckdown || blckleft || blckright;
		break;
	case DOWN:
		this->blockedTiles[y + 1][x] = blckup || blckleft || blckright;
		break;
	case RIGHT:
		this->blockedTiles[y][x + 1] = blckdown || blckleft || blckup;
		break;
	case LEFT:
		this->blockedTiles[y][x - 1] = blckdown || blckup || blckright;
		break;
	}
}

utility::direction& utility::tracer::isSeen(const int& x, const int& y) const
{
	return seenTiles[y][x];
}

bool utility::tracer::isAccessible(const int& x, const int& y) const
{
	return blockedTiles[y][x];
}