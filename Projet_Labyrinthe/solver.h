#pragma once
#include "player.h"
namespace utility {
	class solver
	{
		/**
		 * Le labyrinthe � r�soudre
		 */
		grid g;
		/**
		 * Les joueurs du labyrinthe
		 */
		std::vector<players::player*> playerlist;

	public:
		/**
		 * R�solveur de labyrinthe de case de largeur variable
		 *
		 * \param fileName nom du fichier texte � partir 
		 * dequel sera lu la structure du labyrinthe
		 * \param size la largeur des cases
		 */
		solver(const grid& g);

		solver(const solver& s);

		~solver();
		solver& operator= (const solver& s);

		/**
		 * R�sout la grille avec diff�rentes heuristiques,
		 * les compare et d�termine le meilleur type de parcours
		 */
		void solve();
	};
}
