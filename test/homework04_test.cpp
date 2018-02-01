/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <fstream>
#include "homework04/homework04.h"
#include "grading/compare_files.h"

TEST(histogram, good) {
  int res = std::system("homework04/histogram good_input.txt > output.txt");
  EXPECT_EQ(res, 0);
  EXPECT_TRUE(compare_files("output.txt", "good_histogram_result.txt"));
}

TEST(histogram, no_file_supplied) {
  int res = std::system("homework04/histogram");
  EXPECT_NE(res, 0);
}

TEST(histogram, no_file) {
  int res = std::system("homework04/histogram this_file_does_not_exist.txt");
  EXPECT_NE(res, 0);
}
  
TEST(histogram, bad_file) {
  int res = std::system("homework04/histogram bad_input.txt");
  EXPECT_NE(res, 0);
}
  
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

