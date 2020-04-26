#include "Edge.h"

//constructor
Edge::Edge(Node* c1, Node* c2, double d) {
    city1 = c1;
    city2 = c2;
    dist = d;
}

//constructor
Edge::Edge() {
    city1 = NULL;
    city2 = NULL;
    dist = 0;
}

//destructor
Edge::~Edge() {

}