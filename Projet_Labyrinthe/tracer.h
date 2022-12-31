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
		 * Listes des cases visit�s
		 * (true pour case visit�)
		 */
		bool** seenTiles;

		/**
		 * Listes des cases n'�tant pas/plus visitables
		 * (false pour case bloqu�e)
		 */
		bool** blockedTiles;

		/**
		 * Nombre de mouvements r�alis�s
		 */
		int moveAmount;
	public:
		/**
		 * Constructeur d'historique de d�placement
		 *
		 * \param x la longueur du labyrinthe
		 * \param y la largeur du labyrinthe
		 */
		tracer(const int& x, const int& y);

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
		void addMove(const int& x, const int& y, const direction& d);

		/**
		 * Retourne l'�tat de la case (d�placement possible ou non)
		 *
		 * \return true si la case n'a pas compl�tement �t� explor�e
		 */
		bool isAccessible(const int& x, const int& y) const;
	};
}