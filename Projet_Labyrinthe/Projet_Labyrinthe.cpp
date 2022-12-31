#include <iostream>
#include <fstream>
#include "leftPlayer.h"
#include "rightPlayer.h"
#include "yoloplayer.h"
#include "solver.h"

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

	leftPlayer lp(fileName);
	rightPlayer rp(fileName);
	yoloPlayer yp(fileName);

	lp.solve();
	rp.solve();
	yp.solve();
}





