#include "grid.h"
#include <fstream>
#include <iostream>

coo::grid::grid(const std::string& fileName, const int& size)
{
	std::ifstream file(fileName);
	std::string line;
	std::getline(file, line);
	//Détermination du nombre de colonnes
	this->sizeX = 0;
	for (size_t j = 0; j < line.size(); j++) {
		if (j % 3 != size) {
			this->sizeX++;
		}
	}
	//Détermination du nombre de lignes
	this->sizeY = 0;
	while (!file.eof()) {
		this->sizeY++;
		std::getline(file, line);
	}
	//Retour au début du fichier
	file.clear();
	file.seekg(0);
	std::getline(file, line);

	//Transformation des caractères en booléens
	this->tiles = new bool*[this->sizeY];
	for (size_t i = 0; i < this->sizeY; ++i) {
		this->tiles[i] = new bool[this->sizeX];
		int k = -1; //Décalement des colonnes
		if (i != 0 || i != this->sizeY) {
			for (size_t j = 0; j < this->sizeX; j++) {
				if (j % size == 0) {
					k++;
				}
				if (i == 0 || i == this->sizeY-1 || j == 0 || j == this->sizeY-1) {
					this->tiles[i][j] = false;
				}
				else {
					if (line[j + k] == ' ') {
						this->tiles[i][j] = true;
					}
					else {
						this->tiles[i][j] = false;
					}
				}
				
			}
		}
		std::getline(file, line);
	}
	//Fermeture du fichier
	file.close();
}

coo::grid::grid(const grid& g) : sizeX(g.sizeX), sizeY(g.sizeY)
{
	this->tiles = new bool*[this->sizeY];
	for (size_t i = 0; i < this->sizeY; ++i)
	{
		this->tiles[i] = new bool[this->sizeX];
		for (size_t j = 0; j < this->sizeX; ++j)
		{
			this->tiles[i][j] = g.tiles[i][j];
		}
	}
}

coo::grid::~grid()
{
	for (size_t i = 0; i < this->sizeY; ++i) {
		delete[] this->tiles[i];
	}
	delete[] this->tiles;
}

coo::grid& coo::grid::operator=(const grid& g)
{
	if (this != &g) {
		for (size_t i = 0; i < this->sizeY; ++i) {
			delete[] this->tiles[i];
		}
		delete[] this->tiles;
		this->sizeX = g.sizeX;
		this->sizeY = g.sizeY;
		for (size_t i = 0; i < this->sizeY; ++i)
		{
			this->tiles[i] = new bool[this->sizeX];
			for (size_t j = 0; j < this->sizeX; ++j)
			{
				this->tiles[i][j] = g.tiles[i][j];
			}
		}
	}
	return *this;
}

int coo::grid::getSizeX() const
{
	return this->sizeX;
}
int coo::grid::getSizeY() const
{
	return this->sizeY;
}

void coo::grid::printMaze(const int& x, const int& y) const
{
	for (size_t i = 0; i < this->sizeY; ++i) {
		for (size_t j = 0; j < this->sizeX; ++j) {
			if (tiles[i][j]) {
				if (j == x && i == y) {
					std::cout << "X";
				}
				else {
					std::cout << " ";
				}
			}
			else {
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}
}

bool coo::grid::isAccessible(const int& x, const int& y) const
{
	return this->tiles[x][y];
}
