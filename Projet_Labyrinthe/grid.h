#pragma once
#include "tile.h"
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
		~grid();


	private:
		/**
		 * Nombre de cases sur les côtés du labyrinthe.
		 */
		int size;

		/**
		 * Liste des cases du labyrinthe.
		 */
		tile** tiles;
	};
}

