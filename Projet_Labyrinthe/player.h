#pragma once
#include "direction.h"
#include "tracer.h"
#include <string>

namespace coo {
	class player
	{
	public:
		player(const tracer& t);
		~player();

		/**
		 * Déplace le joueur dans la direction donnée
		 * et ajoute le mouvement à l'historique.
		 * 
		 * \param d La direction prise par le joueur
		 */
		void operator+(const direction& d);

		void printHistory() const;

	private:
		int positionX;
		int positionY;
		tracer moveHistory;
	};
}