#pragma once
#include "player.h"
namespace coo {
	class solver
	{
		/**
		 * Les joueurs du labyrinthe
		 */
		std::vector<player*> players;
		
		/**
		 * Résout la grille pour l'heuristique
		 *
		 * \param p La position du player dans la liste
		 * \return Le nombre de cases parcourues nécessaire
		 * à la résolution ou -1 si c'est impossible
		 */
		int solve(const int& p);

	public:
		/**
		 * Résolveur de labyrinthe de case de largeur variable
		 *
		 * \param fileName nom du fichier texte à partir 
		 * dequel sera lu la structure du labyrinthe
		 * \param size la largeur des cases
		 */
		solver(const std::string& filename);

		/**
		 * Résout la grille avec différentes heuristiques,
		 * les compare et détermine le meilleur type de parcours
		 */
		void solve();
	};
}
