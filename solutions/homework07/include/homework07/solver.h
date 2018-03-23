/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK07_INCLUDE_HOMEWORK07_SOLVER_H_
#define HOMEWORK07_INCLUDE_HOMEWORK07_SOLVER_H_
#include <vector>
#include "homework07/occupancy_grid.h"

class Solver {
  public:
    std::vector<Point> solveMaze(OccupancyGrid &maze);
  private:
    void solve_rec(
        OccupancyGrid &maze,
        const Point &pt,
        std::vector<Point> &current_path);

    std::vector<Point> best_path_;
};

#endif  // HOMEWORK07_INCLUDE_HOMEWORK07_SOLVER_H_
