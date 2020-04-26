/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef NODE_H
#define NODE_H

class node {
    
private:
     int data;
     node *next;
     node *prev;

public:
     node(); 
     ~node();

     node(int d);

     friend class deque;
};

#endif //NODE_H