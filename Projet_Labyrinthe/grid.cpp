#include "grid.h"
#include <fstream>
#include <iostream>

utility::grid::grid(const std::string& fileName, const int& size)
{
	//Lecture de la première ligne pour déterminer la taille du labyrinthe
	std::ifstream file(fileName);
	std::string line;
	std::getline(file, line);
	//Détermination du nombre de colonnes
	this->sizex = 0;
	for (size_t j = 0; j < line.size(); j++) {
		if (j % 3 != size) {
			this->sizex++;
		}
	}
	//Détermination du nombre de lignes
	this->sizey = 0;
	while (!file.eof()) {
		this->sizey++;
		std::getline(file, line);
	}
	//Retour au début du fichier
	file.clear();
	file.seekg(0);
	std::getline(file, line);

	//Transformation des caractères en booléens
	this->tiles = new bool*[this->sizey];
	for (size_t i = 0; i < this->sizey; ++i) {
		this->tiles[i] = new bool[this->sizex];
		int k = -1; //Décalage des colonnes
		if (i != 0 || i != this->sizey) {
			for (size_t j = 0; j < this->sizex; j++) {
				if (j % size == 0) {
					k++;
				}
				if (i == 0 || i == this->sizey-1 || j == 0 || j == this->sizey-1) {
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

utility::grid::grid(const grid& g) : sizex(g.sizex), sizey(g.sizey)
{
	this->tiles = new bool*[this->sizey];
	for (size_t i = 0; i < this->sizey; ++i)
	{
		this->tiles[i] = new bool[this->sizex];
		for (size_t j = 0; j < this->sizex; ++j)
		{
			this->tiles[i][j] = g.tiles[i][j];
		}
	}
}

utility::grid::~grid()
{
	for (size_t i = 0; i < this->sizey; ++i) {
		delete[] this->tiles[i];
	}
	delete[] this->tiles;
}

utility::grid& utility::grid::operator=(const grid& g)
{
	if (this != &g) {
		for (size_t i = 0; i < this->sizey; ++i) {
			delete[] this->tiles[i];
		}
		delete[] this->tiles;
		this->sizex = g.sizex;
		this->sizey = g.sizey;
		for (size_t i = 0; i < this->sizey; ++i)
		{
			this->tiles[i] = new bool[this->sizex];
			for (size_t j = 0; j < this->sizex; ++j)
			{
				this->tiles[i][j] = g.tiles[i][j];
			}
		}
	}
	return *this;
}

int utility::grid::getX() const
{
	return this->sizex;
}
int utility::grid::getY() const
{
	return this->sizey;
}

void utility::grid::printMaze(const int& x, const int& y) const
{
	for (size_t i = 0; i < this->sizey; ++i) {
		for (size_t j = 0; j < this->sizex; ++j) {
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
	std::cout << std::endl;
}

bool utility::grid::isAccessible(const int& x, const int& y) const
{
	return this->tiles[y][x];
}
