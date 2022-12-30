#include "grid.h"
#include <fstream>
#include <iostream>

coo::grid::grid(const std::string& fileName)
{
	int spacesize = 2;
	std::ifstream file(fileName);
	std::string line;
	//Lecture de la première ligne pour déterminer la taille du labyrinthe
	std::getline(file, line);

	//Détermination du nombre de colonnes
	this->size_x = 0;
	for (size_t j = 0; j < line.size(); j++) {
		if (j % 3 != 2) {
			this->size_x += 1;
		}
	}

	//Détermination du nombre de lignes
	this->size_y = 0;
	while (!file.eof()) {
		size_y++;
		std::getline(file, line);
	}

	//Retour au début du fichier
	file.clear();
	file.seekg(0);
	std::getline(file, line);

	//Transformation des caractères en booléens
	this->tiles = new bool*[this->size_y];
	for (size_t i = 0; i < size_y; ++i) {
		this->tiles[i] = new bool[size_x];
		int k = -1; //Décalement des colonnes
		if (i != 0 || i != size_y) {
			for (size_t j = 0; j < size_x; j++) {
				if (j % 2 == 0) {
					k++;
				}
				if (i == 0 || i == size_x-1 || j == 0 || j == size_y-1) {
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

coo::grid::grid(const grid& g) : size_x(g.size_x), size_y(g.size_y)
{
	this->tiles = new bool*[this->size_y];
	for (size_t i = 0; i < size_y; ++i)
	{
		this->tiles[i] = new bool[size_x];
		for (size_t j = 0; j < size_x; ++j)
		{
			this->tiles[i][j] = g.tiles[i][j];
		}
	}
}

coo::grid::~grid()
{
	for (size_t i = 0; i < this->size_y; ++i) {
		delete[] this->tiles[i];
	}
	delete[] this->tiles;
}

coo::grid& coo::grid::operator=(const grid& g)
{
	if (this != &g) {
		for (size_t i = 0; i < size_y; ++i) {
			delete[] this->tiles[i];
		}
		delete[] this->tiles;
		this->size_x = g.size_x;
		this->size_y = g.size_y;
		for (size_t i = 0; i < size_y; ++i)
		{
			this->tiles[i] = new bool[size_x];
			for (size_t j = 0; j < size_x; ++j)
			{
				this->tiles[i][j] = g.tiles[i][j];
			}
		}
	}
	return *this;
}

void coo::grid::printMaze(int posX, int posY) const
{
	for (size_t i = 0; i < size_y; ++i) {
		for (size_t j = 0; j < size_x; ++j) {
			if (tiles[i][j]) {
				if (j == posX && i == posY) {
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
	std::cout << std::endl;
}

int coo::grid::getSizeX() const 
{
	return this->size_x;
}
int coo::grid::getSizeY() const
{
	return this->size_y;
}

bool** coo::grid::getTiles() const
{
	return this->tiles;
}
