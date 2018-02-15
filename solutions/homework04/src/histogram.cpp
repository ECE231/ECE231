/***
  Copyright 2018 J. West
 */
#include <iostream>
#include <string>
#include "homework04/homework04.h"
int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Create histogram from numbers in an input text file\n"
      "Usage:\n histogram <input_filename>\n";
    return -1;
  }
  if (histogram(argv[1])) {
    return 0;
  } else {
    return -1;
  }
}
