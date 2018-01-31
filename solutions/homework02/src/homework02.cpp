/***
  Copyright 2018 J. West
 */
#include <math.h>
#include <iostream>
#include "homework02/homework02.h"
unsigned int permutations(unsigned int n, unsigned int k) {
  if (n < k) {
    std::cerr << "In permutations, neither k cannot be > n"
      << std::endl;
    return 0;
  }
  unsigned int result = 1;
  for (unsigned int i = (n-k+1) ; i <=n ; i++) {
    result *= i;
  }
  return result;
}
unsigned int fact(unsigned int n) {
  // note that n==0 is automatically = 1
  unsigned int result = 1;
  for (unsigned int i = 1 ; i <= n ; i++) {
    result *= i;
  }
  return result;
}
unsigned int combinations(unsigned int n, unsigned int k) {
  if (n < k) {
    std::cerr << "In combinations, neither k cannot be > n"
      << std::endl;
    return 0;
  }
  return permutations(n, k) / fact(k);
}
