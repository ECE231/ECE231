/***
  Copyright 2018 J. West
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "homework09/IntArray.h"
#define NUM 10
int main(int argc, char** argv) {
  IntArray a(NUM);
  std::cout << "Size is "<<a.size()<<std::endl;
  a[0] = a[1] = 1234;
  a.put(4, 44);
  std::cout << "a[0,1]= " << a[0] << ", " << a.get(1) << " a[4] = " <<
      a[4]<< std::endl;
  try {
    a[NUM] = 5;
  } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
  }
  try {
    a.get(-1);
  } catch(const std::out_of_range & e) {
    std::cerr << "EXCEPTION:  " << e.what() << std::endl;
  }
  return 0;
}
