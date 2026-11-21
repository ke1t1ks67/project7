#pragma once
#include <stdexcept>

struct Fraction {
    long long numerator;
    long long denominator;

    Fraction(long long n = 0, long long d = 1)
        : numerator(n), denominator(d) {
        validate(*this);
    }

    static void validate(const Fraction& f) {
        if (f.denominator == 0)
            throw std::invalid_argument("Zero denominator");
    }

    static long long gcd(long long a, long long b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            long long remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    static void simplifyFraction(Fraction& f) {
        validate(f);
        long long divisor = gcd(f.numerator, f.denominator);
        f.numerator /= divisor;
        f.denominator /= divisor;
        if (f.denominator < 0) {
            f.numerator = -f.numerator;
            f.denominator = -f.denominator;
        }
    }

    static void addFractions(const Fraction& a,
        const Fraction& b, Fraction& result) {
        validate(a);
        validate(b);
        Fraction temp(
            a.numerator * b.denominator + b.numerator * a.denominator,
            a.denominator * b.denominator);
        simplifyFraction(temp);
        result = temp;
    }

    static void multiplyFractions(const Fraction& a,
        const Fraction& b, Fraction& result) {
        validate(a);
        validate(b);
        Fraction temp(a.numerator * b.numerator,
            a.denominator * b.denominator);
        simplifyFraction(temp);
        result = temp;
    }

    static double toDecimal(const Fraction& f) {
        validate(f);
        return static_cast<double>(f.numerator) / f.denominator;
    }
};
