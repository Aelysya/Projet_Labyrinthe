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
		 * R�sout la grille pour l'heuristique
		 *
		 * \param p La position du player dans la liste
		 * \return Le nombre de cases parcourues n�cessaire
		 * � la r�solution ou -1 si c'est impossible
		 */
		int solve(const int& p);

	public:
		/**
		 * R�solveur de labyrinthe de case de largeur variable
		 *
		 * \param fileName nom du fichier texte � partir 
		 * dequel sera lu la structure du labyrinthe
		 * \param size la largeur des cases
		 */
		solver(const std::string& filename);

		/**
		 * R�sout la grille avec diff�rentes heuristiques,
		 * les compare et d�termine le meilleur type de parcours
		 */
		void solve();
	};
}
