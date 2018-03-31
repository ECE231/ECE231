/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK07_INCLUDE_HOMEWORK07_SOLVER_H_
#define HOMEWORK07_INCLUDE_HOMEWORK07_SOLVER_H_

#include <vector>
#include "homework07/point.h"
#include "homework07/occupancy_grid.h"
class Solver {
  public:
    std::vector<Point> solveMaze(OccupancyGrid &maze);
  private:
    std::vector<Point> best_path_;
    Point current_point_;
    void solveMazeRecursive(OccupancyGrid &maze, Point p,
        std::vector<Point> &path);
};

#endif  // HOMEWORK07_INCLUDE_HOMEWORK07_SOLVER_H_
