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
		 * Ajoute le dernier mouvement effectu� par le 
		 * joueur dans l'historique.
		 * 
		 * \param d La direction prise par le joueur
		 */
		void addMove(const direction& d);

	private:
		/**
		 * Ce vecteur contient une liste de direction qui 
		 * est l'historique des d�placements du joueur.
		 */
		std::vector<direction> moveHistory;
	};
}