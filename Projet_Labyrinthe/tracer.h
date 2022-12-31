#pragma once
#include "direction.h"
#include <vector>
#include <string>

namespace coo {
	class tracer
	{
		/**
		 * Nombre de lignes du labyrinthe.
		 */
		int sizex;
		/**
		 * Nombre de colonnes du labyrinthe.
		 */
		int sizey;

		/**
		 * Listes des cases visités
		 * (true pour case visité)
		 */
		bool** seenTiles;

		/**
		 * Listes des cases n'étant pas/plus visitables
		 * (false pour case bloquée)
		 */
		bool** blockedTiles;

		/**
		 * Nombre de mouvements réalisés
		 */
		int moveAmount;
	public:
		/**
		 * Constructeur d'historique de déplacement
		 *
		 * \param x la longueur du labyrinthe
		 * \param y la largeur du labyrinthe
		 */
		tracer(const int& x, const int& y);

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
		void addMove(const int& x, const int& y, const direction& d);

		/**
		 * Retourne l'état de la case (déplacement possible ou non)
		 *
		 * \return true si la case n'a pas complètement été explorée
		 */
		bool isAccessible(const int& x, const int& y) const;
	};
}