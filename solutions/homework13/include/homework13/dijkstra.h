/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK13_INCLUDE_HOMEWORK13_DIJKSTRA_H_
#define HOMEWORK13_INCLUDE_HOMEWORK13_DIJKSTRA_H_
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <utility>

#include "homework13/graph.h"
/* 
   this is a type to hold a (possibly) multi-segment path between nodes
 */
typedef std::vector<Arc *> Path;

/*
   this is a type for our priority queue.  
   the first element is a vector of Arcs which represents a path 
   between 2 nodes
   the second is the cost of that path (distance)
 */
typedef std::pair<Path, double> QueueElement;

/*
   In order for the priority queue to be able to put the paths in 
   the desired order it needs a "<" function to compare 2 paths 
   so this overloads "<" for this type
   We can choose how the order behaves.  In this case we want shorter 
   paths to be considered better than longer paths so shorter 
   distance will have higher priority in the queue and therefore be 
   considered "greater" than longer paths
 */
bool operator<(const QueueElement &l, const QueueElement &r);

/*
   Stream a path's information
 */
std::ostream &operator<<(std::ostream &os, const Path &p);

/*
   Find the shortest path between two cities on a certian graph
   return an empty path if the cities are not on the map or there
   is no path between them
 */
Path findShortestPath(Graph &g,
    std::string startName,
    std::string finishName);

/* 
   function to make sure queue priorities work as desired
 */
void testQueue(void);
#endif  // HOMEWORK13_INCLUDE_HOMEWORK13_DIJKSTRA_H_
