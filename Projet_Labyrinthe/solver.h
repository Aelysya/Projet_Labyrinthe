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
		 * R�solveur de labyrinthe
		 *
		 * \param g le labyrinthe � r�soudre
		 */
		solver(const grid& g);
		solver(const solver& s);
		~solver();
		solver& operator=(const solver& s);

		/**
		 * R�sout la grille avec diff�rentes heuristiques,
		 * les compare et d�termine le meilleur type de parcours
		 */
		void solve();
	};
}
