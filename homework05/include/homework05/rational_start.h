/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK05_INCLUDE_HOMEWORK05_RATIONAL_H_
#define HOMEWORK05_INCLUDE_HOMEWORK05_RATIONAL_H_
#include <string>
#include <iostream>

class Rational {
 public:
  Rational(void);
  explicit Rational(int n);
  Rational(int x, int y);
  std::string toString(void);
  friend Rational operator+(Rational r1, Rational R2);
  friend Rational operator-(Rational r1, Rational R2);
  friend Rational operator*(Rational r1, Rational R2);
  friend Rational operator/(Rational r1, Rational R2);
 private:
  int num;
  int den;
};

std::ostream& operator<<(std::ostream &os, Rational ret);
Rational operator+(Rational r1, Rational R2);
Rational operator-(Rational r1, Rational R2);
Rational operator*(Rational r1, Rational R2);
Rational operator/(Rational r1, Rational R2);

#endif  // HOMEWORK05_INCLUDE_HOMEWORK05_RATIONAL_H_
