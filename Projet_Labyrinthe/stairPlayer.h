#pragma once
#include "player.h"

namespace players {
	class stairPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra �tre prise par le joueur
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur de rightPlayer.
		 *
		 * \param fileName Le nom du fichier dans lequel sera
		 * lu le labyrinthe o� le joueur sera plac�
		 */
		stairPlayer(const utility::grid& grid);

		/**
		 * R�solution du labyrinthe
		 */
		int solve();
	};
}