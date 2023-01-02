#pragma once
#include "player.h"
namespace utility {
	class solver
	{
		/**
		 * Les joueurs du labyrinthe
		 */
		std::vector<players::player*> players;

	public:
		/**
		 * Résolveur de labyrinthe
		 *
		 * \param g le labyrinthe à résoudre
		 */
		solver(const grid& g);
		solver(const solver& s);
		~solver();
		solver& operator=(const solver& s);

		/**
		 * Résout la grille avec différentes heuristiques,
		 * les compare et détermine le meilleur type de parcours
		 */
		void solve();
	};
}
