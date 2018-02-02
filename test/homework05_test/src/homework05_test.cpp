/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <iostream>
#include "homework05/rational.h"

TEST(rational, stream) {
  std::ostringstream os;
  os << Rational(123, 456);
  EXPECT_STREQ(os.str().c_str(), "41/152");
}

TEST(rational, add) {
  std::ostringstream os;
  os << Rational(12, 45) + Rational(23, 55);
  EXPECT_STREQ(os.str().c_str(), "113/165");
}

TEST(rational, sub) {
  std::ostringstream os;
  os << Rational(12, 45) - Rational(23, 55);
  EXPECT_STREQ(os.str().c_str(), "-5/33");
}

TEST(rational, multiply) {
  std::ostringstream os;
  os << Rational(12, 45) * Rational(23, 55);
  EXPECT_STREQ(os.str().c_str(), "92/825");
}

TEST(rational, divide) {
  std::ostringstream os;
  os << Rational(12, 45) / Rational(23, 55);
  EXPECT_STREQ(os.str().c_str(), "44/69");
}

TEST(rational, equal) {
  EXPECT_TRUE(Rational(12,45) == Rational(24,90));
  EXPECT_FALSE(Rational(12,45) == Rational(23,90));
  EXPECT_FALSE(Rational(12,45) == Rational(25,90));
}

TEST(rational, notequal) {
  EXPECT_FALSE(Rational(12,45) != Rational(24,90));
  EXPECT_TRUE(Rational(12,45) != Rational(23,90));
}

TEST(rational, greater) {
  EXPECT_FALSE(Rational(12,45) > Rational(24,90));
  EXPECT_TRUE(Rational(12,45) > Rational(23,90));
  EXPECT_FALSE(Rational(12,45) > Rational(25,90));
}

TEST(rational, greater_equal) {
  EXPECT_TRUE(Rational(12,45) >= Rational(24,90));
  EXPECT_TRUE(Rational(12,45) >= Rational(23,90));
  EXPECT_FALSE(Rational(12,45) >= Rational(25,90));
}

TEST(rational, less) {
  EXPECT_FALSE(Rational(12,45) < Rational(24,90));
  EXPECT_FALSE(Rational(12,45) < Rational(23,90));
  EXPECT_TRUE(Rational(12,45) < Rational(25,90));
}

TEST(rational, less_equal) {
  EXPECT_TRUE(Rational(12,45) <= Rational(24,90));
  EXPECT_FALSE(Rational(12,45) <= Rational(23,90));
  EXPECT_TRUE(Rational(12,45) <= Rational(25,90));
}

TEST(rational, plus_equal) {
  EXPECT_TRUE(Rational(15,45) == Rational(12,45) += Rational(3,45));
}

TEST(rational, minus_equal) {
  EXPECT_TRUE(Rational(9,45) == Rational(12,45) -= Rational(3,45));
}

TEST(rational, times_equal) {
  EXPECT_TRUE(Rational(36,2025) == Rational(12,45) *= Rational(3,45));
}

TEST(rational, div_equal) {
  EXPECT_TRUE(Rational(4) == Rational(12,45) *= Rational(3,45));
}

TEST(rational, increment) {
  EXPECT_TRUE(Rational(57,45) == ++Rational(12,45));
}

TEST(rational, decrement) {
  EXPECT_TRUE(Rational(-33,45) == --Rational(12,45));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

