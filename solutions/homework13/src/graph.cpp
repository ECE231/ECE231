/***
  Copyright 2018 J. West
 */
#include "homework13/graph.h"
#include <fstream>
#include <sstream>
#include <string>
#include <set>

void Graph::addNode(
    std::string start_city,
    std::string finish_city,
    double distance) {
  Node *start = insertNode(start_city);
  Node *finish = insertNode(finish_city);
  insertArc(start, finish, distance);
}

Node *Graph::insertNode(const std::string &name) {
  Node *n = findNodeByName(name);
  // if the node is not in the set, then create and add it
  if (n == NULL) {
    n = new Node;
    n->name = name;
    nodes_.insert(n);
  }
  return n;
}

Arc *Graph::insertArc(Node *start, Node * finish, double distance) {
  Arc *a = findArc(start, finish);
  // if the arc is not in the set, then create and add it
  if (a == NULL) {
    a = new Arc;
    a->start = start;
    a->finish = finish;
    a->cost = distance;
    arcs_.insert(a);
  }
  return a;
}

Node *Graph::findNodeByName(const std::string &name) {
  for (Node *n : nodes_) {
    if (n->name == name) return n;
  }
  return NULL;
}

Arc *Graph::findArc(Node *start, Node *finish) {
  for (Arc *a : arcs_) {
    if (a->start == start && a->finish == finish) return a;
  }
  return NULL;
}

std::set<Arc *> Graph::getArcsAtNode(const Node *node) {
  std::set<Arc *> arcs;
  for (Arc *a : arcs_) {
    if (a->start->name == node->name || a->finish->name == node->name) {
      arcs.insert(a);
    }
  }
  return arcs;
}

