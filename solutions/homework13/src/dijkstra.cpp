/***
  Copyright 2018 J. West
 */
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <queue>
#include "homework13/dijkstra.h"

Path findShortestPath(Graph &g, Node *start, Node *finish);
double getPathCost(const Path &path);

std::ostream &operator<<(std::ostream &os, const Path &p) {
  os << "Path has " << p.size() << " segments and " << getPathCost(p) <<
    " miles\n";
  for (Arc *a : p) {
    os << a->start->name << " to " << a->finish->name << " " <<
      a->cost << " miles\n";
  }
  return os;
}

Path findShortestPath(Graph &g,
    std::string startName,
    std::string finishName) {
  Node *start = g.findNodeByName(startName);
  Node *finish = g.findNodeByName(finishName);
  if (start == NULL || finish == NULL) {
    throw std::runtime_error("Nodes not found" + startName + "," + finishName);
  }
  return findShortestPath(g, start, finish);
}

Path findShortestPath(Graph &g, Node *start, Node *finish) {
  std::cout << "looking for path from " << start->name << " to " <<
    finish->name << std::endl;
  Path path;
  std::priority_queue<QueueElement> queue;
  std::map<std::string, double> fixed;
  while (start != finish) {
    if (fixed.find(start->name) == fixed.end()) {
      fixed[start->name] = getPathCost(path);
      for (Arc *arc : g.getArcsAtNode(start)) {
        if (fixed.find(arc->finish->name) == fixed.end()) {
          path.push_back(arc);
          QueueElement q;
          q.first = path;
          q.second = getPathCost(path);
          queue.push(q);
          path.pop_back();
        }
      }
    }
    if (queue.empty()) {
      path.clear();
      return path;
    }
    path = queue.top().first;
    queue.pop();
    start = path.back()->finish;
  }
  return path;
}

double getPathCost(const Path &path) {
  double cost = 0;
  for (Arc *arc : path) {
    cost += arc->cost;
  }
  return cost;
}

bool operator<(const QueueElement &l, const QueueElement &r) {
  // notice that the operator is for priority so smaller value is
  // greater priority
  return l.second > r.second;
}

void testQueue(void) {
  std::priority_queue<QueueElement> queue;
  QueueElement q;
  Path path;
  q.first = path;
  q.second = 5;
  queue.push(q);
  q.second = 7;
  queue.push(q);
  q.second = 2;
  queue.push(q);
  q.second = 12;
  queue.push(q);
  q.second = 0;
  queue.push(q);
  while (!queue.empty()) {
    std::cout << queue.top().second << std::endl;
    queue.pop();
  }
}

