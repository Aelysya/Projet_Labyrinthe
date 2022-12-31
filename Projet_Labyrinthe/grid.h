#pragma once
#include <string>
#include "tracer.h"

namespace coo {
	class grid
	{
		/**
		 * Nombre de lignes du labyrinthe.
		 */
		int sizeX;
		/**
		 * Nombre de colonnes du labyrinthe.
		 */
		int sizeY;

		/**
		 * Liste des cases du labyrinthe.
		 * Les cases ont comme valeur 'vrai' lorsque
		 * celles-ci correspondent � un chemin et 'false'
		 * lorsqu'elle correspondent � un mur.
		 */
		bool** tiles;

	public:
		/**
		 * Constructeur de labyrinthe de case � largeur variable
		 * 
		 * \param fileName nom du fichier texte � partir 
		 * dequel sera lu la structure du labyrinthe
		 * \param size la largeur des cases
		 */
		grid(const std::string& fileName, const int& size);

		/**
		 * Constructeur de recopie du labyrinthe
		 *
		 * \param g Le labyrinthe � recopier
		 */
		grid(const grid& g);

		/**
		 * Destructeur
		 */
		~grid();

		/**
		 * Op�rateur d'affectation
		 * 
		 * \param g Le labyrinthe � affecter
		 */
		grid& operator=(const grid& g);

		int getSizeX() const;
		int getSizeY() const;

		/**
		 * Affiche une position dans le labyrinthe
		 * 
		 * \param posX Position horizontale
		 * \param posY Position verticale
		 */
		void printMaze(const int& x, const int& y) const;

		/**
		 * Retourne l'�tat de la case (d�placement possible ou non)
		 * 
		 * \return true si la case n'est pas un mur
		 */
		bool isAccessible(const int& x, const int& y) const;
	};
}