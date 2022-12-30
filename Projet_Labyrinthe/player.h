#pragma once
#include "direction.h"
#include "tracer.h"
#include "grid.h"
#include <string>

namespace coo {
	class player
	{
	protected:
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

		/*
		* La direction actuelle du joueur.
		*/
		direction currentDirection;

		/**
		 * Le labyrinthe dans lequel se trouve le joueur.
		 */
		grid maze;

		/**
		 * Vérifie que le déplacement voulant être effectué est possible.
		 *
		 * \param d La direction voulant être prise par le joueur
		 * \return Si le joueur peut se déplacer dans la direction voulue
		 */
		bool operator+(const direction& d) const;

		/**
		 * Déplace le joueur dans la direction donnée
		 * et ajoute le mouvement à l'historique.
		 *
		 * \param d La direction prise par le joueur
		 * \return Si le joueur a effectué le déplacement
		 */
		bool operator+=(const direction& d);

		/**
		 * Change la direction du joueur
		 */
		virtual void changeDirection() = 0;
		
	public:
		player(const grid& g);

		/**
		 * Affiche l'historique des mouvements effectués.
		 */
		void printHistory() const;

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 */
		void printMaze() const;

		/**
		 * Résolution du labyrinthe
		 * 
		 * \return Si le joueur a trouvé la sortie
		 */
		virtual bool solve() = 0;
	};
}