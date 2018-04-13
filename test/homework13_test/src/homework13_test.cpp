/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <iostream>
#include "compare_files/compare_files.h"

TEST(graph, good) {
  int res = std::system("../../homework13/test_dijkstra map.txt Atlanta Denver > output1.txt");
  EXPECT_TRUE(compare_files("output1.txt", "correct_output1.txt"));
}
TEST(graph, none) {
  int res = std::system("../../homework13/test_dijkstra map.txt Atlanta Portland > output2.txt");
  EXPECT_TRUE(compare_files("output2.txt", "correct_output2.txt"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

