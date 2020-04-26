#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "AdjNode.h"
#include "Edge.h"
#include "PriorityQueue.h"
#include <vector>
#include <string>

using namespace std;

class Graph {
private:
    vector <Node*> node_list;
    vector <Edge> edge_list;
    int num_node;
    int num_edge;

public:
    Graph();    //constructor
    ~Graph();   //destructor

    void insertNode(string c);                          //insert node to graph function
    void setDistance(string c1, string c2, double d);   //sets distance between two cities function
    bool cityFound(string c);                           //helper function to find city c in graph
    void searchCity(string c);                          //search city in graph function
    void degreeCity(string c);                          //prints out degree of city function
    void printNodes();                                  //prints out number of nodes in the graph
    void printEdges();                                  //prints out number of edges in the graph
    void printDistance(string c1, string c2);           //prints out the distance between 2 cities
    void clearGraph();                                  //clears the graph 
    void relax(Node* u, Node* v);                       //relax function used in Dijkstra algorithm
    void dijkstraAlgo(string c1, string c2);            //dijstra algorithm 
    void shortestDistance(string c1, string c2);        //gets the shortest distance from c1 to c2
    void printPath(string c1, string c2);               //prints shortest path from c1 to c2
};

#endif //GRAPH_H