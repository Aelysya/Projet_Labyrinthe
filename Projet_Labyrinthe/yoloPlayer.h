#pragma once
#include "player.h"
namespace players {
	class yoloPlayer : public player
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
		yoloPlayer(const utility::grid& g);

		/**
		 * Résolution du labyrinthe
		 */
		int solve();
	};
}