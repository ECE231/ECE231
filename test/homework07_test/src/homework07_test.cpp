/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <fstream>
//#include "homework07/homework07.h"
#include "compare_files/compare_files.h"

TEST(solver, good) {
  int res = std::system("../../homework07/solve_maze ShortestPathMaze.txt");
  EXPECT_EQ(res, 0);
  // try with start square properly marked
  bool good = compare_files("output.txt", "correct_output.txt");
  // if no match with start square then try with start marked with X
  if(!good) {
    std::cout << "Trying with start square as part of path\n";
    EXPECT_TRUE(compare_files("output.txt", "correct_output_with_start.txt"));
  }
}
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

