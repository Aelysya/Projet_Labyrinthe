#include "pch.h"
#include "CppUnitTest.h"
#include "../Projet_Labyrinthe/grid.cpp"
#include "../Projet_Labyrinthe/tracer.cpp"

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
			utility::tracer t(7, 7);
			Assert::IsTrue(t.getMoves() == 0);
			t.addMove(1, 1, utility::direction::RIGHT);
			Assert::IsTrue(t.getMoves() == 1);
		}
	};
}
