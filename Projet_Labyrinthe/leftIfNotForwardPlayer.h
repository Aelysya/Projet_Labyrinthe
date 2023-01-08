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
		 * \param g la grille à résoudre
		 */
		leftIfNotForwardPlayer(const utility::grid& g);

		/**
		 * Résolution du labyrinthe
		 *
		 * \return Le nombre de cases parcourues nécessaire
		 * à la résolution ou -1 si c'est impossible
		 */
		int solve();
	};
}
