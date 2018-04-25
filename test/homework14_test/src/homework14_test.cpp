/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include "compare_files/compare_files.h"

TEST(employees, all) {
  int res = std::system("../../homework14/test_employee > output.txt");
  EXPECT_EQ(res,0);
  EXPECT_TRUE(compare_files("output.txt", "correct_output.txt"));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

