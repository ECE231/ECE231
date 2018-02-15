/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <iostream>
#include "homework06/homework06.h"
bool checkWeights(
    int target,
    const std::vector<int> &weights,
    std::vector<int> &left,
    std::vector<int> &right) {
  // add up all of the weight on left and right
  int sum_left = target;
  for (int i : left) sum_left += i;
  int sum_right = 0;
  for (int i : right) sum_right += i;
  EXPECT_TRUE(sum_left == sum_right);
}
  
TEST(balance, one) {
  std::vector<int> left, right;
  std::vector<int> weights = {10, 20, 30, 40};
  int target = 100;
  EXPECT_TRUE(findBalance(target, weights, left, right));
  checkWeights(target, weights, left, right);
}
 
TEST(balance, two) {
  std::vector<int> left, right;
  std::vector<int> weights = {10, 20, 30};
  int target = 100;
  EXPECT_FALSE(findBalance(target, weights, left, right));
}

TEST(balance, three) {
  std::vector<int> left, right;
  std::vector<int> weights = {1, 3, 4, 5};
  int target = 6;
  EXPECT_TRUE(findBalance(target, weights, left, right));
  checkWeights(target, weights, left, right);
}

TEST(balance, four) {
  std::vector<int> left, right;
  std::vector<int> weights = {20, 5, 1, 3, 6};
  int target = 18;
  EXPECT_TRUE(findBalance(target, weights, left, right));
  checkWeights(target, weights, left, right);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

