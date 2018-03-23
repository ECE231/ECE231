/***
  Copyright 2018 J. West
 */
#include <iostream>
#include <vector>
#include "homework07/solver.h"
std::vector<Point> Solver::solveMaze(OccupancyGrid &maze) {
  std::vector<Point> path;
  Point start_pt = maze.getStartPosition();
  // clear start square so it will not require special treatment in rec
  maze.getSquare(start_pt).set_state(EMPTY);
  solve_rec(maze, start_pt, path);
  // restore start square
  maze.getSquare(start_pt).set_state(START);
  return best_path_;
}

void Solver::solve_rec(
    OccupancyGrid &maze,
    const Point &pt,
    std::vector<Point> &current_path) {
  // if current_path is a solution then we will be outside of the maze
  if (maze.isOutside(pt)) {
    // if current_path is better than the last discovered best_path_ then
    // save it as the new best_path_
    if (best_path_.empty() || best_path_.size() > current_path.size()) {
      best_path_ = current_path;
    }
    return;
  }
  // if this point cannot be occupied then we are at an end so return
  if (maze.getSquare(pt).state() != EMPTY) return;
  // otherwise add this point to the path and mark it
  current_path.push_back(pt);
  maze.getSquare(pt).set_state(MARKED);
  // go in all of the directions
  solve_rec(maze, maze.getPoint(pt, N), current_path);
  solve_rec(maze, maze.getPoint(pt, E), current_path);
  solve_rec(maze, maze.getPoint(pt, S), current_path);
  solve_rec(maze, maze.getPoint(pt, W), current_path);
  // backtrack by removing this pt from the path and unmarking it
  current_path.pop_back();
  maze.getSquare(pt).set_state(EMPTY);
}
