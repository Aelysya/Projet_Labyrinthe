#include "tracer.h"
#include <iostream>

coo::tracer::tracer(const int& x, const int& y) : moveAmount(0), sizex(x), sizey(y)
{
	this->seenTiles = new bool*[y];
	for (size_t i = 0; i < y; ++i) {
		this->seenTiles[i] = new bool[x];
		for (size_t j = 0; j < x; j++) {
			this->seenTiles[i][j] = false;
		}
	}

	this->blockedTiles = new bool* [y];
	for (size_t i = 0; i < y; ++i) {
		this->blockedTiles[i] = new bool[x];
		for (size_t j = 0; j < x; j++) {
			this->blockedTiles[i][j] = false;
		}
	}
}

coo::tracer::tracer(const coo::tracer& t) : moveAmount(t.moveAmount), sizex(t.sizex), sizey(t.sizey)
{
	this->seenTiles = new bool*[this->sizey];
	this->blockedTiles = new bool*[this->sizey];
	for (size_t i = 0; i < this->sizey; ++i) {
		this->seenTiles[i] = new bool[this->sizex];
		this->blockedTiles[i] = new bool[this->sizex];
		for (size_t j = 0; j < this->sizex; j++) {
			this->seenTiles[i][j] = t.seenTiles[i][j];
			this->blockedTiles[i][j] = t.blockedTiles[i][j];
		}
	}
}

coo::tracer::~tracer()
{
	for (size_t i = 0; i < this->sizey; ++i) {
		delete[] this->seenTiles[i];
		delete[] this->blockedTiles[i];
	}
	delete[] this->seenTiles;
	delete[] this->blockedTiles;
}

coo::tracer& coo::tracer::operator=(const coo::tracer& t)
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

		this->seenTiles = new bool*[this->sizey];
		this->blockedTiles = new bool*[this->sizey];
		for (size_t i = 0; i < this->sizey; ++i) {
			this->seenTiles[i] = new bool[this->sizex];
			this->blockedTiles[i] = new bool[this->sizex];
			for (size_t j = 0; j < this->sizex; j++) {
				this->seenTiles[i][j] = t.seenTiles[i][j];
				this->blockedTiles[i][j] = t.blockedTiles[i][j];
			}
		}
	}
	return *this;
}

void coo::tracer::addMove(const int& x, const int& y, const direction& d)
{
	// todo: penser à mettre les deux cases dans seenTiles
	// modification de blockedTiles ici (normalement)
}

bool coo::tracer::isAccessible(const int& x, const int& y) const
{
	return blockedTiles[y][x];
}