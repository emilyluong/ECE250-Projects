#ifndef NODE_H
#define NODE_H

#include "AdjNode.h"
#include <string>
#include <vector>

using namespace std;

class Node {
private:
    string city;
    int degree;
    vector <AdjNode> adj_list;

    Node* parent;
    double dist;

public:
    Node();     //default constructor
    ~Node();     //destructor

    void setDist(double d);     //declaration of setting distance function
    void setParent(Node* n);    //declaration of setting parent function

    friend class AdjNode;
    friend class Graph;
    friend class PriorityQueue;
    friend class Edge;
};

#endif //NODE_H