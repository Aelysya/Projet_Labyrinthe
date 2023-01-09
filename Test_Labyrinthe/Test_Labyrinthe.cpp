#include "pch.h"
#include "CppUnitTest.h"
#include "../Projet_Labyrinthe/grid.cpp"
#include "../Projet_Labyrinthe/tracer.cpp"
#include "../Projet_Labyrinthe/direction.h"

using namespace utility;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestLabyrinthe
{
	TEST_CLASS(TestGrid)
	{
	public:
		TEST_METHOD(getSize)
		{
			grid g1("..\\..\\Test_Labyrinthe\\mazeTest1.txt", 2);
			Assert::IsTrue(g1.getX() == 5);
			Assert::IsTrue(g1.getY() == 5);
			grid g2("..\\..\\Test_Labyrinthe\\mazeTest2.txt", 2);
			Assert::IsTrue(g2.getX() == 7);
			Assert::IsTrue(g2.getY() == 7);
		}
	};

	TEST_CLASS(TestTracer)
	{
	public:
		TEST_METHOD(getMoves)
		{
			//Ajout de mouvements
			tracer t(3, 3);
			Assert::IsTrue(t.getMoves() == 0);
			t.addMove(1, 1, RIGHT);
			Assert::IsTrue(t.getMoves() == 1);
			//Effectuer un mouvement déjà effectué ajoute 
			//un mouvement au compteur
			t.addMove(1, 1, RIGHT);
			Assert::IsTrue(t.getMoves() == 2);
		}

		TEST_METHOD(isAccessible)
		{
			tracer t(5, 5);
			grid g("..\\..\\Test_Labyrinthe\\mazeTest1.txt", 2);

			//Une case avec deux chemins possible ne peut être bloqué
			t.checkBlocked(3, 1, LEFT, g);
			t.checkBlocked(3, 1, DOWN, g);
			Assert::IsTrue(t.isAccessible(2, 1));
			Assert::IsTrue(t.isAccessible(3, 2));

			//Une case ne peut être bloquée s'il y a au moins un autre chemin
			//que la direction donnée
			Assert::IsTrue(t.isAccessible(1, 1));
			t.checkBlocked(1, 1, LEFT, g);
			Assert::IsTrue(t.isAccessible(2, 1));
			t.checkBlocked(1, 1, UP, g);
			Assert::IsTrue(t.isAccessible(2, 1));
			t.checkBlocked(1, 1, DOWN, g);
			Assert::IsTrue(t.isAccessible(2, 1));

			//La seule direction possible est la droite, 
			//la case à droite de la case (1,1) est bloquée
			t.checkBlocked(1, 1, RIGHT, g); //bloque case de droite
			Assert::IsFalse(t.isAccessible(2, 1));

			//Un des chemins a été bloqué, il n'y a plus qu'un chemin possible
			//le chemin donné par la direction
			t.checkBlocked(3, 1, DOWN, g); //bloque case d'en bas
			Assert::IsFalse(t.isAccessible(3, 2));
		}

		TEST_METHOD(isSeen)
		{
			//A l'instanciation du tracer, aucune case n'est vue
			tracer t(5, 5);
			Assert::IsTrue(t.isSeen(1, 1) ==  NONE);
			Assert::IsTrue(t.isSeen(2, 1) == NONE);
			Assert::IsTrue(t.isSeen(1, 2) == NONE);
			//Ajouter un mouvement à droite actualise la case actuelle + celle de droite
			t.addMove(1, 1, RIGHT);
			Assert::IsTrue(t.isSeen(1, 1) == RIGHT);
			Assert::IsTrue(t.isSeen(2, 1) == RIGHT);
			Assert::IsTrue(t.isSeen(1, 2) == NONE);
			//Ajouter un mouvement à droite actualise la case actuelle + celle d'en bas
			t.addMove(1, 1, DOWN);
			Assert::IsTrue(t.isSeen(1, 1) == DOWN);
			Assert::IsTrue(t.isSeen(2, 1) == RIGHT);
			Assert::IsTrue(t.isSeen(1, 2) == DOWN);
			//Ajouter un mouvement à droite actualise la case actuelle + celle de gauche
			t.addMove(2, 1, LEFT);
			Assert::IsTrue(t.isSeen(1, 1) == LEFT);
			Assert::IsTrue(t.isSeen(2, 1) == LEFT);
			Assert::IsTrue(t.isSeen(1, 2) == DOWN);
			//Ajouter un mouvement à droite actualise la case actuelle + celle d'en haut
			t.addMove(1, 2, UP);
			Assert::IsTrue(t.isSeen(1, 1) == UP);
			Assert::IsTrue(t.isSeen(2, 1) == LEFT);
			Assert::IsTrue(t.isSeen(1, 2) == UP);
		}
	};
}
