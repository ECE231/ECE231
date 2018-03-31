/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK07_INCLUDE_HOMEWORK07_POINT_H_
#define HOMEWORK07_INCLUDE_HOMEWORK07_POINT_H_

#include <string>
#include <vector>

class Point {
  public:
  Point(void) {x = y = 0;}
  Point(int new_x, int new_y) {x = new_x; y = new_y;}
  std::string to_string(void);
  int x, y;
};

std::ostream &operator<<(std::ostream &os, Point p);

#endif  // HOMEWORK07_INCLUDE_HOMEWORK07_POINT_H_
