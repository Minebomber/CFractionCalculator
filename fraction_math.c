#include "fraction_math.h"

struct Fraction add_fractions(struct Fraction f1, struct Fraction f2) {
    int new_numerator1 = f1.numerator * f2.denominator;
    int new_numerator2 = f2.numerator * f1.denominator;
    int common_denominator = f1.denominator * f2.denominator;
    int numerator = new_numerator1 + new_numerator2;
    struct Fraction f = {.numerator = numerator, .denominator = common_denominator};
    f = simplify(f);
    return f;
}

struct Fraction subtract_fractions(struct Fraction f1, struct Fraction f2) {
    int new_numerator1 = f1.numerator * f2.denominator;
    int new_numerator2 = f2.numerator * f1.denominator;
    int common_denominator = f1.denominator * f2.denominator;
    int numerator = new_numerator1 - new_numerator2;
    struct Fraction f = {.numerator = numerator, .denominator = common_denominator};
    f = simplify(f);
    return f;
}

struct Fraction multiply_fractions(struct Fraction f1, struct Fraction f2) {
    int numerator = f1.numerator * f2.numerator;
    int denominator = f1.denominator * f2.denominator;
    struct Fraction f = {.numerator = numerator, .denominator = denominator};
    f = simplify(f);
    return f;
}

struct Fraction divide_fractions(struct Fraction f1, struct Fraction f2) {
    struct Fraction recip = reciprocal(f2);
    struct Fraction result = multiply_fractions(f1, recip);
    return result;
}

struct MixedNumber add_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2) {
    struct Fraction f1 = mixed_to_improper(m1);
    struct Fraction f2 = mixed_to_improper(m2);
    struct Fraction result = add_fractions(f1, f2);
    struct MixedNumber m = improper_to_mixed(result);
    return m;
}

struct MixedNumber subtract_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2) {
    struct Fraction f1 = mixed_to_improper(m1);
    struct Fraction f2 = mixed_to_improper(m2);
    struct Fraction result = subtract_fractions(f1, f2);
    struct MixedNumber m = improper_to_mixed(result);
    return m;
}

struct MixedNumber multiply_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2) {
    struct Fraction f1 = mixed_to_improper(m1);
    struct Fraction f2 = mixed_to_improper(m2);
    struct Fraction result = multiply_fractions(f1, f2);
    struct MixedNumber m = improper_to_mixed(result);
    return m;
}

struct MixedNumber divide_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2) {
    struct Fraction f1 = mixed_to_improper(m1);
    struct Fraction f2 = mixed_to_improper(m2);
    struct Fraction result = divide_fractions(f1, f2);
    struct MixedNumber m = improper_to_mixed(result);
    return m;
}

struct Fraction mixed_to_improper(struct MixedNumber m) {
    struct Fraction f;
    int numerator = m.whole * m.denominator + m.numerator;
    f.numerator = numerator;
    f.denominator = m.denominator;
    return f;
}

struct MixedNumber improper_to_mixed(struct Fraction f) {
    int whole = (int)((float)f.numerator / (float)f.denominator);
    int abs_numerator = abs(f.numerator);
    int gcd = find_gcd(f.numerator, f.denominator);
    int numerator = abs_numerator / gcd;
    int denominator = f.denominator / gcd;
    int abs_whole = abs(whole);
    numerator = numerator - (abs_whole * denominator);
    struct MixedNumber m = {.whole = whole, .numerator = numerator, .denominator = denominator};
    return m;
}

struct Fraction simplify(struct Fraction f) {
    struct Fraction result;
    int gcd = find_gcd(f.numerator, f.denominator);
    result.numerator = f.numerator / gcd;
    result.denominator = f.denominator / gcd;
    return result;
}

struct Fraction reciprocal(struct Fraction f) {
    struct Fraction result = {.numerator = f.denominator, .denominator = f.numerator};
    return result;
}

int find_gcd(int n1, int n2) {
    if (n2 != 0)
        return find_gcd(n2, n1 % n2);
    else
        return n1;
}
