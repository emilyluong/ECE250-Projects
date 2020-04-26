#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include "Node.h"

using namespace std;

class PriorityQueue {
private:
    vector <Node*> PQ;
    int size;

public:
    PriorityQueue(vector <Node*> pq);   //overloading constructor
    ~PriorityQueue();                   //destructor

    void heapify(int i);        //heapify function used to restore heap   
    void buildMinHeap();        //builds the minimum heap
    Node* extractMin();         //takes out the minimum distance node from the priority queue
    void modifyKey(Node* n);    //restores the heap condition of the priority queue
    bool isEmpty();             //checks if priorety queue is empty

    friend class Graph;
};

#endif //PRIORITYQUEUE_H