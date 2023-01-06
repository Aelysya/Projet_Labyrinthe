#pragma once
#include "player.h"

namespace players {
	class stairPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra être prise par le joueur
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur de rightPlayer.
		 *
		 * \param fileName Le nom du fichier dans lequel sera
		 * lu le labyrinthe où le joueur sera placé
		 */
		stairPlayer(const utility::grid& grid);

		/**
		 * Résolution du labyrinthe
		 */
		int solve();
	};
}