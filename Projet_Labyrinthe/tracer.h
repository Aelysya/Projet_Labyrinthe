#pragma once
#include "direction.h"
#include <vector>

namespace coo {
	class tracer
	{
	public:
		tracer();
		~tracer();

		/**
		 * Ajoute le dernier mouvement effectué par le 
		 * joueur dans l'historique.
		 * 
		 * \param d La direction prise par le joueur
		 */
		void addMove(const direction& d);

	private:
		/**
		 * Ce vecteur contient une liste de direction qui 
		 * est l'historique des déplacements du joueur.
		 */
		std::vector<direction> moveHistory;
	};
}