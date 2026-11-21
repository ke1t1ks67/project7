#include <iostream>
#include "Fraction.h"

int main() {
    Fraction result;

    Fraction::addFractions(Fraction(1, 2), Fraction(1, 3), result);
    std::cout << "1/2 + 1/3 = "
        << result.numerator << "/" << result.denominator << "\n";

    Fraction::multiplyFractions(Fraction(2, 3), Fraction(3, 4), result);
    std::cout << "2/3 * 3/4 = "
        << result.numerator << "/" << result.denominator << "\n";

    Fraction value(8, 12);
    Fraction::simplifyFraction(value);
    std::cout << "8/12 = "
        << value.numerator << "/" << value.denominator << "\n";

    std::cout << "3/4 = "
        << Fraction::toDecimal(Fraction(3, 4)) << "\n";

    try {
        Fraction invalid(1, 0);
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Error: " << error.what() << "\n";
    }
    return 0;
}

