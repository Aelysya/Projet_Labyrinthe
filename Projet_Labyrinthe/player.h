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
		int x;

		/**
		 * La position verticale du joueur.
		 */
		int y;

		/**
		 * L'historique des mouvements du joueur.
		 */
		tracer moveHistory;

		/*
		* La direction actuelle du joueur.
		*/
		direction currentDirection;

		/**
		 * Le labyrinthe � r�soudre.
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
		
	public:
		/**
		 * Constructeur de joueur
		 *
		 * \param g le labyrinthe � parcourir
		 */
		player(const grid& g, const int& x, const int& y);

		/**
		 * Affiche l'historique des mouvements effectu�s.
		 */
		void printHistory() const;

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 */
		void printPosition() const;

		/**
		 * R�solution du labyrinthe
		 * 
		 * \return Le nombre de cases parcourues n�cessaire
		 * � la r�solution ou -1 si c'est impossible
		 */
		virtual int solve() = 0;
	};
}