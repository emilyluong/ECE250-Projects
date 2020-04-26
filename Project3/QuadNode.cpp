#include "QuadNode.h"

QuadNode::QuadNode() {
    city = "";
    longitude = 0.0;
    latitude = 0.0;
    population = 0;
    livingcost = 0;
    netsalary = 0;

    NW = NULL, NE = NULL, SW = NULL, SE = NULL;
}

QuadNode::QuadNode(std::string n, double x, double y, unsigned int p, unsigned int r, unsigned int s) {
    city = n;
    longitude = x;
    latitude = y;
    population = p;
    livingcost = r;
    netsalary = s;

    NW = NULL, NE = NULL, SW = NULL, SE = NULL;
}