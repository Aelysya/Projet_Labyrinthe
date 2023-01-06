#pragma once
#include "player.h"
namespace utility {
	class solver
	{
		/**
		 * Le labyrinthe à résoudre
		 */
		grid g;
		/**
		 * Les joueurs du labyrinthe
		 */
		std::vector<players::player*> playerlist;

	public:
		/**
		 * Résolveur de labyrinthe de case de largeur variable
		 *
		 * \param fileName nom du fichier texte à partir 
		 * dequel sera lu la structure du labyrinthe
		 * \param size la largeur des cases
		 */
		solver(const grid& g);

		solver(const solver& s);

		~solver();
		solver& operator= (const solver& s);

		/**
		 * Résout la grille avec différentes heuristiques,
		 * les compare et détermine le meilleur type de parcours
		 */
		void solve();
	};
}
