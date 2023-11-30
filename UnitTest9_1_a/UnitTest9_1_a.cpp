#include "pch.h"
#include "CppUnitTest.h"
#include "../PR9_1/PR9_1_a.cpp"
 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest91a
{
	TEST_CLASS(UnitTest91a)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Student st;
			st.spec = KN;
			st.physicm = 90.0;
			st.mathm = 80.0;
			st.itm = 70.0;
			int N = 1;

			double result = Average(st, N);
			Assert::AreEqual(80.0, result);
		}
	};
}
