#pragma once
#include "player.h"
namespace players {
	class rightPlayer : public player 
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
		rightPlayer(const utility::grid& g);

		/**
		 * R�solution du labyrinthe
		 *
		 * \return Le nombre de cases parcourues n�cessaire
		 * � la r�solution ou -1 si c'est impossible
		 */
		int solve();
	};
}