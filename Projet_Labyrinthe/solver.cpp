#include "solver.h"
#include "leftIfNotForwardPlayer.h"

coo::solver::solver(const coo::grid& g) : g(g)
{
	playerlist.push_back(new coo::leftIfNotForwardPlayer(this->g));
}

coo::solver::solver(const coo::solver& s) : g(s.g)
{
	playerlist.push_back(new coo::leftIfNotForwardPlayer(this->g));
}

coo::solver::~solver()
{
	for (player* p : this->playerlist) {
		delete p;
	}
	this->playerlist.clear();
}

coo::solver& coo::solver::operator=(const solver& s)
{
	if (this != &s) {
		this->g = s.g;
		for (player* p : this->playerlist) {
			delete p;
		}
		this->playerlist.clear();
		playerlist.push_back(new coo::leftIfNotForwardPlayer(this->g));
	}
	return *this;
}

void coo::solver::solve()
{
//	//Ajout des joueurs
//	coo::leftPlayer p1(g);
//	//coo::rightPlayer p2(g);
//	//coo::yoloPlayer p3(g);
//	//coo::stairsPlayer p4(g);
//	//coo::customPlayer p5(g);
//	this->playerlist.push_back(&p1);
//	//this->playerlist.push_back(&p2);
//	//this->playerlist.push_back(&p3);
//	//this->playerlist.push_back(coo::stairsPlayer(g));
//	//this->playerlist.push_back(coo::customPlayer(g));

	int min = INT_MAX;
	int currentMin = 0;
	//todo: compare execution time with chrono? optionnel
	for (player* p : this->playerlist) {
		currentMin = p->solve();
		if (currentMin != -1 && currentMin < min) {
			min = currentMin;
		}
	}
	//todo: display result
}
