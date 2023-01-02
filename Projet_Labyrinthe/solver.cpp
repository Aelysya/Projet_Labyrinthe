#include "solver.h"
#include "leftPlayer.h"
#include "rightPlayer.h"
#include "yoloPlayer.h"
#include "stairPlayer.h"

using namespace players;

utility::solver::solver(const utility::grid& g)
{
	//Ajout des joueurs
	leftPlayer p1(g);
	rightPlayer p2(g);
	//yoloPlayer p3(g);
	stairPlayer p4(g);
	//players::customPlayer p5(g);
	this->players.push_back(&p1);
	this->players.push_back(&p2);
	//this->players.push_back(&p3);
	this->players.push_back(&p4);
	//this->players.push_back(&p5);
}

int utility::solver::solve(const int& p)
{
	for (player* p : players) {
		p->solve();
	}
	return 0;
}

void utility::solver::solve()
{
	/*int min = INT_MAX;
	int minSolver = -1;
	int currentMin = 0;
	//todo: compare execution time with chrono? optionnel
	for (int i = 0; i < players.size(); i++)
	{
		currentMin = solve(i);
		if (currentMin != -1 && currentMin < min) {
			min = currentMin;
			minSolver = i;
		}
	}*/
	//todo: display result
}