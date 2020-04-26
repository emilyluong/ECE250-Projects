#include <iostream>
#include "QuadNode.h"
#include "QuadTree.h"

QuadTree::QuadTree() {
    sizeTree = 0;
    root = NULL;
}

QuadTree::~QuadTree() {
    clearNode(root);
}

//Function for insertion of QuadTree
void QuadTree::insertInfo(std::string n, double x, double y, unsigned int p, unsigned int r, unsigned int s) {
    //allocate memory for a QuadNode and set it to QuadNode pointer, node
    QuadNode* node = new QuadNode(n, x, y, p, r, s);
    
    //if root of QuadTree is NULL, set the root to the allocated node
    if (root == NULL) {
        sizeTree++;
        root = node;
        std::cout << "success" << std::endl;
    } 
    //Otherwise, set a QuadNode pointer, current_node to the root. This will be used to traverse down the tree in a separate function call
    else {
        QuadNode* current_node = root;
        insert(node, current_node);
    }
}

//Helper function of insertInfo 
void QuadTree::insert(QuadNode* node, QuadNode* current_node) {
    //NE condition
    if ((node -> longitude) >= (current_node -> longitude) && (node -> latitude) > (current_node -> latitude)) {
        //If NE pointer of current_node is NULL, set that pointer to the node wanting to insert
        if (current_node -> NE == NULL){
            current_node -> NE = node;
            current_node = NULL;
            sizeTree++;
            std::cout << "success" << std::endl;
        } 
        //Otherwise, rerun function but with the current node's NE pointer being the second function argument
        else {
            insert(node, current_node -> NE);
        }
    }
    //NW condition
    else if ((node -> longitude) < (current_node -> longitude) && (node -> latitude) >= (current_node -> latitude)) {
        //If NW pointer of current_node is NULL, set that pointer to the node wanting to insert
        if (current_node -> NW == NULL) {
            current_node -> NW = node;
            current_node = NULL;
            sizeTree++;
            std::cout << "success" << std::endl;
        }
        //Otherwise, rerun function but with the current node's NW pointer being the second function argument
        else {
            insert(node, current_node -> NW);
        }
    }
    //SW condition
    else if ((node -> longitude) <= (current_node -> longitude) && (node -> latitude) < (current_node -> latitude)) {
        //If SW pointer of current_node is NULL, set that pointer to the node wanting to insert
        if (current_node -> SW == NULL) {
            current_node -> SW = node;
            current_node = NULL;
            sizeTree++;
            std::cout << "success" << std::endl;
        }
        //Otherwise, rerun function but with the current node's SW pointer being the second function argument
        else {
            insert(node, current_node -> SW);
        }
    }
    //SE condition
    else if ((node -> longitude) > (current_node -> longitude) && (node -> latitude) <= (current_node -> latitude)) {
        //If SE pointer of current_node is NULL, set that pointer to the node wanting to insert
        if (current_node -> SE == NULL) {
            current_node -> SE = node;
            current_node = NULL;
            sizeTree++;
            std::cout << "success" << std::endl;
        }
        //Otherwise, rerun function but with the current node's SE pointer being the second function argument
        else {
            insert(node, current_node -> SE);
        }
    }
    //If all the quadrants of the directions are not satisfied, the only possible reason why and because the node wanting to insert is at the current_node, this the node already exists
    else {
        current_node = NULL;
        std::cout << "failure" << std::endl;
    }
}

//Function used to search for a node in the QuadTree
void QuadTree::searchCity(double x, double y) {
    //If the tree is empty
    if (root == NULL) {
        std::cout << "not found" << std::endl;
    }
    //Otherwise, use search function to find x,y node
    else {
        QuadNode* node = search(x, y, root);
        if (node == NULL) {
            std::cout << "not found" << std::endl;
        } 
        else
            std::cout << "found " << node -> city << std::endl;
    }
}

