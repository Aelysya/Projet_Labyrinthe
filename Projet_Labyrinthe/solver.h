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
		 * Constructeur du solver de labyrinthe
		 *
		 * \param g le labyrinthe � r�soudre
		 */
		solver(const grid& g);

		/**
		 * Constructeur de recopie du labyrinthe
		 *
		 * \param s le solver � copier
		 */
		solver(const solver& s);

		/**
		 * Destructeur
		 */
		~solver();

		/**
		 * Op�rateur d'affectation
		 *
		 * \param s Le solver � affecter
		 */
		solver& operator= (const solver& s);

		/**
		 * R�sout la grille avec diff�rentes heuristiques,
		 * les compare et d�termine le meilleur type de parcours
		 */
		void solve();
	};
}
