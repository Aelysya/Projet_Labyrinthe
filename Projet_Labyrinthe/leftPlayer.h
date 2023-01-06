#pragma once
#include "player.h"
namespace players {
	class leftPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra �tre prise par le joueur
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur de leftPlayer.
		 *
		 * \param fileName Le nom du fichier dans lequel sera
		 * lu le labyrinthe o� le joueur sera plac�
		 */
		leftPlayer(const utility::grid& g);

		/**
		 * R�solution du labyrinthe
		 */
		int solve();
	};
}
