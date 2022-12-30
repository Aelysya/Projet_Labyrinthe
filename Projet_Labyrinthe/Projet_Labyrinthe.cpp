// Projet_Labyrinthe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "leftplayer.h"
#include "tracer.h"
#include "direction.h"
#include "grid.h"

using namespace coo;

int main()
{
	//1: Choix du fichier

	//2: Traitement du fichier

	//3: Résolution du labyrinthe

	//4: Affichage du résultat


	//Tests
	//Création d'une grille, 
	grid g("lab3_3x3.txt");
	leftPlayer p(g);

	p.printMaze();
	p += RIGHT;
	p.printMaze();
	p += DOWN;
	p.printMaze();
	p += DOWN;
	p.printMaze();
	p += RIGHT;
	p.printMaze();

	p.printHistory();
}





