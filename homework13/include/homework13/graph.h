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
   Only has the name of the city
 */
struct Node {
  std::string name;
};

/* 
   an arc represents a connection between two nodes 
   and stores the distance between them
   The values are pointers to the nodes.
   The cost is the distance between citites
 */
struct Arc {
  Node *start;
  Node *finish;
  double cost;
};

/***
   the Graph class is the set of all of the Nodes and Arcs
   and the functions to manipulate them
 */
class Graph {
  public:
    /*** 
       read a csv file with paths and distance between cities like:
       Atlanta,Chicago,599
       and create all of the Nodes and Arcs in the graph
       I wrote this for you.  It is in graph_base.cpp
     */
    void readFromFile(const std::string &filename);

    /***
     * find all of the arcs that connect to a specific node
     * return an empty set if there are none
     */
    std::set<Arc *> getArcsAtNode(const Node *);

    /***
     * get pointer to the node with this name
     * return NULL if it does not exist
     */
    Node *findNodeByName(const std::string &name);

  private:
    // data sets of pointers to the arcs and nodes
    std::set<Arc *> arcs_;
    std::set<Node *> nodes_;

    /*** 
     * add a node to the graph.  
     * Given the names of the start and finish cities and the distance 
     * between them, add the nodes and arcs to the graph.
     * If either city or the arc is already in the graph, you must 
     * not duplicate it. 
     * This function is called when reading the file to create the graph.
     */
    void addNode(std::string start_city, std::string end_city, double distance);

    /***
     * insert an arc into the graph, if it already exists then do nothing
     * This should be called by the addNode() function to insert an 
     * arc between two cities.
     */
    Arc *insertArc(Node *start, Node * end, double distance);

    /***
     * insert a node into the graph, if it already exists then do nothing
     * This should be called from addNode() to add a city to the graph
     */
    Node *insertNode(const std::string &name);

    /***
     * get pointer to Arc between two nodes, return NULL if it does not exist
     * This is 
     */
    Arc *findArc(Node *start, Node *end);

    /***
     * stream the graph to the output.
     * I wrote this for you, it is in graph_base.cpp
     */
    friend std::ostream &operator<<(std::ostream &, const Graph &);
};
/*
   stream the graph information
 */
std::ostream &operator<<(std::ostream &, const Graph &);

#endif  // HOMEWORK13_INCLUDE_HOMEWORK13_GRAPH_H_
