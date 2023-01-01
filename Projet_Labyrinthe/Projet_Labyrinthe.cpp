#include <iostream>
#include <fstream>
#include "leftPlayer.h"
#include "rightPlayer.h"
#include "yoloPlayer.h"
#include "stairPlayer.h"
#include "Chrono.h"
#include "Logger.h"

using namespace coo;

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

	//leftPlayer
	leftPlayer lp(fileName);
	logger.info("leftPlayer solve :");
	Chrono chronoLeftPlayer;

	chronoLeftPlayer.launchChrono();
	lp.solve();
	chronoLeftPlayer.stopChrono();
	//lp.printHistory();
	
	//rightPlayer
	rightPlayer rp(fileName);
	logger.info("rightPlayer solve :");
	Chrono chronoRightPlayer;

	chronoRightPlayer.launchChrono();
	rp.solve();
	chronoRightPlayer.stopChrono();
	//rp.printHistory();


	//yoloPlayer
	yoloPlayer yp(fileName);
	logger.info("yoloPlayer solve :");
	Chrono chronoYoloPlayer;

	chronoYoloPlayer.launchChrono();
	yp.solve();
	chronoYoloPlayer.stopChrono();
	//yp.printHistory();


	//stairPlayer
	stairPlayer sp(fileName);
	logger.info("stairPlayer solve :");
	Chrono chronoStairPlayer;

	chronoStairPlayer.launchChrono();
	sp.solve();
	chronoStairPlayer.stopChrono();
	//sp.printHistory();

	logger.info("Fin des resolutions.");

	//Affichage des temps de résolution
	logger.info("Temps de resolution leftPlayer: " + std::to_string(chronoLeftPlayer.getElapsedTimeSeconds()) + "s");
	logger.info("Temps de resolution rightPlayer: " + std::to_string(chronoRightPlayer.getElapsedTimeSeconds()) + "s");
	logger.info("Temps de resolution yoloPlayer: " + std::to_string(chronoYoloPlayer.getElapsedTimeSeconds()) + "s");
	logger.info("Temps de resolution stairPlayer: " + std::to_string(chronoStairPlayer.getElapsedTimeSeconds()) + "s");
}





