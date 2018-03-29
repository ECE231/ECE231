/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <fstream>
#include "homework09/IntArray.h"
#define NUM 12
TEST(IntArray, size) {
  IntArray a(NUM);
  EXPECT_EQ(a.size(), NUM);
}
TEST(IntArray, get_put) {
  IntArray a(NUM);
  a[0] = a[1] = 1234;
  a.put(5, 5555);
  EXPECT_EQ(a[0], 1234);
  EXPECT_EQ(a[1], 1234);
  EXPECT_EQ(a[5], 5555);
}
TEST(IntArray, array_bounds) {
  IntArray a(NUM);
  int exceptions = 0;
  try { a[NUM] = 5; } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
    exceptions++;
  }
  try { a[-NUM]; } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
    exceptions++;
  }
  EXPECT_EQ(exceptions, 2); 
}
TEST(IntArray, put_bounds) {
  IntArray a(NUM);
  int exceptions = 0;
  try { a.put(NUM,5); } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
    exceptions++;
  }
  try { a.put(-1,5); } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
    exceptions++;
  }
  EXPECT_EQ(exceptions, 2); 
}
TEST(IntArray, get_bounds) {
  IntArray a(NUM);
  int exceptions = 0;
  try { int val = a.get(NUM); } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
    exceptions++;
  }
  try { int val = a.get(-1); } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
    exceptions++;
  }
  EXPECT_EQ(exceptions, 2); 
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
