/***
  Copyright 2018 J. West
 */
#include <math.h>
#include <iostream>
#include "homework01/homework01.h"
double calculatePi(const int numOfDivisions) {
  double r = 2.0;
  if (numOfDivisions < 1) {
    std::cerr << "numOfDivisions cannot be zero or negative" << std::endl;
    return 0.0;
  }
  double step = r/numOfDivisions;
  double totalArea = 0.0;

  for (int i = 0 ; i < numOfDivisions ; i++) {
    double x = i*step + step/2.0;
    double y = sqrt(r*r - x*x);
    double rectArea = step*y;
    totalArea += rectArea;
  }
  return totalArea;
}

