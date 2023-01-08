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
		 * Constructeur du solver de labyrinthe
		 *
		 * \param g le labyrinthe à résoudre
		 */
		solver(const grid& g);

		/**
		 * Constructeur de recopie du labyrinthe
		 *
		 * \param s le solver à copier
		 */
		solver(const solver& s);

		/**
		 * Destructeur
		 */
		~solver();

		/**
		 * Opérateur d'affectation
		 *
		 * \param s Le solver à affecter
		 */
		solver& operator= (const solver& s);

		/**
		 * Résout la grille avec différentes heuristiques,
		 * les compare et détermine le meilleur type de parcours
		 */
		void solve();
	};
}
