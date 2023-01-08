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
		 * Listes des dernières directions prises pour chaque case
		 * (NONE pour une case pas visitée)
		 */
		direction** seenTiles;

		/**
		 * Listes des cases n'étant pas/plus visitables
		 * (false pour case bloquée)
		 */
		bool** blockedTiles;

		/**
		 * Nombre de mouvements réalisés
		 */
		int moves;
	public:
		/**
		 * Constructeur d'historique de déplacement
		 *
		 * \param x la largeur du labyrinthe
		 * \param y la hauteur du labyrinthe
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
		 * Retourne le nombre de mouvements effectués
		 * 
		 * \return le nombre de mouvements effectués
		 */
		int getMoves();

		/**
		 * Ajoute le dernier mouvement effectué
		 * dans l'historique.
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \param d La direction choisie
		 */
		void addMove(const int& x, const int& y, const direction& d);

		/**
		 * Vérifie si la position actuelle doit être bloquée
		 * et la bloque si les cases autour de la case actuelle,
		 * excluant celle dans la direction indiquée 
		 * (où un déplacement est possible)
		 * sont soit des murs ou d'autres cases bloquées.
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \param d La direction choisie
		 * \param g le labyrinthe
		 */
		void checkBlocked(const int& x, const int& y, const direction& d, const grid& g);

		/**
		 * Retourne l'état de la case (case déjà vue ou non)
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \return la direction dans laquelle la case a déjà été vue 
		 * (NONE si jamais vue)
		 */
		direction& isSeen(const int& x, const int& y) const;

		/**
		 * Retourne l'état de la case (déplacement possible ou non)
		 *
		 * \param x La position horizontale actuelle
		 * \param y La position verticalle actuelle
		 * \return true si la case n'a pas complètement été explorée
		 */
		bool isAccessible(const int& x, const int& y) const;
	};
}