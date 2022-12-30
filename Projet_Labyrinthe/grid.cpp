#include "grid.h"
#include <fstream>
#include <iostream>

coo::grid::grid(const std::string& fileName)
{
	std::ifstream file(fileName);
	std::string line;
	//Lecture de la première ligne pour déterminer la taille du labyrinthe
	std::getline(file, line);

	//Détermination du nombre de colonnes
	this->size_x = line.size();

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
		for (size_t j = 0; j < size_x; ++j) {
			if (line[j] == ' ') {
				this->tiles[i][j] = true;
			}
			else {
				this->tiles[i][j] = false;
			}
		}
		std::getline(file, line);
	}

	//Fermeture du fichier
	file.close();
}

coo::grid::grid(const std::string& fileName, const int& spacesize)
{
	std::ifstream file(fileName);
	std::string line;
	//Lecture de la première ligne pour déterminer la taille du labyrinthe
	std::getline(file, line);

	//Détermination du nombre de colonnes
	this->size_x = 0;
	for (size_t i = 0; i < line.size(); i++) {
		std::cout << i << std::endl;
		this->size_x += 1;
		//On dit non aux cases non sollicités comme je refuse
		//les appels des gens que je connais pas
		if (line[i] == ' ') {
			i += spacesize - 1; //on a quand même compté un caractère
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
		for (size_t j = 0; j < size_x; ++j) {
			if (line[j] == ' ') {
				this->tiles[i][j] = true;
				j += spacesize - 1;
			}
			else {
				this->tiles[i][j] = false;
			}
		}
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
