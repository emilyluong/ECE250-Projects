#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

using namespace std;
 
class Edge {
private:
    Node* city1;
    Node* city2;
    double dist;

public:
    Edge(Node* c1, Node* c2, double d);     //overloading constructor
    Edge();     //default constructor
    ~Edge();    //destructor

    friend class Graph;
    friend class Node;
};

#endif //EDGE_H