/***
  Copyright 2018 J. West
 */
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include "homework04/homework04.h"

bool histogram(const std::string &filename) {
  // try to open the file
  std::ifstream inf(filename);
  if (inf.fail()) {
    std::cerr << "Could not open input file " << filename << std::endl;
    return false;
  }
  // read the file into a vector of values
  std::string line;
  std::getline(inf, line);
  std::vector<int> values;
  int line_number = 1;
  while (inf.good()) {
    try {
      values.push_back(std::stoi(line));
    } catch (const std::invalid_argument& exp) {
      std::cerr << "\"" << line <<
        "\" is not a vaild integer number on line " <<
        line_number << std::endl << exp.what() << std::endl;

      return false;
    } catch (const std::out_of_range& exp) {
      std::cerr << "\"" << line <<
        "\" is out of range for an integer number on line " <<
        line_number << std::endl << exp.what() << std::endl;
      return false;
    }
    std::getline(inf, line);
    line_number++;
  }

  // make a map for the histogram
  // the key is the lower bound of the bin range
  // the value is the number of values in the bin
  std::map<int, int> hist;
  // bins are every ten values starting at 0 and going to 100
  // this sets the keys and initializes the counts to 0
  for (int i = 0 ; i <= 100; i+=10) {
    hist[i] = 0;
  }
  // for each value, calcualte the index by rounding off the ones place
  // digit and then increment that map value
  for (const auto &val : values) {
    int idx = (val/10) * 10;
    hist[idx] += 1;
  }
  // print out the histogram according to the assignment
  for (const auto &map_val : hist) {
    std::string delimiter;
    if (map_val.first == 0) {
      delimiter = "0s: ";
    } else if (map_val.first < 100) {
      delimiter = "s: ";
    } else {
      delimiter = ": ";
    }
    std::cout << map_val.first << delimiter;
    for (int i = 0 ; i < map_val.second ; i++) {
      std::cout << "*";
    }
    std::cout << std::endl;
  }
}
