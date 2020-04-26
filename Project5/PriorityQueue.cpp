#include "PriorityQueue.h"
#include <cmath>

//constructor
PriorityQueue::PriorityQueue(vector <Node*> pq) {
    PQ = pq;
    size = pq.size();
    buildMinHeap();
}

//destructor
PriorityQueue::~PriorityQueue() {

}

//heapify function used to restore heap
void PriorityQueue::heapify(int i) {
    //get the left and right child of index i
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int smallest;

    //compares index i with left child to obtain the smallest value into smallest
    if (left < size && isinf(PQ[left] -> dist) == false && (isinf(PQ[i] -> dist) == true || (PQ[left] -> dist < PQ[i] -> dist))) {
        smallest = left;
    }
    else {
        smallest = i;
    }

    //compares current smallest value with right child to obtain the smallest value into smallest
    if (right < size && isinf(PQ[right] -> dist) == false && (isinf(PQ[i] -> dist) == true || (PQ[right] -> dist < PQ[smallest] -> dist))) {
        smallest = right;
    }

    //swap if smallest does not equal to i
    if (smallest != i) {
        swap(PQ[i], PQ[smallest]);
        heapify(smallest);
    }
}

//builds the minimum heap
void PriorityQueue::buildMinHeap() {
    for (int i = floor((size - 1) / 2); i >= 0; i--) {
        heapify(i);
    }
}

//takes out the minimum distance node from the priority queue and calls heapify on index 0 
Node* PriorityQueue::extractMin() {
    Node* min = PQ[0];
    PQ[0] = PQ[size - 1];
    PQ.pop_back();
    size--;
    heapify(0);

    return min;
}

//restores the heap condition of the priority queue
void PriorityQueue::modifyKey(Node* n) {
    //finds the index of n in the priority queue
    int index_n;
    for (int i = 0; i < PQ.size(); i++) {
        if (PQ[i] == n) {
            index_n = i;
        }
    }
    //parent of index_n
    int parent_n = floor((index_n - 1) / 2);
    
    //loop for when index_n is not root and distance of index_n is less than distance of parent_n
    while (index_n > 0 && (PQ[index_n] -> dist < PQ[parent_n] -> dist)) {
        swap(PQ[index_n], PQ[parent_n]);
        index_n = parent_n;
        parent_n = floor((index_n - 1) / 2);
    }
}

//checks if priorety queue is empty
bool PriorityQueue::isEmpty() {
    if (size == 0) {
        return true;
    }
    else {
        return false;
    }
}