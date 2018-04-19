/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK12_INCLUDE_HOMEWORK12_FAMILY_TREE_H_
#define HOMEWORK12_INCLUDE_HOMEWORK12_FAMILY_TREE_H_
#include <string>
#include <iostream>

struct FamilyTreeNode {
  std::string name;
  FamilyTreeNode *child;
  FamilyTreeNode *sibling;
};

void displayFamilyTree(FamilyTreeNode *tree);
FamilyTreeNode *readFamilyTree(const std::string &filename);
void deleteTree(FamilyTreeNode *tree);

#endif  // HOMEWORK12_INCLUDE_HOMEWORK12_FAMILY_TREE
