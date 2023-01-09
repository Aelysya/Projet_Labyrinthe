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
			utility::grid g("lab3_3x3.txt", 2);
			Assert::IsTrue(g.getX() == 7);
		}
	};

	TEST_CLASS(TestTracer)
	{
	public:
		TEST_METHOD(getMoves)
		{
			tracer t(3, 3);
			Assert::IsTrue(t.getMoves() == 0);
			t.addMove(1, 1, RIGHT);
			Assert::IsTrue(t.getMoves() == 1);
			t.addMove(1, 1, RIGHT);
			Assert::IsTrue(t.getMoves() == 2);
		}

		TEST_METHOD(checkBlocked)
		{
			tracer t(5, 5);
			//Todo
		}

		TEST_METHOD(isSeen)
		{
			u:tracer t(5, 5);
			Assert::IsTrue(t.isSeen(1, 1) ==  NONE);
			Assert::IsTrue(t.isSeen(2, 1) == NONE);
			Assert::IsTrue(t.isSeen(1, 2) == NONE);
			t.addMove(1, 1, RIGHT);
			Assert::IsTrue(t.isSeen(1, 1) == RIGHT);
			Assert::IsTrue(t.isSeen(2, 1) == RIGHT);
			Assert::IsTrue(t.isSeen(1, 2) == NONE);
			t.addMove(1, 1, DOWN);
			Assert::IsTrue(t.isSeen(1, 1) == DOWN);
			Assert::IsTrue(t.isSeen(2, 1) == RIGHT);
			Assert::IsTrue(t.isSeen(1, 2) == DOWN);
			t.addMove(2, 1, LEFT);
			Assert::IsTrue(t.isSeen(1, 1) == LEFT);
			Assert::IsTrue(t.isSeen(2, 1) == LEFT);
			Assert::IsTrue(t.isSeen(1, 2) == DOWN);
			t.addMove(1, 2, UP);
			Assert::IsTrue(t.isSeen(1, 1) == UP);
			Assert::IsTrue(t.isSeen(2, 1) == LEFT);
			Assert::IsTrue(t.isSeen(1, 2) == UP);
		}

		TEST_METHOD(isAccessible)
		{
			tracer t(3, 3);
			//Todo
		}
	};
}
