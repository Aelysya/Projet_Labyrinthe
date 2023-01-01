#pragma once
#include "player.h"
namespace players {
	class yoloPlayer : public player
	{
	private:
		/**
		 * Renvoie la prochaine direction qui devra être prise par le joueur
		 */
		utility::direction getNextDirection();
	public:
		/**
		 * Constructeur de yoloPlayer.
		 *
		 * \param fileName Le nom du fichier dans lequel sera
		 * lu le labyrinthe où le joueur sera placé
		 */
		yoloPlayer(const std::string& fileName);

		/**
		 * Résolution du labyrinthe
		 */
		void solve();
	};
}