/***
  Copyright 2018 J. West
 */
#include "homework13/graph.h"
#include <fstream>
#include <sstream>
#include <string>

void Graph::readFromFile(const std::string &filename) {
  std::ifstream inf(filename);
  if (!inf.good()) {
    throw std::runtime_error("Could not open file "+filename);
  }
  std::string line;
  while (std::getline(inf, line)) {
    std::string city_start, city_finish;
    double distance;
    std::stringstream ss(line);
    if (!std::getline(ss, city_start, ',') ||
        !std::getline(ss, city_finish, ',') ||
        !(ss >> distance)) {
      throw std::runtime_error("Bad data line" + line);
    }
    addNode(city_start, city_finish, distance);
  }
}

std::ostream &operator<<(std::ostream &os, const Graph &g) {
  os << "Graph has " << g.nodes_.size() << " nodes and " <<
    g.arcs_.size() << " arcs\n";
  os << "Nodes:\n";
  for (Node *n : g.nodes_) {
    os << '\t' <<  n->name << std::endl;
  }
  os << "Arcs:\n";
  for (Arc *a : g.arcs_) {
    os << '\t' << a->start->name << " to " <<
      a->finish->name << " " << a->cost << " miles\n";
  }
  return os;
}
