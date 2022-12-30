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
		 * V�rifie que le d�placement voulant �tre effectu� est possible.
		 *
		 * \param d La direction voulant �tre prise par le joueur
		 * \return Si le joueur peut se d�placer dans la direction voulue
		 */
		bool operator+(const direction& d) const;

		/**
		 * D�place le joueur dans la direction donn�e
		 * et ajoute le mouvement � l'historique.
		 *
		 * \param d La direction prise par le joueur
		 * \return Si le joueur a effectu� le d�placement
		 */
		bool operator+=(const direction& d);

		/**
		 * Change la direction du joueur
		 */
		virtual void changeDirection() = 0;
		
	public:
		player(const grid& g);

		/**
		 * Affiche l'historique des mouvements effectu�s.
		 */
		void printHistory() const;

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 */
		void printMaze() const;

		/**
		 * R�solution du labyrinthe
		 * 
		 * \return Si le joueur a trouv� la sortie
		 */
		virtual bool solve() = 0;
	};
}