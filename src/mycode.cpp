/***
  Copyright 2018 J. West
 */
#include <math.h>
#include "ECE231/mycode.h"
double squareRoot(const double a) {
  double b = sqrt(a);
  if (b != b) {    // nan check
    return -1.0;
  } else {
    return sqrt(a);
  }
}

