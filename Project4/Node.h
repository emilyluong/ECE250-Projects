/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef NODE_H
#define NODE_H

class Node {
private:
    int key;
    Node* parent;
    Node* next;

public:
    Node();
    ~Node();

    friend class DisjointSets;
    friend class Graph;
    friend class Edge;
};

#endif //NODE_H