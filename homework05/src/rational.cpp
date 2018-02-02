/***
  Copyright 2018 J. West
 */
#include <stdlib.h>
#include <string>
#include "homework05/rational.h"

// calculate greatest common denominator
int gcd(int n, int d);

Rational::Rational() {
  num = den = 0;
}

Rational::Rational(int n) {
  num = n;
  den = 1;
}

Rational::Rational(int n, int d) {
  if (d == 0) throw std::overflow_error("Denominator cannot be zero!");
  if (n == 0) {
    num = 0;
    den = 1;
  } else {
    int g = gcd(abs(n), abs(d));
    num = n/g;
    den = abs(d) / g;
    if (d < 0) {
      num = -num;
    }
  }
}

std::string Rational::toString() {
  if (den == 1) {
    return std::to_string(num);
  } else {
    return std::to_string(num) + "/" + std::to_string(den);
  }
}

std::ostream & operator<<(std::ostream &os, Rational ret) {
  return os << ret.toString();
}

Rational operator+(Rational r1, Rational r2) {
  return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

Rational operator-(Rational r1, Rational r2) {
  return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}

Rational operator*(Rational r1, Rational r2) {
  return Rational(r1.num * r2.num, r1.den * r2.den);
}

Rational operator/(Rational r1, Rational r2) {
  return Rational(r1.num * r2.den, r1.den * r2.num);
}

int gcd(int x, int y) {
  int r = x % y;
  while (r != 0) {
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}
