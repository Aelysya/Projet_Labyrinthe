#pragma once
#include <string>

namespace coo {
	class grid
	{
	public:
		/**
		 * Constructeur de labyrinthe de case de 2 de largeur (pourquoi?)
		 * 
		 * \param fileName nom du fichier texte dans 
		 * lequel sera lu la structure du labyrinthe
		 */
		grid(const std::string& fileName);
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