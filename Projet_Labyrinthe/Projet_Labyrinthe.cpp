#include <iostream>
#include <fstream>
#include "grid.h"
#include "leftPlayer.h"
#include "rightPlayer.h"
#include "yoloPlayer.h"
#include "stairPlayer.h"
#include "Chrono.h"
#include "Logger.h"

using namespace players;
using namespace utility;

int main()
{
	bool fileNameOk;
	std::string fileName;
	do {
		std::cout << "Entrez le nom du fichier contenant le labyrinthe: " << std::endl;
		std::getline(std::cin, fileName);
		std::ifstream testOpen(fileName);
		fileNameOk = testOpen.is_open();

		if (!fileNameOk) {
			std::cout << "Fichier invalide !" << std::endl;
		}
	} while (!fileNameOk);

	Logger logger("logger", INFO, "stdout");
	grid g(fileName, 2);
	if (!(g.getSizeX() % 2 || g.getSizeY() % 2)) {
		std::cout << "La grille est de taille invalide, vérifier le fichier." << std::endl;
		exit(-1);
	}

	//leftPlayer
	leftPlayer lp(g);
	logger.info("leftPlayer solve :");
	Chrono chronoLeftPlayer;

	chronoLeftPlayer.launchChrono();
	lp.solve();
	chronoLeftPlayer.stopChrono();
	//lp.printHistory();
	
	//rightPlayer
	rightPlayer rp(g);
	logger.info("rightPlayer solve :");
	Chrono chronoRightPlayer;

	chronoRightPlayer.launchChrono();
	rp.solve();
	chronoRightPlayer.stopChrono();
	//rp.printHistory();


	//yoloPlayer
	yoloPlayer yp(g);
	logger.info("yoloPlayer solve :");
	Chrono chronoYoloPlayer;

	chronoYoloPlayer.launchChrono();
	yp.solve();
	chronoYoloPlayer.stopChrono();
	//yp.printHistory();


	//stairPlayer
	stairPlayer sp(g);
	logger.info("stairPlayer solve :");
	Chrono chronoStairPlayer;

	chronoStairPlayer.launchChrono();
	sp.solve();
	chronoStairPlayer.stopChrono();
	//sp.printHistory();

	logger.info("Fin des resolutions.");

	//Affichage des temps de résolution
	logger.info("Temps de resolution leftPlayer: " + std::to_string(chronoLeftPlayer.getElapsedTimeSeconds()) + "s");
	logger.info("leftPlayer a pris " + std::to_string(lp.getNumberOfSteps()) + " pas pour sortir du labyrinthe");
	logger.info("Temps de resolution rightPlayer: " + std::to_string(chronoRightPlayer.getElapsedTimeSeconds()) + "s");
	logger.info("rightPlayer a pris " + std::to_string(rp.getNumberOfSteps()) + " pas pour sortir du labyrinthe");
	logger.info("Temps de resolution yoloPlayer: " + std::to_string(chronoYoloPlayer.getElapsedTimeSeconds()) + "s");
	logger.info("yoloPlayer a pris " + std::to_string(yp.getNumberOfSteps()) + " pas pour sortir du labyrinthe");
	logger.info("Temps de resolution stairPlayer: " + std::to_string(chronoStairPlayer.getElapsedTimeSeconds()) + "s");
	logger.info("stairPlayer a pris " + std::to_string(sp.getNumberOfSteps()) + " pas pour sortir du labyrinthe");

}





