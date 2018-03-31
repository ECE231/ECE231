/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <iostream>
#include "homework10/editor_buffer.h"

TEST(buffer, construct) {
  EditorBuffer b;
  EXPECT_EQ(b.getCursor(), 0);
  b.insertCharacter('a');
  EXPECT_EQ(b.getCursor(), 1);
  b.insertCharacter('b');
  EXPECT_EQ(b.getCursor(), 2);
  b.insertCharacter('c');
  EXPECT_EQ(b.getCursor(), 3);
  b.insertCharacter('d');
  EXPECT_EQ(b.getCursor(), 4);
  b.insertCharacter('e');
  EXPECT_EQ(b.getCursor(), 5);
  b.insertCharacter('f');
  EXPECT_EQ(b.getCursor(), 6);
  EXPECT_STREQ(b.getText().c_str(), "abcdef");
  b.moveCursorBackward();
  EXPECT_EQ(b.getCursor(), 5);
  b.moveCursorBackward();
  EXPECT_EQ(b.getCursor(), 4);
  b.moveCursorBackward();
  EXPECT_EQ(b.getCursor(), 3);
  b.deleteCharacter();
  EXPECT_EQ(b.getCursor(), 3);
  EXPECT_STREQ(b.getText().c_str(), "abcef");
  b.moveCursorForward();
  EXPECT_EQ(b.getCursor(), 4);
  b.insertCharacter('!');
  EXPECT_STREQ(b.getText().c_str(), "abce!f");
  EXPECT_EQ(b.getCursor(), 5);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

