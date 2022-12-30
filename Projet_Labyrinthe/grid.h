#pragma once
#include <string>

namespace coo {
	class grid
	{
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
	public:
		/**
		 * Constructeur de labyrinthe de case de 2 de largeur (pourquoi?)
		 * 
		 * \param fileName nom du fichier texte dans 
		 * lequel sera lu la structure du labyrinthe
		 */
		grid(const std::string& fileName);
		grid(const grid& g);
		~grid();
		grid& operator=(const grid& g);

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 * 
		 * \param posX Position horizontale du joueur
		 * \param posY Position verticale du joueur
		 */
		void printMaze(int posX, int posY) const;

		/**
		 * .
		 * 
		 * \return La liste des cases du labyrinthe
		 */
		bool** getTiles() const;
	};
}