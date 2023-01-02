// Projet_Labyrinthe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <fstream>
#include "solver.h"
#include "grid.h"

using namespace coo;

int main()
{
	//1: Choix du fichier
	//saisie par l'utilisateur du nom du fichier au format .txt
	//traitement du std::string -> supprimer tout avant /, supprimer tout après . et remplacer par .txt
	bool fileNameOk = true;
	bool gridCorrect = false;
	std::string fileName;
	do {
		//2: Traitement du fichier
		//todo: vérifier que fichier n'est pas vide 
		// + qu'il fait au moins 3x3 de large 
		// (position du joueur de départ = fin)
		//sinon -> step1
		//std::cout << "Entrez le nom du fichier contenant le labyrinthe: " << std::endl;
		//std::getline(std::cin, fileName);
		//std::ifstream testOpen(fileName);
		//fileNameOk = testOpen.is_open();

		if (!fileNameOk) {
			std::cout << "Fichier invalide !" << std::endl;
		}
		
		else {
			grid g("lab3_3x3.txt", 2);
			gridCorrect = (g.getX() > 2 && g.getY() > 2) && (g.getX()%2 && g.getY()%2);

			if (gridCorrect) {
				g.printMaze(1, 1);
				//3: Résolution du labyrinthe et affichage du résultat
				solver s(g);
				s.solve();
			}
			else {
				std::cout << "Grille invalide !" << std::endl;
			}
		}
	} while (!fileNameOk || !gridCorrect);
}





