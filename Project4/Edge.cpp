/* 
Name: Emily Luong
StudentID: e4luong
*/

#include "Edge.h"
#include <string>

//default constructor 
Edge::Edge() {
    weight = 0.0;
    ver1 = NULL;
    ver2 = NULL;
}

//overloading constructor
Edge::Edge(Node* v1, Node* v2, double w) {
    weight = w;
    ver1 = v1;
    ver2 = v2;
}

//default deconstructor
Edge::~Edge() {
    
}