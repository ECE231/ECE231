/***
  Copyright 2018 J. West
 */
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "homework07/occupancy_grid.h"
#include "homework07/solver.h"

int main(int argc, char** argv) {
  try {
    OccupancyGrid m(argv[1]);
    m.draw();
    Solver s;
    std::vector<Point> path = s.solveMaze(m);
    std::cout << "Best path has length " << path.size() << std::endl;
    m.markPath(path);
    m.draw();
    std::ofstream outfile("output.txt");
    for (auto const p : path) {
      outfile << p << std::endl;
    }
  } catch(const std::string & e) {
    std::cerr << "Exception: " << e;
  }
  return 0;
}
