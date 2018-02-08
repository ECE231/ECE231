/***
  Copyright 2018 J. West
 */
#include "homework03/homework03.h"
#include <iostream>
#include <string>
int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "replace tabs in <input_filename> with <tabstop> spaces and\n"
      "write to <output_filname>\n"
      "Usage:\n homework03_main <input_filename>"
      " <tabstop> <output_filename\n";
    return -1;
  }
  tabs_to_spaces(argv[1], std::stoi(argv[2]), argv[3]);
  return 0;
}
