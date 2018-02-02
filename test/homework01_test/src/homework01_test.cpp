/***
  Copyright 2018 J. West
 */
#include <gtest/gtest.h>
#include "homework01/homework01.h"
TEST(calculatePi, all) {
  ASSERT_NEAR(3.4641, calculatePi(1), 0.0001);
  ASSERT_NEAR(3.15241, calculatePi(10), 0.0001);
  ASSERT_NEAR(3.14194, calculatePi(100), 0.0001);
  ASSERT_NEAR(3.14159, calculatePi(1000), 0.0001);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

