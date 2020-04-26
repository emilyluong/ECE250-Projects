/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge {
private:
    double weight;
    Node* ver1;
    Node* ver2;

public:
    Edge();
    Edge(Node* v1, Node* v2, double w);
    
    ~Edge();

    friend class Graph;
    friend class Node;
};

#endif //EDGE_H