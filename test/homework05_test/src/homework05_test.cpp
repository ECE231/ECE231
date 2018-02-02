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

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

