#pragma once
#include "player.h"
namespace players {
	class leftIfNotForwardPlayer : public player
	{
		/**
		 * Tourne la direction actuelle dans le sens antihoraire
		 */
		void changeDirection();
	public:
		/**
		 * Constructeur du player
		 *
		 * \param g la grille � r�soudre
		 */
		leftIfNotForwardPlayer(const utility::grid& g);

		/**
		 * R�solution du labyrinthe
		 *
		 * \return Le nombre de cases parcourues n�cessaire
		 * � la r�solution ou -1 si c'est impossible
		 */
		int solve();
	};
}
