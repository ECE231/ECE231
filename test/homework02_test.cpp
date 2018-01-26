/***
  Copyright 2018 J. West
 */
#include <gtest/gtest.h>
#include "homework02/homework02.h"
TEST(permutations, limits) {
  EXPECT_EQ(permutations(0, 0), 0);
  EXPECT_EQ(permutations(-1, 0), 0);
  EXPECT_EQ(permutations(0, -1), 0);
  EXPECT_EQ(permutations(10, 11), 0);
}
  
TEST(permutations, all) {
  EXPECT_EQ(permutations(52, 2), 2652);
}
TEST(combinations, limits) {
  EXPECT_EQ(combinations(0, 0), 0);
  EXPECT_EQ(combinations(-1, 0), 0);
  EXPECT_EQ(combinations(0, -1), 0);
}

TEST(combinations, all) {
  EXPECT_EQ(combinations(6, 2), 15);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