//Helper function of searchCity, maxValue, minValue, totalValue
QuadNode* QuadTree::search(double x, double y, QuadNode* current_node) {
    if (current_node != NULL) {
        //NE condition
        if (x >= (current_node -> longitude) && y > (current_node -> latitude)) {
            //If current node NE pointer is NULL, x,y, point does not exist
            if (current_node -> NE == NULL) {
                return NULL;
            }
            //Otherwise, set current_node equal to the node of that the current node's NE pointer is pointing to
            else {
                current_node = current_node -> NE; 
                return search(x, y, current_node);
            }
        }
        //NW condition
        else if (x < (current_node -> longitude) && y >= (current_node -> latitude)) {
            //If current node NW pointer is NULL, x,y, point does not exist
            if (current_node -> NW == NULL) {
                return NULL;
            }
            //Otherwise, set current_node equal to the node of that the current node's NW pointer is pointing to
            else {
                current_node = current_node -> NW;
                return search(x, y, current_node);
            }
        }
        //SW condition
        else if (x <= (current_node -> longitude) && y < (current_node -> latitude)) {
            //If current node SW pointer is NULL, x,y, point does not exist
            if (current_node -> SW == NULL) {
                return NULL;
            }
            //Otherwise, set current_node equal to the node of that the current node's SW pointer is pointing to
            else {
                current_node = current_node -> SW;
                return search(x, y, current_node);
            }
        }
        //SE condition
        else if (x > (current_node -> longitude) && y <= (current_node -> latitude)) {
            //If current node SE pointer is NULL, x,y, point does not exist
            if (current_node -> SE == NULL) {
                return NULL;
            }
            //Otherwise, set current_node equal to the node of that the current node's SE pointer is pointing to
            else {
                current_node = current_node -> NE;
                return search(x, y, current_node);
            }
        }
        //If the x,y doesn't belong in any of the direction quadrants, the only possible place x,y can be is in the current_node
        else {
            return current_node;
        }
    }
    else {
        return NULL;
    }
}

