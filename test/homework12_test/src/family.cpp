#include <iostream>
#include "homework12/family_tree.h"
int main(int argc, char **argv) {
  if(argc!=2) {
    std::cerr << "need filename\n";
    return 1;
  }
  FamilyTreeNode *head = readFamilyTree(argv[1]);
  displayFamilyTree(head);
  return 0;
}
