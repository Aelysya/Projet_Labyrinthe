#include "solver.h"
#include "leftPlayer.h"
#include "rightPlayer.h"
#include "yoloPlayer.h"
#include "stairPlayer.h"
#include "Chrono.h"
#include "Logger.h"

using namespace players;

utility::solver::solver(const utility::grid& g)
{
	//Ajout des joueurs
	this->players.push_back(new leftPlayer(g));
	this->players.push_back(new rightPlayer(g));
	this->players.push_back(new yoloPlayer(g));
	this->players.push_back(new stairPlayer(g));
}

utility::solver::solver(const solver& s)
{
	for (player* p : s.players) {
		this->players.push_back(p);
	}
}

utility::solver::~solver()
{
	for (player* p : this->players) {
		delete p;
	}
}

utility::solver& utility::solver::operator=(const solver& s)
{
	if (this != &s) {
		for (player* p : this->players) {
			delete p;
		}
		for (player* p : s.players) {
			this->players.push_back(p);
		}
	}
	return *this;
}

void utility::solver::solve()
{
	Logger logger("logger", INFO, "stdout");
	Chrono c;
	std::vector<std::string> times;
	for (player* p : this->players) {
		//logger.info(typeid(p).name() + "solve :");
		c.launchChrono();
		p->solve();
		c.stopChrono();
		times.push_back("Temps de resolution: " + std::to_string(c.getElapsedTimeSeconds()) + "s et "+ std::to_string(p->getNumberOfSteps()) + " pas pour sortir du labyrinthe.");
	}
	for (int i = 0; i < this->players.size(); ++i) {
		logger.info(times.at(i));
	}
}