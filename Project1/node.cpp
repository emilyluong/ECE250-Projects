/* 
Name: Emily Luong
StudentID: e4luong
*/

#include "node.h"
#include <string>

//constructor initializing the member variables
node::node() {
    data = 0;
    next = NULL;
    prev = NULL;
}

//destructor
node::~node() {

}

//constructor that takes in an argument and stores that in data member variable
node::node(int d) {
    data = d;
}