//Function used to get max value in a direction of node with x,y
void QuadTree::maxValue(double x, double y, std::string d, std::string attr) {
    //Search for x, y from root
    QuadNode* node = search(x, y, root);
    //If x, y doesn't exist in tree, return failure
    if (node == NULL) {
        std::cout << "failure" << std::endl;
    }
    //Otherwise, check the direction from the x, y
    else {
        if (d == "NW") {
            //If NW pointer of x, y is NULL, the direction trying to find max is empty
            if (node -> NW == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMaxValue function
            else {
                unsigned int max = getMaxValue(node -> NW, attr);
                std::cout << "max " << max << std::endl;  
            }
        }
        else if (d == "NE") {
            //If NE pointer of x, y is NULL, the direction trying to find max is empty
            if (node -> NE == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMaxValue function
            else {
                unsigned int max = getMaxValue(node -> NE, attr);
                std::cout << "max " << max << std::endl;  
            }
        }
        else if (d == "SW") {
            //If SW pointer of x, y is NULL, the direction trying to find max is empty
            if (node -> SW == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMaxValue function
            else {
                unsigned int max = getMaxValue(node -> SW, attr);
                std::cout << "max " << max << std::endl;
            }
        }
        else if (d == "SE") {
            //If SE pointer of x, y is NULL, the direction trying to find max is empty
            if (node -> SE == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMaxValue function
            else {
                unsigned int max = getMaxValue(node -> SE, attr);
                std::cout << "max " << max << std::endl;
            }
        }
    }
} 

//Helper function of maxValue
unsigned int QuadTree::getMaxValue(QuadNode* node, std::string attr) {
    unsigned int maxValueNE = 0, maxValueNW = 0, maxValueSE = 0, maxValueSW = 0, current_value = 0, maxValue = 0;
    //If there are more nodes at the current NE pointer, recursively get max value from NE quadrant 
    if (node -> NE != NULL){
        maxValueNE = getMaxValue(node -> NE, attr);
    }
    //If there are more nodes at the current NW pointer, recursively get max value from NW quadrant 
    if (node -> NW != NULL){
        maxValueNW = getMaxValue(node -> NW, attr);
    }
    //If there are more nodes at the current SE pointer, recursively get max value from SE quadrant 
    if (node -> SE != NULL){
        maxValueSE = getMaxValue(node -> SE, attr);
    }
    //If there are more nodes at the current SW pointer, recursively get max value from SW quadrant 
    if (node -> SW != NULL){
        maxValueSW = getMaxValue(node -> SW, attr);
    }

    //Check the attribute wanting to find the max of and set the current value to that 
    if (attr == "p")
        current_value = node -> population;
    else if (attr == "r")
        current_value = node -> livingcost;
    else if (attr == "s")
        current_value = node -> netsalary;

    //Return the max value
    return maxValue = std::max(current_value, std::max(maxValueSW, std::max(maxValueSE, std::max(maxValueNW, maxValueNE))));
}


//Function used to get min value in a direction of node with x,y
void QuadTree::minValue(double x, double y, std::string d, std::string attr) {
    //Search for x, y from root
    QuadNode* node = search(x, y, root);
    //If x, y doesn't exist in tree, return failure
    if (node == NULL) {
        std::cout << "failure" << std::endl;
    }
    //Otherwise, check the direction from the x, y
    else {
        if (d == "NW") {
            //If NW pointer of x, y is NULL, the direction trying to find min is empty
            if (node -> NW == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMinValue function
            else {
                unsigned int min = getMinValue(node -> NW, attr);
                std::cout << "min " << min << std::endl;
            }
        }
        else if (d == "NE") {
            //If NE pointer of x, y is NULL, the direction trying to find min is empty
            if (node -> NE == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMinValue function
            else {
                unsigned int min = getMinValue(node -> NE, attr);
                std::cout << "min " << min << std::endl;
            }
        }
        else if (d == "SW") {
            //If SW pointer of x, y is NULL, the direction trying to find min is empty
            if (node -> SW == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMinValue function
            else {
                unsigned int min = getMinValue(node -> SW, attr);
                std::cout << "min " << min << std::endl;
            }
        }
        else if (d == "SE") {
            //If SE pointer of x, y is NULL, the direction trying to find min is empty
            if (node -> SE == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getMinValue function
            else {
                unsigned int min = getMinValue(node -> SE, attr);
                std::cout << "min " << min << std::endl;
            }
        }
    }
} 

//Helper function of minValue
unsigned int QuadTree::getMinValue(QuadNode* node, std::string attr) {
    unsigned int minValueNE = 4294967295, minValueNW = 4294967295, minValueSE = 4294967295, minValueSW = 4294967295, current_value = 4294967295, minValue = 0;
    //If there are more nodes at the current NE pointer, recursively get min value from NE quadrant 
    if (node -> NE != NULL){
        minValueNE = getMinValue(node -> NE, attr);
    }
    //If there are more nodes at the current NW pointer, recursively get min value from NW quadrant 
    if (node -> NW != NULL){
        minValueNW = getMinValue(node -> NW, attr);
    }
    //If there are more nodes at the current SE pointer, recursively get min value from SE quadrant 
    if (node -> SE != NULL){
        minValueSE = getMinValue(node -> SE, attr);
    }
    //If there are more nodes at the current SW pointer, recursively get min value from SW quadrant 
    if (node -> SW != NULL){
        minValueSW = getMinValue(node -> SW, attr);
    }

    //Check the attribute wanting to find the min of and set the current value to that
    if (attr == "p")
        current_value = node -> population;
    else if (attr == "r")
        current_value = node -> livingcost;
    else if (attr == "s")
        current_value = node -> netsalary;

    return minValue = std::min(current_value, std::min(minValueSW, std::min(minValueSE, std::min(minValueNW, minValueNE))));
}


//Function used to get total value in a direction of node with x,y
void QuadTree::totalValue(double x, double y, std::string d, std::string attr) {
    //Search for x, y from root
    QuadNode* node = search(x, y, root);
    //If x, y doesn't exist in tree, return failure
    if (node == NULL) {
        std::cout << "failure" << std::endl;
    }
    //Otherwise, check the direction from the x, y
    else {
        if (d == "NW") {
            //If NW pointer of x, y is NULL, the direction trying to find total is empty
            if (node -> NW == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getTotalValue function
            else {
                unsigned int total = getTotalValue(node -> NW, attr);
                std::cout << "total " << total << std::endl;
            }
        }
        else if (d == "NE") {
            //If NE pointer of x, y is NULL, the direction trying to find total is empty
            if (node -> NE == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getTotalValue function
            else {
                unsigned int total = getTotalValue(node -> NE, attr);
                std::cout << "total " << total << std::endl;
            }
        }
        else if (d == "SW") {
            //If SW pointer of x, y is NULL, the direction trying to find total is empty
            if (node -> SW == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getTotalValue function
            else {
                unsigned int total = getTotalValue(node -> SW, attr);
                std::cout << "total " << total << std::endl;
            }
        }
        else if (d == "SE") {
            //If SE pointer of x, y is NULL, the direction trying to find total is empty
            if (node -> SE == NULL) {
                std::cout << "failure" << std::endl;
            }
            //Otherwise, run getTotalValue function
            else {
                unsigned int total = getTotalValue(node -> SE, attr);
                std::cout << "total " << total << std::endl;
            }
        }
    }
} 

//Helper function of totalValue
unsigned int QuadTree::getTotalValue(QuadNode* node, std::string attr) {
    unsigned int totalValueNE = 0, totalValueNW = 0, totalValueSE = 0, totalValueSW = 0, current_value = 0, totalValue = 0;
    //If there are more nodes at the current NE pointer, recursively get total value from NE quadrant 
    if (node -> NE != NULL){
        totalValueNE = getTotalValue(node -> NE, attr);
    }
    //If there are more nodes at the current NW pointer, recursively get total value from NW quadrant 
    if (node -> NW != NULL){
        totalValueNW = getTotalValue(node -> NW, attr);
    }
    //If there are more nodes at the current SE pointer, recursively get total value from SE quadrant 
    if (node -> SE != NULL){
        totalValueSE = getTotalValue(node -> SE, attr);
    }
    //If there are more nodes at the current SW pointer, recursively get total value from SW quadrant 
    if (node -> SW != NULL){
        totalValueSW = getTotalValue(node -> SW, attr);
    }

    //Check the attribute wanting to find the total of and set the current value to that
    if (attr == "p")
        current_value = node -> population;
    else if (attr == "r")
        current_value = node -> livingcost;
    else if (attr == "s")
        current_value = node -> netsalary;

    return totalValue = current_value + totalValueSW + totalValueSE + totalValueNW + totalValueNE;
}


//Function used to print tree in order traversal
void QuadTree::print(){
    if (root != NULL) {
        printTree(root);
        std::cout << std::endl;    
    }
}

//Helper function of print()
void QuadTree::printTree(QuadNode* node){
    //left
    if (node -> NE != NULL){
        printTree(node -> NE);
    }
    if (node -> NW != NULL){
        printTree(node -> NW);
    }
    //node
    std::cout << node -> city << " ";
    //right
    if (node -> SW != NULL){
        printTree(node -> SW);
    }
    if (node -> SE != NULL){
        printTree(node -> SE);
    }
}

//Functions used to clear QuadTree
void QuadTree::clear(){
    clearNode(root);
    std::cout << "success" << std::endl;
}

//Helper function of clear()
void QuadTree::clearNode(QuadNode* node) {
    if (node != NULL) {
        if (node -> NE != NULL){
            clearNode(node -> NE);
        }
        if (node -> NW != NULL){
            clearNode(node -> NW);
        }
        if (node -> SW != NULL){
            clearNode(node -> SW);
        }
        if (node -> SE != NULL){
            clearNode(node -> SE);
        }

        if (node != root) {
            delete node;
            sizeTree--;
        }
        //Can't delete root, thus create pointer equal to root and delete that pointer
        else {
            QuadNode* temp = root;
            root = NULL;
            delete temp;
            sizeTree--;
        }   
    }
}

//Function used to get size of tree
void QuadTree::size() {
    std::cout << "tree size " << sizeTree << std::endl;
}