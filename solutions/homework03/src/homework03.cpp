/***
  Copyright 2018 J. West
 */
#include <math.h>
#include <iostream>
#include <string>
#include <fstream>
#include "homework03/homework03.h"

std::string substitute(const std::string &input,
    const std::string &key,
    const std::string &base) {
  size_t n = input.size();
  std::string result = input;
  if (base.size() != key.size()) {
    std::cerr << "ERROR! key must be same size as base" << std::endl;
    return "";
  }
  for (size_t i = 0 ; i < n ; i++) {
    size_t idx = base.find(input[i]);
    if (idx != std::string::npos) {
      result[i] = key[base.find(input[i])];
    }
  }
  return result;
}

std::string encrypt(const std::string &input, const std::string &key) {
  std::string base("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  return substitute(input, key, base);
}

std::string decrypt(const std::string &input, const std::string &key) {
  std::string base("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  return substitute(input, base, key);
}

void tabs_to_spaces(
    const std::string &input_filename,
    int tabstop,
    const std::string &output_filename
    ) {
  // create a string of tabstop spaces
  std::string spaces(tabstop, ' ');
  // open the file streams
  std::ifstream f_in(input_filename.c_str());
  std::ofstream f_out(output_filename.c_str());
  char c;
  // read the first character from the file
  f_in.get(c);
  // good() tells if the file has reached the end
  while (f_in.good()) {
    // if it is a tab, stream the spaces, otherwise just copy it
    if (c == '\t') {
      f_out << spaces;
    } else {
      f_out << c;
    }
    // read next char and loop
    f_in.get(c);
  }
}
