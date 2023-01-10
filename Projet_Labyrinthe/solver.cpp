#include "solver.h"
#include "leftIfNotForwardPlayer.h"
#include "rightIfNotForwardPlayer.h"
#include "leftPlayer.h"
#include "rightPlayer.h"
#include "yoloPlayer.h"
#include "stairPlayer.h"
#include "Logger.h"
#include "Chrono.h"

utility::solver::solver(const utility::grid& g) : g(g)
{
	playerlist.push_back(new players::leftIfNotForwardPlayer(this->g));
	playerlist.push_back(new players::rightIfNotForwardPlayer(this->g));
	playerlist.push_back(new players::leftPlayer(this->g));
	playerlist.push_back(new players::rightPlayer(this->g));
	playerlist.push_back(new players::yoloPlayer(this->g));
	playerlist.push_back(new players::stairPlayer(this->g));
}

utility::solver::solver(const utility::solver& s) : g(s.g)
{
	playerlist.push_back(new players::leftIfNotForwardPlayer(this->g));
	playerlist.push_back(new players::rightIfNotForwardPlayer(this->g));
	playerlist.push_back(new players::leftPlayer(this->g));
	playerlist.push_back(new players::rightPlayer(this->g));
	playerlist.push_back(new players::yoloPlayer(this->g));
	playerlist.push_back(new players::stairPlayer(this->g));
}

utility::solver::~solver()
{
	for (players::player* p : this->playerlist) {
		delete p;
	}
	this->playerlist.clear();
}

utility::solver& utility::solver::operator=(const solver& s)
{
	if (this != &s) {
		this->g = s.g;
		for (players::player* p : this->playerlist) {
			delete p;
		}
		this->playerlist.clear();
		playerlist.push_back(new players::leftIfNotForwardPlayer(this->g));
		playerlist.push_back(new players::rightIfNotForwardPlayer(this->g));
		playerlist.push_back(new players::leftPlayer(this->g));
		playerlist.push_back(new players::rightPlayer(this->g));
		playerlist.push_back(new players::yoloPlayer(this->g));
		playerlist.push_back(new players::stairPlayer(this->g));
	}
	return *this;
}

void utility::solver::solve()
{
	Logger logger("logger", INFO, "stdout");
	Chrono c;
	std::string minMPlayer = "";
	std::string minMTime = "";
	int minM = INT_MAX;
	int currentMinM = 0;
	//todo: compare execution time with chrono? optionnel
	for (players::player* p : this->playerlist) {
		c.launchChrono();
		currentMinM = p->solve();
		c.stopChrono();
		if (currentMinM != -1) {
			logger.info("Temps de resolution de " + p->getName() + " : " 
				+ std::to_string(c.getElapsedTimeSeconds()) + "s et " 
				+ std::to_string(currentMinM) + " pas pour sortir du labyrinthe.\n");
			if (currentMinM < minM) {
				minM = currentMinM;
				minMPlayer = p->getName();
				minMTime = std::to_string(c.getElapsedTimeSeconds());
			}
		}
		else {
			logger.info("Echec de la resolution de " + p->getName() + "\n");
		}
	}
	logger.info("Le player traversant le labyrinthe avec le moins de deplacements est " + minMPlayer + " avec " + std::to_string(minM) + " pas en " + minMTime + "s.");
	//todo: display result
}
