/***
  Copyright 2018 J. West
 */
#include <vector>
#include <iostream>
#include "homework06/homework06.h"

bool balance(
    int target,
    std::vector<int> &left,
    std::vector<int> &right,
    std::vector<int> &unused
    ) {
  // add up all of the weight on left and right
  int sum_left = target;
  for (int i : left) sum_left += i;
  int sum_right = 0;
  for (int i : right) sum_right += i;

#if DEBUG
  int sum_ctr = 0;
  for (int i : unused) sum_ctr += i;
  std::cout << "L\tC\tR\n";
  std::cout << sum_left << '\t' << sum_ctr << '\t' << sum_right << std::endl;
#endif

  // this is the only successfull exit condition
  if (sum_left == sum_right) return true;

  // if there are no unused weights left, then we failed
  if (unused.size() == 0) return false;

  // take weight off of unused
  int w = unused.back();
  unused.pop_back();
  // try to balance without the weight
  if (balance(target, left, right, unused)) return true;
  // move weight to left and try again
  left.push_back(w);
  if (balance(target, left, right, unused)) return true;
  // move weight to right and try again
  left.pop_back();
  right.push_back(w);
  if (balance(target, left, right, unused)) return true;
  // if none of those can balance, restore the stacks 
  // to their origianl states and and return false
  right.pop_back();
  unused.push_back(w);
  return false;
}

bool findBalance(
    int target,
    const std::vector<int> &weights,
    std::vector<int> &left,
    std::vector<int> &right
    ) {
  // first move all of the weights to the unused
  std::vector<int> unused(weights);
  // then call the recursive function
  if (balance(target, left, right, unused)) {
    return true;
  } else {
    return false;
  }
}

