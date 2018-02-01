/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <fstream>
#include "homework04/homework04.h"
#include "grading/compare_files.h"

TEST(histogram, all) {
  int res = std::system("histogram good_input.txt > output.txt");
  EXPECT_EQ(res, 0);
  EXPECT_TRUE(compare_files("output.txt", "good_histogram_result.txt"));
}
  
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

