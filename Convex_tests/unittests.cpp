#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Convex/Point.h"
#include "../Convex/Point.cpp"
#include "../Convex/Alg.h"
#include "../Convex/Alg.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Convex_tests
{		
	TEST_CLASS(UnitTests)
	{
	public:
		
		std::vector<Point> vec;
		std::vector<Point> hull;

		TEST_METHOD(onePointTest)
		{
			Point P1(-6, 3.4);
			vec.push_back(P1);
			Alg::make_hull(vec, hull);
			bool b1 = hull[0].same(P1);
			Assert::AreEqual((int)hull.size(), 1);
			Assert::AreEqual(b1, true);
		}

		TEST_METHOD(twoPointsSameTest)
		{
			Point P1(0, 1);
			Point P2(0, 1);
			vec.push_back(P1);
			vec.push_back(P2);
			Alg::make_hull(vec, hull);
			Assert::AreEqual((int)hull.size(), 1);
			bool b1 = hull[0].same(P1);
			Assert::AreEqual(b1, true);
		}

		TEST_METHOD(twoPointsTest)
		{
			Point P1(0, 1);
			Point P2(-3.4, 9);
			vec.push_back(P1);
			vec.push_back(P2);
			Alg::make_hull(vec, hull);
			Assert::AreEqual((int)hull.size(), 2);
			bool b1 = hull[0].same(P1);
			bool b2 = hull[1].same(P2);
			Assert::AreEqual(b1, true);
			Assert::AreEqual(b2, true);
		}

		TEST_METHOD(normalTest1)
		{
			Point P1(0, 0);
			Point P2(2, 2);
			Point P3(0, 2);
			Point P4(2, 0);
			Point P5(1, 1);
			vec.push_back(P1);
			vec.push_back(P2);
			vec.push_back(P3);
			vec.push_back(P4);
			vec.push_back(P5);
			Alg::make_hull(vec, hull);
			Assert::AreEqual((int)hull.size(), 4);
			bool b1 = hull[0].same(P1);
			bool b2 = hull[1].same(P4);
			bool b3 = hull[2].same(P2);
			bool b4 = hull[3].same(P3);
			Assert::AreEqual(b1, true);
			Assert::AreEqual(b2, true);
			Assert::AreEqual(b3, true);
			Assert::AreEqual(b4, true);
		}

		TEST_METHOD(normalTest2)
		{
			Point P1(-5, 0);
			Point P2(-8, 2);
			Point P3(0, -6);
			Point P4(-4, -5);
			Point P5(0, -6);
			Point P6(9, 10);
			Point P7(3, -4);
			Point P8(4, 5);
			Point P9(1, 1);
			vec.push_back(P1);
			vec.push_back(P2);
			vec.push_back(P3);
			vec.push_back(P4);
			vec.push_back(P5);
			vec.push_back(P6);
			vec.push_back(P7);
			vec.push_back(P8);
			vec.push_back(P9);
			Alg::make_hull(vec, hull);
			Assert::AreEqual((int)hull.size(), 5);
			bool b1 = hull[0].same(P3);
			bool b2 = hull[1].same(P7);
			bool b3 = hull[2].same(P6);
			bool b4 = hull[3].same(P2);
			bool b5 = hull[4].same(P4);
			Assert::AreEqual(b1, true);
			Assert::AreEqual(b2, true);
			Assert::AreEqual(b3, true);
			Assert::AreEqual(b4, true);
			Assert::AreEqual(b5, true);
		}

		TEST_METHOD(normalTest3)
		{
			Point P1(-5, 0);
			Point P2(-5.1, 0);
			Point P3(-5.2, 0);
			Point P4(-5.3, 0);
			Point P5(-5.4, 0);
			Point P6(-5.5, 0);
			Point P7(0, 5);
			Point P8(0, 5.1);
			Point P9(-5, 0.1);
			vec.push_back(P1);
			vec.push_back(P2);
			vec.push_back(P3);
			vec.push_back(P4);
			vec.push_back(P5);
			vec.push_back(P6);
			vec.push_back(P7);
			vec.push_back(P8);
			vec.push_back(P9);
			Alg::make_hull(vec, hull);
			Assert::AreEqual((int)hull.size(), 8);
			bool b1 = hull[0].same(P6);
			bool b2 = hull[1].same(P5);
			bool b3 = hull[2].same(P4);
			bool b4 = hull[3].same(P3);
			bool b5 = hull[4].same(P2);
			bool b6 = hull[5].same(P1);
			bool b7 = hull[6].same(P7);
			bool b8 = hull[7].same(P8);
			Assert::AreEqual(b1, true);
			Assert::AreEqual(b2, true);
			Assert::AreEqual(b3, true);
			Assert::AreEqual(b4, true);
			Assert::AreEqual(b5, true);
			Assert::AreEqual(b6, true);
			Assert::AreEqual(b7, true);
			Assert::AreEqual(b8, true);
		}
	};
}