#include "grid.h"
#include <fstream>
#include <iostream>

coo::grid::grid(const std::string& fileName)
{
	std::ifstream fd(fileName);
	std::string line;
	//Lecture de la première ligne pour déterminer la taille du labyrinthe
	std::getline(fd, line);
	this->size = (line.length() - 1) / 3;
	this->tiles = new tile*[size * size];

	//Initialisation des cases
	int tileCounter = 0;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			this->tiles[tileCounter] = new tile(i, j);
			tileCounter++;
		}
	}

	//for (int i = 0; i < 9; ++i) {
	//	tiles[i]->print();
	//}

	//Attribution des voisins accessibles pour chaque case
	while (!fd.eof()) {
		std::getline(fd, line);
	}
	fd.close();
}

coo::grid::~grid()
{
	for (int i = 0; i < this->size * this->size; ++i) {
		delete this->tiles[i];
	}
	delete[] this->tiles;
}
