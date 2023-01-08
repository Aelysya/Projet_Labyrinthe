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
		 * Le labyrinthe à résoudre.
		 */
		utility::grid maze;

		/**
		 * Vérifie que le déplacement voulant être effectué est possible.
		 *
		 * \param d La direction voulant être prise par le joueur
		 * \return true si le joueur peut se déplacer dans la direction voulue
		 */
		bool operator+(const utility::direction& d) const;

		/**
		 * Déplace le joueur dans la direction donnée
		 * et ajoute le mouvement à l'historique.
		 *
		 * \param d La direction prise par le joueur
		 * \return true si le joueur a effectué le déplacement
		 */
		bool operator+=(const utility::direction& d);
		
	public:
		/**
		 * Constructeur de joueur
		 *
		 * \param g le labyrinthe à parcourir
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

		/**
		 * Retourne le nom du player
		 *
		 * \return Le nom du player actuel
		 */
		std::string getName();
	};
}