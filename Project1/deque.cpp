/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include "deque.h"

//constructor that initialized member variables
deque::deque() {
    head = NULL;
    tail = NULL;
    num_node = 0;
}

//destructor that deletes and frees up allocated memory
deque::~deque() {
    while (head != NULL) {
        node *n = head;
        head = head -> prev;
        delete n;
        num_node--;
    } 
}

//adds an element to the front of the deque
void deque::enqueue_front(int i) {
    if (head == NULL) {
        head = tail = new node;
        head -> data = i;
        num_node++;
        cout << "success" << endl;
    }

    else {
        node *n = new node;
        n -> data = i;
        n -> prev = head;
        head -> next = n;
        head = n;
        num_node++;
        cout << "success" << endl;
    }
}

//adds an element to the back of the deque
void deque::enqueue_back(int i) {
    if (tail == NULL) {
        tail = head = new node;
        tail -> data = i;
        num_node++;
        cout << "success" << endl;
    }

    else {
        node *n = new node;
        n -> data = i;
        n -> next = tail;
        tail -> prev = n;
        tail = n; 
        num_node++;
        cout << "success" << endl;
    }
}

//deletes an element at the front of the deque
void deque::dequeue_front() {
    if ((num_node == 1) && (head == tail)) {
        node *n = head;
        head = tail = NULL;
        delete n;
        num_node--;
        cout << "success" << endl;
    }

    else if ((num_node > 1) && (head != tail)) {
        node *n = head;
        head = n -> prev;
        head -> next = NULL;
        delete n; 
        num_node--;
        cout << "success" << endl;
    }

    else {
        throw deque_empty();
    }
}

//deletes an element at the back of the deque
void deque::dequeue_back() {
    if ((num_node == 1) && (tail == head)) {
        node *n = tail;
        tail = head = NULL;
        delete n;
        num_node--;
        cout << "success" << endl;
    }

    else if ((num_node > 1) && (head != tail)) {
        node *n = tail;
        tail = n -> next;
        tail -> prev = NULL;
        delete n; 
        num_node--;
        cout << "success" << endl;
    }

    else {
        throw deque_empty();
    }
}

//clears the entire deque
void deque::clear() {
    while (head != NULL) {
        node *n = head;
        head = head -> prev;
        delete n;
        num_node--;
    } 
    cout << "success" << endl;
}

//checks if the front of the deque is a certain int
void deque::front(int i) {
    if (head == NULL || i != (head -> data)) {
        throw deque_empty();
    }

    else if (i == (head -> data)) {
        cout << "success" << endl;
    } 
}

//checks if the back of the deque is a certain int
void deque::back(int i) {
    if (tail == NULL || i != (tail -> data)) {
        throw deque_empty();
    }

    else if (i == (tail -> data)) {
        cout << "success" << endl;
    } 
}

//checks if the deque is empty
void deque::empty() {
    if (num_node == 0) {
        cout << "success" << endl;
    }

    else {
        cout << "failure" << endl;
    }
}

//returns the size of the deque
void deque::size() {
    cout << "size is " << num_node << endl;
}

//prints the deque from front to back and from back to front
void deque::print() {
    if (num_node == 0) {
        
    }
    
    else {
        node *t = head;
        
        while (t != tail) {
            cout << t -> data << " ";
            t = t -> prev;
        }
        
        cout << tail -> data << endl;
        t = tail;

        while (t != head) {
            cout << t -> data << " ";
            t = t -> next;
        }

        cout << head -> data << endl;
    }
}