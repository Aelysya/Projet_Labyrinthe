#pragma once
#include "direction.h"
#include <vector>
#include <string>

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

		/**
		 * Affiche l'historique des mouvements 
		 * du joueur sur la sortie principale.
		 * 
		 */
		void printHistory() const;

	private:
		/**
		 * Ce vecteur contient une liste de direction qui 
		 * est l'historique des déplacements du joueur.
		 */
		std::vector<direction> moveHistory;

		/**
		 * Converti une direction énumération en string.
		 * 
		 * \param d La direction à convertir
		 * \return Un string avec le nom de la direction
		 */
		const std::string directionToString(const direction& d) const;
	};
}