/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <fstream>
#include "homework03/homework03.h"

TEST(encrypt, all) {
  EXPECT_STREQ(encrypt("WORKERS OF THE WORLD UNITE!", 
    "QWERTYUIOPASDFGHJKLZXCVBNM").c_str(), 
    "VGKATKL GY ZIT VGKSR XFOZT!");
}

TEST(decrypt, all) {
  EXPECT_STREQ(decrypt("VGKATKL GY ZIT VGKSR XFOZT!",
    "QWERTYUIOPASDFGHJKLZXCVBNM").c_str(), 
    "WORKERS OF THE WORLD UNITE!"); 
}

bool compareFiles(const std::string &file1, const std::string &file2) {
  std::ifstream f1(file1.c_str());
  std::ifstream f2(file2.c_str());
  while(f1.good() && f2.good()) {
    char c1, c2;
    f1.get(c1);
    f2.get(c2);
    if (c1 != c2) {
      return false;
    }
  }
  return true;
}


TEST(tabs_to_spaces, all) {
  tabs_to_spaces("tab_input.txt", 4, "tab_output.txt");
  EXPECT_TRUE(compareFiles("tab_output.txt", "tab_correct_result.txt"));
}
  
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

