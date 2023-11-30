#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9_1_b/PR9_1_b.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91b
{
	TEST_CLASS(UnitTest91b)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int N = 3; 
            Student students[N];

            students[0].physicm = 4.0;
            students[0].mathm = 4.0;
            students[0].pedagogs = 5.0;

            students[1].physicm = 4.5;
            students[1].mathm = 4.5;
            students[1].pedagogs = 4.5;

            students[2].physicm = 3.0;
            students[2].mathm = 3.5;
            students[2].pedagogs = 4.0;

            double result = SearchProc(students, N);
            Assert::AreEqual(0.0, result, 0.000001);
		}
	};
}
