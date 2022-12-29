// Projet_Labyrinthe.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "player.h"
#include "tracer.h"
#include "direction.h"
#include "grid.h"

using namespace coo;

int main()
{
	tracer t;
	player p1(t);

	p1 + UP;
	p1 + RIGHT;

	p1.printHistory();
}

/*

Taille du labyrinthe en cases
 -> (nb de # sur la première ligne + 2) / 3


*/





