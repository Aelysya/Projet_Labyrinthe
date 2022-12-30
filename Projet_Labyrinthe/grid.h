#pragma once
#include <string>

namespace coo {
	class grid
	{
	public:
		/**
		 * Constructeur de labyrinthe.
		 * 
		 * \param fileName nom du fichier texte dans 
		 * lequel sera lu la structure du labyrinthe
		 */
		grid(const std::string& fileName);
		/**
		 * Constructeur de labyrinthe pour espaces à plusieurs caractères
		 *
		 * \param spacesize le nombre d'espaces composant
		 * une case du labyrinthe
		 */
		grid(const std::string& fileName, const int& spacesize);
		~grid();
		void printMaze() const;

	private:
		/**
		 * Nombre de lignes du labyrinthe.
		 */
		int size_x;

		/**
		 * Nombre de colonnes dans la dernière ligne du labyrinthe.
		 */
		int size_y;

		/**
		 * Liste des cases du labyrinthe.
		 */
		bool** tiles;
	};
}