#pragma once
#include <string>

namespace utility {
	class grid
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
		 * Liste des cases du labyrinthe.
		 * Les cases ont comme valeur 'vrai' lorsque
		 * celles-ci correspondent � un chemin
		 * (false = mur)
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


		/**
		* Retourne le nombre de colonnes 
		* 
		* \return le nombre de colonnes
		*/
		int getX() const;

		/**
		* Retourne le nombre de lignes
		*
		* \return le nombre de lignes
		*/
		int getY() const;

		/**
		 * Affiche une position dans le labyrinthe
		 * 
		 * \param x Position horizontale
		 * \param y Position verticale
		 */
		void printMaze(const int& x, const int& y) const;

		/**
		 * Retourne l'�tat de la case (d�placement possible ou non)
		 * 
		 * \param x Position horizontale de la case
		 * \param y Position verticale de la case
		 * \return true si la case n'est pas un mur
		 */
		bool isAccessible(const int& x, const int& y) const;
	};
}