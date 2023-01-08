#pragma once
#include "direction.h"
#include "tracer.h"
#include "grid.h"
#include <string>

namespace players {
	class player
	{
		/**
		* Le nom du joueur
		*/
		std::string name;

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
		 * \return true si le joueur peut se d�placer dans la direction voulue
		 */
		bool operator+(const utility::direction& d) const;

		/**
		 * D�place le joueur dans la direction donn�e
		 * et ajoute le mouvement � l'historique.
		 *
		 * \param d La direction prise par le joueur
		 * \return true si le joueur a effectu� le d�placement
		 */
		bool operator+=(const utility::direction& d);
		
	public:
		/**
		 * Constructeur de joueur
		 *
		 * \param g le labyrinthe � parcourir
		 * \param x la largeur du labyrinthe
		 * \param y la longueur du labyrinthe
		 * \param name le nom du player
		 */
		player(const utility::grid& g, const int& x, const int& y, const std::string& name);


		/**
		 * Destructeur
		 */
		virtual ~player();

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

		/**
		 * Retourne le nom du player
		 *
		 * \return Le nom du player actuel
		 */
		std::string getName();
	};
}