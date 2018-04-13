/***
  Copyright 2018 J. West
 */
#ifndef HOMEWORK13_INCLUDE_HOMEWORK13_GRAPH_H_
#define HOMEWORK13_INCLUDE_HOMEWORK13_GRAPH_H_
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <queue>

/*
   a structure for a node on the graph
 */
struct Node {
  std::string name;
};

/* 
   an arc represents a connection between two nodes 
   and stores the distance between them
 */
struct Arc {
  Node *start;
  Node *finish;
  double cost;
};

/*
   the Graph is the set of all of the Nodes and Arcs
 */
class Graph {
  public:
    /* 
       read a csv file with paths and distance between cities like:
       Atlanta,Chicago,599
       and create all of the Nodes and Arcs in the graph
     */
    void readFromFile(const std::string &filename);

    // find all of the arcs that connect to a specific node
    std::set<Arc *> getArcsAtNode(const Node *);

    // get pointer to node with this name, return NULL if it does not exist
    Node *findNodeByName(const std::string &name);

  private:
    // data sets of pointers to the arcs and nodes
    std::set<Arc *> arcs_;
    std::set<Node *> nodes_;

    // add a node to the graph
    void addNode(std::string start_city, std::string end_city, double distance);

    // insert an arc into the graph, if it already exists then do nothing
    Arc *insertArc(Node *start, Node * end, double distance);

    // insert a node into the graph, if it already exists then do nothing
    Node *insertNode(const std::string &name);

    // get pointer to Arc between two nodes, return NULL if it does not exist
    Arc *findArc(Node *start, Node *end);

    friend std::ostream &operator<<(std::ostream &, const Graph &);
};
/*
   stream the graph information
 */
std::ostream &operator<<(std::ostream &, const Graph &);

#endif  // HOMEWORK13_INCLUDE_HOMEWORK13_GRAPH_H_
