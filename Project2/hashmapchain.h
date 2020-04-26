/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef HASHMAPCHAIN_H
#define HASHMAPCHAIN_H

#include <vector>
#include "hashentrychain.h"

using namespace std;

class HashMapChain {

private:
    int max_size;
    vector <HashEntryChain*> hashtable;

public:
    HashMapChain(); //constructor declaration
    ~HashMapChain();    //destructor declaration
    
    long long hash_func1(long long k);  //hash function declaration

    void setSize(int m);    //set size of hashtable declaration

    void insertEntry(long long k, string caller);    //insert key and caller into hashtable using hash function declaration
 
    void searchKey(long long k);    //search for key in hashtable using hash function declaration

    void deleteKey(long long k);    //deletes a key in hashtable using hash function declaration

    void printChain(int i);    //prints out the asending ordered chain in position i of hashtable declaration
};

#endif //HASHMAPCHAIN_H