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
		 */
		void operator+=(const direction& d);

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 */
		void printPosition() const;

		/**
		 * Renvoie la prochaine direction qui devra �tre prise par le joueur
		 */
		virtual direction getNextDirection() = 0;
	public:
		/**
		 * Constructeur de player.
		 * 
		 * \param fileName Le nom du fichier dans lequel sera 
		 * lu le labyrinthe o� le joueur sera plac�
		 */
		player(const std::string& fileName);

		/**
		 * Affiche l'historique des mouvements effectu�s.
		 */
		void printHistory() const;

		/**
		 * R�solution du labyrinthe
		 */
		virtual void solve() = 0;
	};
}