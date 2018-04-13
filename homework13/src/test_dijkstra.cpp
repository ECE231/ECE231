/***
  Copyright 2018 J. West
 */
#include <iostream>
#include "homework13/dijkstra.h"
int main(int argc, char **argv) {
  if (argc != 4) {
    std::cerr << "Arguments: <graph filename> <Start City> <End City>\n";
    return -1;
  }
  Graph g;
  g.readFromFile(argv[1]);
  std::cout << g;
  Path p = findShortestPath(g, argv[2], argv[3]);
  if (p.empty()) {
    std::cout << " No path exists from " << argv[2] << " to " <<
      argv[3] << std::endl;
  } else {
    std::cout << p;
  }
  //  testQueue();
  return 0;
}
