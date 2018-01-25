/***
  Copyright 2018 J. West
 */
#include <gtest/gtest.h>
#include "homework02/homework02.h"
TEST(permutations, all) {
  EXPECT_EQ(permutations(52, 2), 2652);
}
TEST(combinations, all) {
  EXPECT_EQ(combinations(6, 2), 15);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

