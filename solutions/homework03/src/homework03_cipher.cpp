/***
  Copyright 2018 J. West
 */
#include "homework03/homework03.h"
#include <string>
#include <iostream>
int main() {
  std::string input("WORKERS OF THE WORLD UNITE!");
  std::string key("QWERTYUIOPASDFGHJKLZXCVBNM");
  std::string encrypted = encrypt(input, key);
  std::cout << encrypted << std::endl;
  std::cout << decrypt(encrypted, key) << std::endl;
  return 0;
}
