// Projet_Labyrinthe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include "solver.h"
#include "grid.h"

using namespace utility;

int main()
{
	//1: Choix du fichier
	bool fileNameOk = false;
	bool gridCorrect = false;
	std::string fileName;
	do {
		//2: Traitement du fichier
		std::cout << "Entrez le nom du fichier contenant le labyrinthe: " << std::endl;
		std::getline(std::cin, fileName);
		std::ifstream testOpen(fileName);
		fileNameOk = testOpen.is_open();

		if (!fileNameOk) {
			std::cout << "Fichier invalide !" << std::endl;
		}
		
		else {
			grid g(fileName, 2);
			//Vérification que le labyrinthe est correctement écrit dans le fichier
			gridCorrect = (g.getX() > 2 && g.getY() > 2) && (g.getX()%2 && g.getY()%2);

			if (gridCorrect) {
				g.printMaze(1, 1);
				//3: Résolution du labyrinthe et affichage du résultat pour chaque heuristique
				solver s(g);
				s.solve();
			}
			else {
				std::cout << "Grille invalide !" << std::endl;
			}
		}
	} while (!fileNameOk || !gridCorrect);
}





