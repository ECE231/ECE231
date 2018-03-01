/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK06_INCLUDE_HOMEWORK06_HOMEWORK06_H_
#define HOMEWORK06_INCLUDE_HOMEWORK06_HOMEWORK06_H_
/*
   calculate the positions of the weights such that balance can be achieved 
   (if possible) 

   if it is not possible to balance, return false and set left, right
     to empty
   if it is possible, return true and set left, right to the 
     arrangement resulting in balance

   NOTE: there may be more than one solution, as long as yours
     balances, it will pass the test.

   fill left with the weights necessary to place to the 
      left of center (along with the target)
   fill right with the weights necessary to place to the right of center

   balance => left + target == right
 */

#include <vector>

bool findBalance(
    int target,
    const std::vector<int> &weights,
    std::vector<int> &left,
    std::vector<int> &right);

#endif  // HOMEWORK06_INCLUDE_HOMEWORK06_HOMEWORK06_H_
