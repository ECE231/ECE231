/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK07_INCLUDE_HOMEWORK07_OCCUPANCY_GRID_H_
#define HOMEWORK07_INCLUDE_HOMEWORK07_OCCUPANCY_GRID_H_

#include <string>
#include <vector>
#include "homework07/point.h"
#include "homework07/square.h"

class OccupancyGrid {
  public:
    /*** create a grid from the data in filename */
    explicit OccupancyGrid(const std::string &filename);
    /*** return the coordinates of the start position 
      or Point(-1,-1) if there is none */
    Point getStartPosition(void);
    /*** Check if a point is outside of the grid boundaries */
    bool isOutside(Point pt);
    /*** draw the map to the screen */
    void draw(void);
    /*** Mark a path on the map */
    void markPath(std::vector<Point> &path);
    /*** get the square at pt
      will throw std::string if outside of grid 
    */
    Square &getSquare(Point pt);
    /*** get the square from pt in direction d 
      will throw std::string if outside of grid 
      */
    Square &getSquare(Point pt, Direction d);
    /*** Get the coordinates of the square from pt in Direction d */
    Point getPoint(Point pt, Direction d);

  private:
    /*** size of the grid */
    Point size_;
    /*** grid of squares stored as grid_[rows][cols]*/
    std::vector<std::vector<Square>> grid_;

    void readFile(const std::string &filename);
    void computeSize(const std::string &filename);
    void processFile(const std::string &filename);
    void processLine(std::string line, int y);
};

std::ostream& operator<<(std::ostream &os, const OccupancyGrid &g);
#endif  // HOMEWORK07_INCLUDE_HOMEWORK07_OCCUPANCY_GRID_H_
