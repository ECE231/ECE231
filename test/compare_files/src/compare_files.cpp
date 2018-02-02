/*** Copyright 2018 J. West */
#include <fstream>
#include <iostream>
#include "compare_files/compare_files.h"
/*
 compare 2 text files. return true if identical otherwise false.
 */
bool compare_files(const std::string &file1, const std::string &file2) {
  std::ifstream f1(file1.c_str());
  if (f1.fail()) {
    std::cerr << "could not open input file " << file1 << std::endl;
    return false;
  }
  std::ifstream f2(file2.c_str());
  if (f2.fail()) {
    std::cerr << "could not open input file " << file2 << std::endl;
    return false;
  }
  while(f1.good() && f2.good()) {
    char c1, c2;
    f1.get(c1);
    f2.get(c2);
    if (c1 != c2) {
      std::cerr << "File content does not match\n";
      return false;
    }
  }
  if (f1.good() != f2.good()) {
    std::cout << "Files are not the same length\n";
    return false;
  }
  return true;
}
