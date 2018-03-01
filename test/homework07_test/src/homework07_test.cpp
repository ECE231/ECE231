/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <fstream>
//#include "homework07/homework07.h"
#include "compare_files/compare_files.h"

TEST(solver, good) {
  int res = std::system("../../homework07/solve_maze ShortestPathMaze.txt");
  EXPECT_EQ(res, 0);
  EXPECT_TRUE(compare_files("output.txt", "correct_output.txt"));
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

