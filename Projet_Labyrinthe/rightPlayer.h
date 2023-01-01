#pragma once
#include "player.h"
namespace players {
	class rightPlayer : public player 
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
		rightPlayer(const std::string& fileName);

		/**
		 * R�solution du labyrinthe
		 */
		void solve();
	};
}