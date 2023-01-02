#pragma once
#include "direction.h"
#include "tracer.h"
#include "grid.h"
#include <string>

namespace players {
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
		utility::tracer moveHistory;

		/*
		* La direction actuelle du joueur.
		*/
		utility::direction currentDirection;

		/**
		 * Le labyrinthe � r�soudre.
		 */
		utility::grid maze;

		/**
		 * V�rifie que le d�placement voulant �tre effectu� est possible.
		 *
		 * \param d La direction voulant �tre prise par le joueur
		 * \return Si le joueur peut se d�placer dans la direction voulue
		 */
		bool operator+(const utility::direction& d) const;

		/**
		 * D�place le joueur dans la direction donn�e
		 * et ajoute le mouvement � l'historique.
		 *
		 * \param d La direction prise par le joueur
		 */
		void operator+=(const utility::direction& d);

		/**
		 * Affiche le labyrinthe avec la position du joueur.
		 */
		void printPosition() const;

		/**
		 * Renvoie la prochaine direction qui devra �tre prise par le joueur
		 */
		virtual utility::direction getNextDirection() = 0;
	public:
		/**
		 * Constructeur de player.
		 * 
		 * \param fileName Le nom du fichier dans lequel sera 
		 * lu le labyrinthe o� le joueur sera plac�
		 */
		player(const utility::grid& grid);
		virtual ~player();
		/**
		 * Affiche l'historique des mouvements effectu�s.
		 */
		void printHistory() const;

		/**
		 * Getter pour le nombre de pas effectu�s.
		 * 
		 * \return Le nombre de pas effectu� pour sortir du labyrinthe
		 */
		int getNumberOfSteps() const;

		/**
		 * R�solution du labyrinthe
		 */
		virtual void solve() = 0;
	};
}