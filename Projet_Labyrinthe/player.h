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
		 */
		void operator+=(const direction& d);

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 */
		void printPosition() const;

		/**
		 * Renvoie la prochaine direction qui devra être prise par le joueur
		 */
		virtual direction getNextDirection() = 0;
	public:
		/**
		 * Constructeur de player.
		 * 
		 * \param fileName Le nom du fichier dans lequel sera 
		 * lu le labyrinthe où le joueur sera placé
		 */
		player(const std::string& fileName);

		/**
		 * Affiche l'historique des mouvements effectués.
		 */
		void printHistory() const;

		/**
		 * Résolution du labyrinthe
		 */
		virtual void solve() = 0;
	};
}