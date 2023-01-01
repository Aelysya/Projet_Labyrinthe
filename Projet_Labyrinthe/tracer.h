#pragma once
#include "direction.h"
#include <vector>
#include <string>

namespace coo {
	class tracer
	{
	private:
		/**
		 * L'historique des mouvements d'un joueur.
		 */
		std::vector<direction> moveHistory;
	public:
		/**
		 * Constructeur d'historique de déplacement
		 *
		 * \param x la longueur du labyrinthe
		 * \param y la largeur du labyrinthe
		 */
		tracer();

		/**
		 * Constructeur par recopie
		 *
		 * \param t le tracer à recopier
		 */
		tracer(const tracer& t);

		/**
		 * Déconstructeur
		 */
		~tracer();

		/**
		 * Opérateur d'affectation
		 *
		 * \param t le tracer à affecter
		 */
		tracer& operator=(const tracer& t);

		/**
		 * Ajoute le dernier mouvement effectué
		 * dans l'historique.
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalled actuelle
		 * \param d La direction choisie
		 */
		void addMove(const direction& d);

		/**
		 * Affiche l'historique des mouvements du joueur.
		 * 
		 */
		void printHistory() const;
	};
}