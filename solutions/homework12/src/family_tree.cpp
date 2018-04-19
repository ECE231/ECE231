/***
  Copyright 2018 J. West
 */
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include "homework12/family_tree.h"

FamilyTreeNode *findName(FamilyTreeNode *head, const std::string &name) {
  FamilyTreeNode *n = NULL;
  if (head->name == name) {
    return head;
  }
  // follow children first
  if (head->child != NULL) {
    if((n = findName(head->child, name)) != NULL) return n;
  }
  // then follow siblings
  if (head->sibling != NULL) {
    if((n = findName(head->sibling, name)) != NULL) return n;
  }
  return NULL;
}

FamilyTreeNode *add(FamilyTreeNode *head, 
    const std::string &parent_name, 
    const std::string &child_name) {
  FamilyTreeNode *n;
  // first find the parent
  n = findName(head, parent_name);
  if (n == NULL) {
    throw std::runtime_error(parent_name + " is not in the tree");
  }
  // if this parent has no children then add this one
  if(n->child == NULL) {
    n->child = new FamilyTreeNode;
    n->child->name = child_name;
    n->child->child = NULL;
    n->child->sibling = NULL;
  } else {  
    n = n->child;
    // otherwise go to the last sibling under this parent and add child
    while(n->sibling != NULL) {
      n = n->sibling;
    }
    n->sibling = new FamilyTreeNode;
    n->sibling->name = child_name;
    n->sibling->child = NULL;
    n->sibling->sibling = NULL;
  }
}

void display(FamilyTreeNode *head, std::string indent) {
  std::cout << indent << head->name << std::endl;
  // follow children first
  if (head->child != NULL) {
    display(head->child, indent + "  ");
  }
  // then follow siblings
  if (head->sibling != NULL) {
    display(head->sibling, indent);
  }
}
void displayFamilyTree(FamilyTreeNode *head) {
  display(head, "");
}

FamilyTreeNode *readFamilyTree(const std::string &filename) {
  std::ifstream inf(filename);
  if(!inf.good()) {
    throw std::runtime_error("Unable to open file "+filename);
  }
  std::string line;
  std::string head_name;
  if(!std::getline(inf, head_name)) {
    throw std::runtime_error("File contains no head!");
  }
  FamilyTreeNode *head = new FamilyTreeNode;
  head->name = head_name;
  head->child = head->sibling = NULL;
  while(std::getline(inf, line)) {
    size_t idx = line.find(":");
    if (idx == std::string::npos) {
      throw std::runtime_error("Bad line "+line+" in file");
    }
    std::string child = line.substr(0,idx);
    std::string parent = line.substr(idx+1);
    add(head, parent, child);
  }
  return head;
}

void deleteTree(FamilyTreeNode *head) {
  if(head == NULL) return;
  deleteTree(head->child);
  deleteTree(head->sibling);
  std::cout << "Killing " << head->name << std::endl;
  delete head;
}
