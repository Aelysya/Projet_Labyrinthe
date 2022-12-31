#include "solver.h"
#include "leftplayer.h"
#include "rightplayer.h"
#include "yoloplayer.h"

coo::solver::solver(const std::string& filename)
{
	//Ajout des joueurs
	coo::leftPlayer p1(filename);
	coo::rightPlayer p2(filename);
	coo::yoloPlayer p3(filename);
	//coo::stairsPlayer p4(g);
	//coo::customPlayer p5(g);
	this->players.push_back(&p1);
	this->players.push_back(&p2);
	this->players.push_back(&p3);
	//this->playerlist.push_back(coo::stairsPlayer(g));
	//this->playerlist.push_back(coo::customPlayer(g));
}

int coo::solver::solve(const int& p)
{
	for (player* p : players) {
		p->solve();
	}
	return 0;
}

void coo::solver::solve()
{
	for (player* p : players) {
		p->solve();
	}
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