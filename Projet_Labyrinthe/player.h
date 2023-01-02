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
		 * Le labyrinthe à résoudre.
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
		
	public:
		/**
		 * Constructeur de joueur
		 *
		 * \param g le labyrinthe à parcourir
		 */
		player(const grid& g, const int& x, const int& y);

		virtual ~player();

		/**
		 * Affiche l'historique des mouvements effectués.
		 */
		void printHistory() const;

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 */
		void printPosition() const;

		/**
		 * Résolution du labyrinthe
		 * 
		 * \return Le nombre de cases parcourues nécessaire
		 * à la résolution ou -1 si c'est impossible
		 */
		virtual int solve() = 0;
	};
}