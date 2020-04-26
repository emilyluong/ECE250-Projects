/* 
Name: Emily Luong
StudentID: e4luong
*/

#ifndef HASHENTRYOPEN_H
#define HASHENTRYOPEN_H

using namespace std;

class HashEntryOpen {

private:
    long long key;
    string value;
    bool used_node;

public:
    HashEntryOpen();    //constructor declaration
    ~HashEntryOpen();   //destructor declaration

    void setKey(long long k);   //set key function declaration
    long long getKey(); //get key function declaration
    void setValue(string caller);   //set value(caller) function declaration
    string getValue();  //get value(caller) function declaration
    void setUsedNode(bool used_n);  //set used node function declaration
    bool getUsedNode(); //get bool used node declaration 
};

#endif //HASHENTRYOPEN_H