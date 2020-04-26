#ifndef QUADTREE_H
#define QUADTREE_H

#include "QuadNode.h"

class QuadTree {
private:
    unsigned int sizeTree;
    QuadNode* root;

    void insert(QuadNode* node, QuadNode* current_node);    //private function used for insert
    QuadNode* search(double x, double y, QuadNode* current_node);    //private function used for search
    unsigned int getMaxValue(QuadNode* node, std::string attr);
    unsigned int getMinValue(QuadNode* node, std::string attr);
    unsigned int getTotalValue(QuadNode* node, std::string attr);
    void printTree(QuadNode* node);
    void clearNode(QuadNode* node);

public:
    QuadTree();     //constructor
    ~QuadTree();    //destructor

    void insertInfo(std::string n, double x, double y, unsigned int p, unsigned int r, unsigned int s);
    void searchCity(double x, double y);
    void maxValue(double x, double y, std::string d, std::string attr);
    void minValue(double x, double y, std::string d, std::string attr);
    void totalValue(double x, double y, std::string d, std::string attr);
    void print();
    void clear();
    void size(); 
};

#endif //QUADTREE_H