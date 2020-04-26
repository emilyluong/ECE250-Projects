/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef HASHENTRYCHAIN_H
#define HASHENTRYCHAIN_H

using namespace std;

class HashEntryChain {

private:
    long long key;
    string value;
    HashEntryChain *next;

public:
    HashEntryChain();   //constructor declaration
    ~HashEntryChain();  //destructor declaration

    friend class HashMapChain;  //friend class so that HashMapChain can access private variables of HashEntryChain
};

#endif //HASHENTRYCHAIN_H