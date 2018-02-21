/***
  Copyright 2018 J. West
 */
#include <stdlib.h>
#include <string>
#include "homework05/rational.h"

// calculate greatest common denominator
int gcd(int n, int d);

Rational Rational::reduce(void) {
    int g = gcd(abs(num), abs(den));
    num = num/g;
    if (den < 0) {
      num = -num;
    }
    den = abs(den) / g;
    return *this;
}

Rational::Rational() {
  num = 0;
  den = 1;
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
    num = n;
    den = d;
    reduce();
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

bool operator==(Rational r1, Rational r2) {
  return r1.num == r2.num && r1.den == r2.den;
}

bool operator!=(Rational r1, Rational r2) {
  return !(r1 == r2);
}

bool operator<(Rational r1, Rational r2) {
  Rational dif = r1 - r2;
  return dif.num < 0;
}

bool operator<=(Rational r1, Rational r2) {
  return r1 == r2 || r1 < r2;
}

bool operator>(Rational r1, Rational r2) {
  Rational dif = r1 - r2;
  return dif.num > 0;
}

bool operator>=(Rational r1, Rational r2) {
  return r1 == r2 || r1 > r2;
}

Rational &operator+=(Rational &r1, Rational r2) {
  return r1 = r1 + r2;
}

Rational &operator-=(Rational &r1, Rational r2) {
  return r1 = r1 - r2;
}

Rational &operator*=(Rational &r1, Rational r2) {
  return r1 = r1 * r2;
}

Rational &operator/=(Rational &r1, Rational r2) {
  return r1 = r1 / r2;
}

Rational &operator++(Rational &r1) {       // prefix  ++Rational
  return r1 = r1 + Rational(1);
}

Rational operator++(Rational &r1, int) {  // postfix Rational++
  Rational temp = r1;
//  std::cout << r1;
  r1 += Rational(1);
//  std::cout << r1;
  return temp;
}

Rational &operator--(Rational &r1) {       // prefix  --Rational
  return r1 = r1 - Rational(1);
}

Rational operator--(Rational &r1, int) {  // postfix Rational--
  Rational temp = r1;
  r1 -= Rational(1);
  return temp;
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
