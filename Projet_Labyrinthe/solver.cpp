#include "solver.h"
#include "leftplayer.h"
#include "rightplayer.h"
#include "yoloplayer.h"

coo::solver::solver(const std::string& filename, const int& size) : g(filename, size)
{
	//Ajout des joueurs
	coo::leftPlayer p1(g);
	coo::rightPlayer p2(g);
	coo::yoloPlayer p3(g);
	//coo::stairsPlayer p4(g);
	//coo::customPlayer p5(g);
	this->playerlist.push_back(&p1);
	this->playerlist.push_back(&p2);
	this->playerlist.push_back(&p3);
	//this->playerlist.push_back(coo::stairsPlayer(g));
	//this->playerlist.push_back(coo::customPlayer(g));
}

int coo::solver::solve(const int& p)
{
	//todo
	player* e = playerlist[p];
	e->solve();
	return -1;
}

void coo::solver::solve()
{
	int min = INT_MAX;
	int minSolver = -1;
	int currentMin = 0;
	//todo: compare execution time with chrono? optionnel
	for (int i = 0; i < playerlist.size(); i++)
	{
		currentMin = solve(i);
		if (currentMin != -1 && currentMin < min) {
			min = currentMin;
			minSolver = i;
		}
	}
	//todo: display result
}
