#include "pch.h"
#include "CppUnitTest.h"
#include "../task6/task6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			vector <pair<int, int> > input_vector = { make_pair(2, 2), make_pair(3,4), make_pair(2, 3), 
				make_pair(1,1), make_pair(3, 3) }, test_output;
			vector <pair<int, int> > true_output = { make_pair(1, 1), make_pair(2, 2), make_pair(2, 3),
				make_pair(3, 3), make_pair(3, 4) };
			test_output = get_distances(input_vector);
			Assert::IsTrue(test_output == true_output);
		}

		TEST_METHOD(TestMethod2)
		{
			vector <pair<int, int> > input_vector = { make_pair(2, 1), make_pair(3,3), make_pair(0, 1),
				make_pair(-2,-2) }, test_output;
			vector <pair<int, int> > true_output = { make_pair(0, 1), make_pair(2, 1), make_pair(-2, -2),
				make_pair(3, 3)};
			test_output = get_distances(input_vector);
			Assert::IsTrue(test_output == true_output);
		}

		TEST_METHOD(TestMethod3)
		{
			vector <pair<int, int> > input_vector = { make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0)}, test_output;
			vector <pair<int, int> > true_output = { make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0)};
			test_output = get_distances(input_vector);
			Assert::IsTrue(test_output == true_output);
		}
	};
}
