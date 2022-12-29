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
	grid g("lab3_3x3.txt");
	tracer t;
	player p(t);

	p + UP;
	p + RIGHT;

	p.printHistory();
}





