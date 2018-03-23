/***
  Copyright 2018 J. West
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "homework07/occupancy_grid.h"

OccupancyGrid::OccupancyGrid(const std::string &filename) {
  readFile(filename);
}

Point OccupancyGrid::getStartPosition() {
  for (int r = 0 ; r < size_.y ; r++) {
    for (int c = 0 ; c < size_.x ; c++) {
      if (grid_[r][c].state() == START) return Point(c, r);
    }
  }
  return Point(-1, -1);
}

bool OccupancyGrid::isOutside(Point pt) {
  return pt.x < 0 || pt.x >= size_.x || pt.y < 0 || pt.y >= size_.y;
}

Point OccupancyGrid::getPoint(Point pt, Direction d) {
  Point p = pt;
  if (d == N) p.y--;
  else if (d == S) p.y++;
  else if (d == E) p.x++;
  else if (d == W) p.x--;
  return p;
}

Square &OccupancyGrid::getSquare(Point pt) {
  if (isOutside(pt)) throw std::string("Coordinates (" + pt.to_string() +
      " are out of range of map size " + size_.to_string());
  return grid_[pt.y][pt.x];
}

Square &OccupancyGrid::getSquare(Point pt, Direction d) {
  return getSquare(getPoint(pt, d));
}

void OccupancyGrid::readFile(const std::string &filename) {
  computeSize(filename);

  // create an empty maze of the appropriate size
  grid_.resize(size_.y);
  for (auto &row : grid_) row.resize(size_.x);

  processFile(filename);
  if (getStartPosition().x == -1)
    throw std::string("Maze contains no start square");
}

void OccupancyGrid::computeSize(const std::string &filename) {
  std::ifstream infile(filename);
  if (infile.fail()) throw std::string("computeSize Can't open "
      + filename);
  std::string line;
  size_.x = 0;
  size_.y = 0;
  while (getline(infile, line)) {
    if (line.size() > size_.x) size_.x = line.size();
    size_.y++;
  }
  size_ = Point(size_.y, size_.x);
  std::cout << "Map size = " << size_ << std::endl;
  infile.close();
}

void OccupancyGrid::processFile(const std::string &filename) {
  std::ifstream infile(filename);
  if (infile.fail()) throw std::string("ProcessFile Can't open "
      + filename);
  std::string line;
  for (int y = 0; y < size_.y ; y++) {
    getline(infile, line);
    processLine(line, y);
  }
  if (getStartPosition().x == -1) throw std::string("Map file "+filename+
      " does not contain a start square");
}

void OccupancyGrid::processLine(std::string line, int y) {
  int len = line.length();
  for (int x = 0 ; x < len ; x++) {
    switch (line[x]) {
      case '|':
      case '+':
      case '-':
        grid_[y][x].set_state(OCCUPIED);
        break;
      case ' ':
        grid_[y][x].set_state(EMPTY);
        break;
      case 'S':
        if (getStartPosition().x != -1) {
          throw std::string("File contains multiple start squares!");
        }
        grid_[y][x].set_state(START);
        break;
    }
  }
}

void OccupancyGrid::markPath(std::vector<Point> &path) {
  for (auto p : path) {
    getSquare(p).set_state(MARKED);
  }
}

void OccupancyGrid::draw() {
  for (const auto &row : grid_) {
    for (const auto &square : row) {
      switch (square.state()) {
        case OCCUPIED:
          std::cout << '0';
          break;
        case EMPTY:
          std::cout << " ";
          break;
        case START:
          std::cout << "S";
          break;
        case MARKED:
          std::cout << "X";
          break;
      }
    }
    std::cout << std::endl;
  }
}
