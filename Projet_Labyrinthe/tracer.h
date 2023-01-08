#pragma once
#include "direction.h"
#include <vector>
#include <string>
#include "grid.h"

namespace utility {
	class tracer
	{
		/**
		 * Nombre de colonnes du labyrinthe.
		 */
		int sizex;

		/**
		 * Nombre de lignes du labyrinthe.
		 */
		int sizey;

		/**
		 * Listes des derni�res directions prises pour chaque case
		 * (NONE pour une case pas visit�e)
		 */
		direction** seenTiles;

		/**
		 * Listes des cases n'�tant pas/plus visitables
		 * (false pour case bloqu�e)
		 */
		bool** blockedTiles;

		/**
		 * Nombre de mouvements r�alis�s
		 */
		int moves;
	public:
		/**
		 * Constructeur d'historique de d�placement
		 *
		 * \param x la largeur du labyrinthe
		 * \param y la hauteur du labyrinthe
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
		 * Retourne le nombre de mouvements effectu�s
		 * 
		 * \return le nombre de mouvements effectu�s
		 */
		int getMoves();

		/**
		 * Ajoute le dernier mouvement effectu�
		 * dans l'historique.
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \param d La direction choisie
		 */
		void addMove(const int& x, const int& y, const direction& d);

		/**
		 * V�rifie si la position actuelle doit �tre bloqu�e
		 * et la bloque si les cases autour de la case actuelle,
		 * excluant celle dans la direction indiqu�e 
		 * (o� un d�placement est possible)
		 * sont soit des murs ou d'autres cases bloqu�es.
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \param d La direction choisie
		 * \param g le labyrinthe
		 */
		void checkBlocked(const int& x, const int& y, const direction& d, const grid& g);

		/**
		 * Retourne l'�tat de la case (case d�j� vue ou non)
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \return la direction dans laquelle la case a d�j� �t� vue 
		 * (NONE si jamais vue)
		 */
		direction& isSeen(const int& x, const int& y) const;

		/**
		 * Retourne l'�tat de la case (d�placement possible ou non)
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \return true si la case n'a pas compl�tement �t� explor�e
		 */
		bool isAccessible(const int& x, const int& y) const;
	};
}