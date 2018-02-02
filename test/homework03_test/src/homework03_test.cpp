/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <fstream>
#include "homework03/homework03.h"
#include "compare_files/compare_files.h"

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

TEST(tabs_to_spaces, all) {
  tabs_to_spaces("tab_input.txt", 2, "tab_output.txt");
  EXPECT_TRUE(compare_files("tab_output.txt", "tab_correct_result.txt"));
}
  
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

