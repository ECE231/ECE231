/***
  Copyright 2018 J. West
 */
#include <math.h>
#include "homework00/homework00.h"
double squareRoot(const double a) {
  double b = sqrt(a);
  if (b != b) {    // nan check
    return -1.0;
  } else {
    return sqrt(a);
  }
}

