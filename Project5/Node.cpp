#include "Node.h"

//constructor
Node::Node() {
    city = "";
    degree = 0;
    parent = NULL;
    dist = 0.0;
}

//destructor
Node::~Node() {

}

//set distance function 
void Node::setDist(double d) {
    dist = d;
}

//set parent function
void Node::setParent(Node* n) {
    parent = n;
}
