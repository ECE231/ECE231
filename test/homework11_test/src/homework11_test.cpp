/*** Copyright 2018 J. West */
#include <gtest/gtest.h>
#include <iostream>
#include "homework11/priority_queue.h"

TEST(queue, function) {
  PriorityQueue<std::string> q;
  EXPECT_EQ(q.size(), 0);
  EXPECT_TRUE(q.isEmpty());
  q.enqueue("Student 10", 10);
  q.enqueue("Student 6", 6);
  q.enqueue("Student 7", 7);
  q.enqueue("Dr. West", 1);
  q.enqueue("Student 9", 9);
  q.enqueue("Student 8", 8);
  EXPECT_EQ(q.size(), 6);
  EXPECT_FALSE(q.isEmpty());
  EXPECT_STREQ(q.peek().c_str(), "Dr. West");
  EXPECT_STREQ(q.dequeue().c_str(), "Dr. West");
  EXPECT_EQ(q.size(), 5);
  EXPECT_STREQ(q.peek().c_str(), "Student 6");
  EXPECT_EQ(q.size(), 5);
  EXPECT_STREQ(q.dequeue().c_str(), "Student 6");
  EXPECT_STREQ(q.dequeue().c_str(), "Student 7");
  EXPECT_STREQ(q.dequeue().c_str(), "Student 8");
  EXPECT_STREQ(q.dequeue().c_str(), "Student 9");
  EXPECT_STREQ(q.dequeue().c_str(), "Student 10");
  EXPECT_EQ(q.size(), 0);
  EXPECT_TRUE(q.isEmpty());
  bool exception = false;
  try {q.dequeue();} catch(std::runtime_error) {exception = true;}
  EXPECT_TRUE(exception);
  exception = false;
  try {q.peek();} catch(std::runtime_error) {exception = true;}
  EXPECT_TRUE(exception);
}

TEST(queue, copy) {
  PriorityQueue<std::string> q;
  q.enqueue("Hello", 1);
  q.enqueue("again", 2);
  PriorityQueue<std::string> newQueue(q);
  EXPECT_EQ(newQueue.size(), 2);
  EXPECT_STREQ(newQueue.dequeue().c_str(), "Hello");
  EXPECT_STREQ(newQueue.dequeue().c_str(), "again");
  EXPECT_TRUE(newQueue.isEmpty());
  newQueue = q;
  EXPECT_EQ(newQueue.size(), 2);
  EXPECT_STREQ(newQueue.dequeue().c_str(), "Hello");
  EXPECT_STREQ(newQueue.dequeue().c_str(), "again");
  EXPECT_TRUE(newQueue.isEmpty());
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

