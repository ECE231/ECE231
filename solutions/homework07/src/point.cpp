/***
  Copyright 2018 J. West
 */

#include <iostream>
#include <string>
#include "homework07/point.h"
std::string Point::to_string(void) {
  return std::string("("+std::to_string(x)+","+std::to_string(y)+")");
}

std::ostream &operator<<(std::ostream &os, Point p) {
  return os << p.to_string();
}
