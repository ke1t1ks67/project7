#include "pch.h"
#include "CppUnitTest.h"
#include "../Project8/Fraction.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Practice8Tests {
    TEST_CLASS(FractionTests) {
public:

    // Позитивный тест: сложение
    TEST_METHOD(Add_ValidFractions) {
        Fraction a(1, 2), b(1, 3), result;

        Fraction::addFractions(a, b, result);

        Assert::AreEqual(5LL, result.numerator);
        Assert::AreEqual(6LL, result.denominator);
    }

    // Позитивный тест: умножение, сокращение и перевод
    TEST_METHOD(Multiply_Simplify_ToDecimal) {
        Fraction a(2, 3), b(3, 4), result;

        Fraction::multiplyFractions(a, b, result);

        Assert::AreEqual(1LL, result.numerator);
        Assert::AreEqual(2LL, result.denominator);
        Assert::AreEqual(0.5, Fraction::toDecimal(result), 0.000001);
    }

    // Негативный тест: создание дроби со знаменателем 0
    TEST_METHOD(Constructor_ZeroDenominator) {
        Assert::ExpectException<std::invalid_argument>([]() {
            Fraction invalid(1, 0);
            });
    }

    // Негативный тест: перевод дроби со знаменателем 0
    TEST_METHOD(ToDecimal_ZeroDenominator) {
        Fraction value(1, 2);
        value.denominator = 0;

        Assert::ExpectException<std::invalid_argument>([&]() {
            Fraction::toDecimal(value);
            });
    }
    };
}

