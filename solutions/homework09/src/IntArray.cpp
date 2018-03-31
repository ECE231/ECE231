/***
  Copyright 2018 J. West
 */

#include <iostream>
#include <fstream>
#include <string>
#include "homework09/IntArray.h"
IntArray::IntArray(unsigned int n) {
  size_ = n;
  data_ = new int[n];
  for (unsigned int i = 0 ; i < n ; ++i) data_[i]=0;
}
IntArray::~IntArray(void) {
  delete []data_;
}
int IntArray::size(void) {
  return size_;
}
int IntArray::get(unsigned int k) {
  checkIndex(k);
  return data_[k];
}
void IntArray::put(unsigned int k, int value) {
  checkIndex(k);
  data_[k] = value;
}
int &IntArray::operator[](unsigned int k) {
  checkIndex(k);
  return data_[k];
}
void IntArray::checkIndex(unsigned int k) {
  if (k >= size_)
    throw std::out_of_range("Tried to index element "+ std::to_string(k) +
        " but valid range is [0 to " + std::to_string(size_-1) + "]");
}
