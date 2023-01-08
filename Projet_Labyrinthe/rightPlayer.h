#pragma once
#include "player.h"
namespace players {
	class rightPlayer : public player 
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra être prise par le joueur
		 *
		 * \return La prochaine direction
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur du player
		 *
		 * \param g la grille à résoudre
		 */
		rightPlayer(const utility::grid& g);

		/**
		 * Résolution du labyrinthe
		 *
		 * \return Le nombre de cases parcourues nécessaire
		 * à la résolution ou -1 si c'est impossible
		 */
		int solve();
	};
}