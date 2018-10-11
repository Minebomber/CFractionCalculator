#ifndef  _FRACTION_MATH_H_
#define  _FRACTION_MATH_H_

#include "fraction.h"
#include "mixed_number.h"
#include <stdlib.h>
#include <stdio.h>

struct Fraction add_fractions(struct Fraction f1, struct Fraction f2);
struct Fraction subtract_fractions(struct Fraction f1, struct Fraction f2);
struct Fraction multiply_fractions(struct Fraction f1, struct Fraction f2);
struct Fraction divide_fractions(struct Fraction f1, struct Fraction f2);

struct MixedNumber add_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2);
struct MixedNumber subtract_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2);
struct MixedNumber multiply_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2);
struct MixedNumber divide_mixed_numbers(struct MixedNumber m1, struct MixedNumber m2);

struct Fraction mixed_to_improper(struct MixedNumber m);
struct MixedNumber improper_to_mixed(struct Fraction f);
struct Fraction simplify(struct Fraction f);
struct Fraction reciprocal(struct Fraction f);

int find_gcd(int n1, int n2);

#endif
