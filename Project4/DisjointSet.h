/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include "Node.h"
#include "Graph.h"
#include <vector>

using namespace std;

class DisjointSets {
private:
    vector<Node*> disjoint_set;

public:
    DisjointSets(vector<Node*> n_set);
    DisjointSets();
    ~DisjointSets();

    Node* findSet(Node* n);
    void unionSet(Node* u, Node* v);

    friend class Graph;
};

#endif //DISJOINTSET_H