#pragma once
#include "player.h"
namespace players {
	class leftPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra être prise par le joueur
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur de leftPlayer.
		 *
		 * \param fileName Le nom du fichier dans lequel sera
		 * lu le labyrinthe où le joueur sera placé
		 */
		leftPlayer(const utility::grid& g);

		/**
		 * Résolution du labyrinthe
		 */
		int solve();
	};
}
