/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK03_INCLUDE_HOMEWORK03_HOMEWORK03_H_
#define HOMEWORK03_INCLUDE_HOMEWORK03_HOMEWORK03_H_
#include <string>
/*
  Encrypt a sring using a Caesar cipher using the supplied key
*/
std::string encrypt(const std::string &input, const std::string &key);
/*
  Decrypt a sring using a Caesar cipher using the supplied key
*/
std::string decrypt(const std::string &input, const std::string &key);
/*
  Convert the tabs in <input_filename> to <tabstop> spaces and
  save the result to <output_filename>
*/
void tabs_to_spaces(
  const std::string &input_filename,
  int tabstop,
  const std::string &output_filename);
#endif  // HOMEWORK03_INCLUDE_HOMEWORK03_HOMEWORK03_H_
