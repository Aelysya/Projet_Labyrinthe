#pragma once
#include "player.h"
namespace players {
	class yoloPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra ?tre prise par le joueur
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur de yoloPlayer.
		 *
		 * \param fileName Le nom du fichier dans lequel sera
		 * lu le labyrinthe o? le joueur sera plac?
		 */
		yoloPlayer(const utility::grid& grid);

		/**
		 * R?solution du labyrinthe
		 */
		void solve();
	};
}