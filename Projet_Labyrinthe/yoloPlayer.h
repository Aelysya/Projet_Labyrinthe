#pragma once
#include "player.h"
namespace players {
	class yoloPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra �tre prise par le joueur
		 *
		 * \return La prochaine direction
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur du player
		 *
		 * \param g la grille � r�soudre
		 */
		yoloPlayer(const utility::grid& g);

		/**
		 * R�solution du labyrinthe
		 */
		int solve();
	};
}