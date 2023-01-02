#include "solver.h"
#include "leftplayer.h"
#include "rightplayer.h"
#include "yoloplayer.h"

using namespace players;

utility::solver::solver(const std::string& filename)
{
	//Ajout des joueurs
	//leftPlayer p1(filename);
	//rightPlayer p2(filename);
	//yoloPlayer p3(filename);
	//players::stairsPlayer p4(g);
	//players::customPlayer p5(g);
	//this->players.push_back(&p1);
	//this->players.push_back(&p2);
	//this->players.push_back(&p3);
	//this->playerlist.push_back(players::stairsPlayer(g));
	//this->playerlist.push_back(players::customPlayer(g));
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