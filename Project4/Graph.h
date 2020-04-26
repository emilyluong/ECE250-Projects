/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include "Edge.h"
#include "illegal_argument.h"
#include "DisjointSet.h"
#include <vector>

using namespace std;

class Graph {
private:
    int node_num;
    int edge_num;
    vector<Node*> nodes;
    vector<Edge> e_set;
    double** adj_matrix;
 
public:
    Graph(int n);   
    Graph();     

    ~Graph();

    void insertEdge(int u, int v, double w);
    void deleteEdge(int u, int v);
    void degreeVertex(int u);
    void edgeTotal();
    void clearGraph();
    void resetNodes();
    void kruskalMST();
};

#endif //GRAPH_H
