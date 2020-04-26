#ifndef ADJNODE_H
#define ADJNODE_H

#include <string>

using namespace std;

class AdjNode {
private:
    string city;
    double dist;

public:
    AdjNode();      //default constructor
    ~AdjNode();     //destructor

    friend class Graph;
    friend class Node;
};

#endif //ADJNODE_H