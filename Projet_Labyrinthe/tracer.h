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
		 * Constructeur d'historique de d�placement
		 *
		 * \param x la longueur du labyrinthe
		 * \param y la largeur du labyrinthe
		 */
		tracer();

		/**
		 * Constructeur par recopie
		 *
		 * \param t le tracer � recopier
		 */
		tracer(const tracer& t);

		/**
		 * D�constructeur
		 */
		~tracer();

		/**
		 * Op�rateur d'affectation
		 *
		 * \param t le tracer � affecter
		 */
		tracer& operator=(const tracer& t);

		/**
		 * Ajoute le dernier mouvement effectu�
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