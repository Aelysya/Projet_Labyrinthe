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
	this->tiles = new bool* [this->size_y];
	for (size_t i = 0; i < size_y; ++i) {
		this->tiles[i] = new bool[size_x];
		int k = -1;
		for (size_t j = 0; j < size_x; j++) {
			if (j % 2 == 0) {
				k++;
			}
			std::cout << j + k;
			if (line[j + k] == ' ') {
				this->tiles[i][j] = true;
			}
			else {
				this->tiles[i][j] = false;
			}
			
		}
		std::cout << std::endl;
		std::getline(file, line);
	}
	//Fermeture du fichier
	file.close();
}

coo::grid::~grid()
{
	for (size_t i = 0; i < this->size_y; ++i) {
		delete[] this->tiles[i];
	}
	delete[] this->tiles;
}

void coo::grid::printMaze() const
{
	for (size_t i = 0; i < size_y; ++i) {
		for (size_t j = 0; j < size_x; ++j) {
			if (tiles[i][j]) {
				std::cout << " ";
			}
			else {
				std::cout << "#";
			}
		}
		std::cout << std::endl;
	}
}
