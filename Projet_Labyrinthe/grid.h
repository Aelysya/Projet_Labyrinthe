#pragma once
#include <string>

namespace coo {
	class grid
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
		 * Liste des cases du labyrinthe.
		 * Les cases ont comme valeur 'vrai' lorsque
		 * celles-ci correspondent à un chemin
		 * (false = mur)
		 */
		bool** tiles;

	public:
		/**
		 * Constructeur de labyrinthe de case à largeur variable
		 * 
		 * \param fileName nom du fichier texte à partir 
		 * dequel sera lu la structure du labyrinthe
		 * \param size la largeur des cases
		 */
		grid(const std::string& fileName, const int& size);

		/**
		 * Constructeur de recopie du labyrinthe
		 *
		 * \param g Le labyrinthe à recopier
		 */
		grid(const grid& g);

		/**
		 * Destructeur
		 */
		~grid();

		/**
		 * Opérateur d'affectation
		 * 
		 * \param g Le labyrinthe à affecter
		 */
		grid& operator=(const grid& g);

		int getX() const;
		int getY() const;

		/**
		 * Affiche une position dans le labyrinthe
		 * 
		 * \param posX Position horizontale
		 * \param posY Position verticale
		 */
		void printMaze(const int& x, const int& y) const;

		/**
		 * Retourne l'état de la case (déplacement possible ou non)
		 * 
		 * \return true si la case n'est pas un mur
		 */
		bool isAccessible(const int& x, const int& y) const;
	};
}