#ifndef QUADNODE_H
#define QUADNODE_H

#include <string>

class QuadNode {
private:
    //city information
    std::string city;
    double longitude;
    double latitude;
    unsigned int population;
    unsigned int livingcost;
    unsigned int netsalary;
    
    QuadNode* NW; 
    QuadNode* NE;
    QuadNode* SW;
    QuadNode* SE;

public:
    friend class QuadTree;

    QuadNode();     //constructor
    QuadNode(std::string n, double x, double y, unsigned int p, unsigned int r, unsigned int s);     //overloading constructor
};

#endif //QUADNODE_H