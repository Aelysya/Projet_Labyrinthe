#pragma once
#include "direction.h"
#include "tracer.h"
#include "grid.h"
#include "tile.h"
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

		/**
		 * Affiche l'historique des mouvements effectués.
		 * 
		 */
		void printHistory() const;

	private:
		/**
		 * La position horizontale du joueur.
		 */
		int positionX;


		/**
		 * La position verticale du joueur.
		 */
		int positionY;

		/**
		 * L'historique des mouvements du joueur.
		 */
		tracer moveHistory;
	};
}