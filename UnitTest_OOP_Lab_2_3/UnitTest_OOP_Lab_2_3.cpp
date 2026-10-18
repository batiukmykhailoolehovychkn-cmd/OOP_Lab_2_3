#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2_3/Fraction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestOOPLab23
{
	TEST_CLASS(UnitTestOOPLab23)
	{
    public:
        TEST_METHOD(TestAddition)
        {
            Fraction f1(2, 5000); // 2.5000
            Fraction f2(1, 5000); // 1.5000
            Fraction result = f1 + f2;

            // 2.5 + 1.5 = 4.0
            Assert::AreEqual(4L, result.GetIntegerPart());
            Assert::AreEqual((unsigned short)0, result.GetFractionalPart());
        }

        TEST_METHOD(TestMultiplication)
        {
            Fraction f1(2, 5000); // 2.5000
            Fraction f2(2, 0);    // 2.0000
            Fraction result = f1 * f2;

            // 2.5 * 2 = 5.0
            Assert::AreEqual(5L, result.GetIntegerPart());
            Assert::AreEqual((unsigned short)0, result.GetFractionalPart());
        }

        TEST_METHOD(TestIncrement)
        {
            Fraction f(1, 5000); // 1.5000
            ++f;                 // Префіксний інкремент (збільшує цілу частину)

            Assert::AreEqual(2L, f.GetIntegerPart());
            Assert::AreEqual((unsigned short)5000, f.GetFractionalPart());
        }
    };
}