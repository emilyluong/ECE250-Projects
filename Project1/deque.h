/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
#include "deque_empty.h"

using namespace std;

class deque {

private:
    node *head;
    node *tail;
    int num_node;

public:
    deque();
    ~deque();

    void enqueue_front(int i);
    void enqueue_back(int i);
    
    void dequeue_front();
    void dequeue_back();

    void clear();

    void front(int i);
    void back(int i);

    void empty();

    void size();
    
    void print();
};

#endif //DEQUE_H