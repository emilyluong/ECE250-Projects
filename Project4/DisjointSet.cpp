/* 
Name: Emily Luong
StudentID: e4luong
*/

#include "DisjointSet.h"
#include <iostream>

//overloading constructor
DisjointSets::DisjointSets(vector<Node*> n_set) {
    disjoint_set = n_set;
}

//default constructor
DisjointSets::DisjointSets() {
}

//default deconstructor
DisjointSets::~DisjointSets() {
}

//returns the parent of the node
Node* DisjointSets::findSet(Node* n) {
    return n -> parent; 
}

//merges the sets of u and v
void DisjointSets::unionSet(Node* u, Node* v) {
    Node* temp1  = u;
    Node* temp2 = v;

    //traverses down the u set link link until the last node next pointer is NULL
    while (temp1 -> next != NULL) {
        temp1 = temp1 -> next;
    }
    //sets the last node next pointer to the second node set link list
    temp1 -> next = temp2;

    //traverse the second node set link list and assigns the parents of the nodes in the second node set to u
    while (temp2 != NULL) {
        temp2 -> parent = u;
        temp2 = temp2 -> next;
    } 

    //deletes the v set by setting the index where v was at to NULL
    for (int i = 0; i < disjoint_set.size(); i++) {
        if (disjoint_set[i] == v) {
            disjoint_set[i] = NULL;
        }
    }
}
