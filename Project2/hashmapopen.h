/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef HASHMAPOPEN_H
#define HASHMAPOPEN_H

#include <vector>
#include "hashentryopen.h"

using namespace std;

class HashMapOpen {

private:
    int max_size;
    int curr_size;
    vector <HashEntryOpen> hashtable;

public:

    HashMapOpen();  //constructor declaration
    ~HashMapOpen(); //destructor declaration

    long long hash_func1(long long k);  //hash function 1 declaration

    long long hash_func2(long long k);  //hash function 2 declaration

    void setSize(int m);    //set size of hashtable declaration

    void insertEntry(long long k, string caller);    //insert key and caller into hashtable using hash function declaration

    void searchKey(long long k);    //search for key in hashtable using hash function declaration

    void deleteKey(long long k);    //deletes a key in hashtable using hash function declaration 
};

#endif //HASHMAPOPEN_H