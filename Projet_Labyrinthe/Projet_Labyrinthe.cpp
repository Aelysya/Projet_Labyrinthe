// Projet_Labyrinthe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "leftPlayer.h"
#include "rightPlayer.h"
#include "yoloplayer.h"
#include "solver.h"

using namespace coo;

int main()
{
	//1: Choix du fichier
	//saisie par l'utilisateur du nom du fichier au format .txt
	//traitement du std::string -> supprimer tout avant /, supprimer tout après . et remplacer par .txt
	
	//2: Traitement du fichier
	//todo: vérifier que fichier n'est pas vide 
	// + qu'il fait au moins 3x3 de large 
	// (position du joueur de départ = fin)
	//sinon -> step1

	//3: Résolution du labyrinthe
	//solver s("lab3_3x3.txt", 2);
	//4: Affichage du résultat
	//s.solve();
	
	//Tests autres
	//grid g("lab3_3x3.txt", 2);
	//g.printMaze(1,1);
	/*yoloPlayer p(g);

	p.printMaze();
	p.solve();
	p.printMaze();
	p.printHistory();*/

	leftPlayer lp("lab3_3x3.txt");
	rightPlayer rp("lab3_3x3.txt");
	yoloPlayer yp("lab3_3x3.txt");

	lp.solve();
	rp.solve();
	yp.solve();
}





