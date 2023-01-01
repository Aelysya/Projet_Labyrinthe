#pragma once
#include "player.h"

namespace coo {
	class stairPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra �tre prise par le joueur
		 */
		direction getNextDirection();
	public:
		/**
		 * Constructeur de rightPlayer.
		 *
		 * \param fileName Le nom du fichier dans lequel sera
		 * lu le labyrinthe o� le joueur sera plac�
		 */
		stairPlayer(const std::string& fileName);

		/**
		 * R�solution du labyrinthe
		 */
		void solve();
	};
}