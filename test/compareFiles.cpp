/*** Copyright 2018 J. West */
#include <fstream>
bool compareFiles(const std::string &file1, const std::string &file2) {
  std::ifstream f1(file1.c_str());
  std::ifstream f2(file2.c_str());
  while(f1.good() && f2.good()) {
    char c1, c2;
    f1.get(c1);
    f2.get(c2);
    if (c1 != c2) {
      return false;
    }
  }
  return true;
}

