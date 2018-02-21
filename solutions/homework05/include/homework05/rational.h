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
  Rational reduce(void);
  std::string toString(void);
  friend Rational operator+(Rational r1, Rational r2);
  friend Rational operator-(Rational r1, Rational r2);
  friend Rational operator*(Rational r1, Rational r2);
  friend Rational operator/(Rational r1, Rational r2);
  friend bool operator==(Rational r1, Rational r2);
  friend bool operator!=(Rational r1, Rational r2);
  friend bool operator<(Rational r1, Rational r2);
  friend bool operator<=(Rational r1, Rational r2);
  friend bool operator>(Rational r1, Rational r2);
  friend bool operator>=(Rational r1, Rational r2);
  friend Rational &operator+=(Rational &r1, Rational r2);
  friend Rational &operator-=(Rational &r1, Rational r2);
  friend Rational &operator*=(Rational &r1, Rational r2);
  friend Rational &operator/=(Rational &r1, Rational r2);
  friend Rational &operator++(Rational &r1);       // prefix  ++Rational
  friend Rational operator++(Rational &r1, int);  // postfix Rational++
  friend Rational &operator--(Rational &r1);       // prefix  --Rational
  friend Rational operator--(Rational &r1, int);  // postfix Rational--

 private:
  int num;
  int den;
};

std::ostream& operator<<(std::ostream &os, Rational ret);
Rational operator+(Rational r1, Rational r2);
Rational operator-(Rational r1, Rational r2);
Rational operator*(Rational r1, Rational r2);
Rational operator/(Rational r1, Rational r2);
bool operator==(Rational r1, Rational r2);
bool operator!=(Rational r1, Rational r2);
bool operator<(Rational r1, Rational r2);
bool operator<=(Rational r1, Rational r2);
bool operator>(Rational r1, Rational r2);
bool operator>=(Rational r1, Rational r2);
Rational &operator+=(Rational &r1, Rational r2);
Rational &operator-=(Rational &r1, Rational r2);
Rational &operator*=(Rational &r1, Rational r2);
Rational &operator/=(Rational &r1, Rational r2);
Rational &operator++(Rational &r1);       // prefix  ++Rational
Rational operator++(Rational &r1, int);  // postfix Rational--
Rational &operator--(Rational &r1);       // prefix  --Rational
Rational operator--(Rational &r1, int);  // postfix Rational--

#endif  // HOMEWORK05_INCLUDE_HOMEWORK05_RATIONAL_H_
