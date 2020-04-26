/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "hashmapopen.h"

//constructor
HashMapOpen::HashMapOpen() {
    max_size = 0;
    curr_size = 0;
    hashtable.resize(0);
}

//destructor
HashMapOpen::~HashMapOpen() {

}

//hash function 1
long long HashMapOpen::hash_func1(long long k) {
    return (k % max_size);
}

//hash function 2
long long HashMapOpen::hash_func2(long long k) {
    return ((long long)(floor((long double)(k/max_size))) % max_size);
}

//set size of hashtable
void HashMapOpen::setSize(int m) {
    if (m <= 0) {

    }

    else {
        max_size = m;
        hashtable.clear();
        hashtable.resize(m);

        cout << "success" << endl;
    }   
}

//insert key and caller into hashtable using hash function
void HashMapOpen::insertEntry(long long k, string caller) {
    //first hash function
    long long hash_val1 = hash_func1(k);

    //if k is negative, do nothing
    if (k < 0) {

    }

    else {
        //checks if hashtable is full
        if (curr_size == max_size) {
            cout << "failure" << endl;
        }

        //checks if the key in the hashtable index already exists
        else if (hashtable[hash_val1].getKey() == k) {
            cout << "failure" << endl;
        }

        //checks if the hashtable index is empty
        else if (hashtable[hash_val1].getKey() == -1 && hashtable[hash_val1].getValue() == "") {            
            (hashtable[hash_val1]).setKey(k);
            (hashtable[hash_val1]).setValue(caller);
            (hashtable[hash_val1]).setUsedNode(true);
            curr_size++;
            cout << "success " << endl;
        }

        else {
            //if the hashtable index is not empty, the second hash function is used 
            long long hash_val2 = hash_func2(k);

            //if hash function has an even result, add 1 to make the result odd
            if ((hash_val2 % 2) == 0) {                
                hash_val2++;
            }
                
            //i indicates the number of collisions, in this else case, the first collision would have already occurred
            int i = 1;
            
            while (i <= (max_size)) {
                long long hash_val = (hash_val1 + (i * hash_val2)) % max_size;

                //checks if the key in the hashtable index already exists
                if (hashtable[hash_val].getKey() == k) {
                    cout << "failure" << endl;                    
                    break;
                }

                //if hashtable index is empty, then the key and caller can be stored in the index
                else if (hashtable[hash_val].getKey() == -1 && hashtable[hash_val].getValue() == "") {
                    (hashtable[hash_val]).setKey(k);
                    (hashtable[hash_val]).setValue(caller);
                    (hashtable[hash_val]).setUsedNode(true);
                    curr_size++;
                    cout << "success" << endl;
                    break;
                }

                //if the hashtable index is already filled, this is a collision, so increment i by 1
                else if (hashtable[hash_val].getKey() != -1 && hashtable[hash_val].getValue() != "") {
                    i++;
                }
            }   
        }
    }
}

//search for key in hashtable using hash function
void HashMapOpen::searchKey(long long k) {
    //first and second hash functions
    long long hash_val1 = hash_func1(k);        
    long long hash_val2 = hash_func2(k);

    //if second hash function has an even result, add 1 to make the result odd
        if ((hash_val2 % 2) == 0) {
            hash_val2 ++;
        }

    int i = 0;
    while (i < max_size) {
        long long hash_val = (hash_val1 + (i * hash_val2)) % max_size;

        //checks if the key in the hashtable index exists
        if (hashtable[hash_val].getKey() == k) {
            cout << "found " << hashtable[hash_val].getValue() << " in " << hash_val << endl;
            break;                
        }
            
        //checks if the search is in the last possible index to search or if the slot in the hashtable has never been used 
        else if (((i == (max_size - 1)) && (hashtable[hash_val].getKey() != k)) || (hashtable[hash_val].getUsedNode() == false)) {
            cout << "not found" << endl;
            break;
        }

        //if the hashtable index is already filled, increment i by 1
        else if (hashtable[hash_val].getKey() != k) {
            i++;            
        }                 
    }
}

//deletes a key in hashtable using hash function
void HashMapOpen::deleteKey(long long k) {
    //first and second hash functions
    long long hash_val1 = hash_func1(k);
    long long hash_val2 = hash_func2(k);

    //if second hash function has an even result, add 1 to make the result odd
        if ((hash_val2 % 2) == 0) {
            hash_val2++;
        }

    int i = 0;
    while (i < max_size) {
        long long hash_val = (hash_val1 + (i * hash_val2)) % max_size;

        //checks if the key in hashtable index exists
        if (hashtable[hash_val].getKey() == k) {
            hashtable[hash_val].setKey(-1);
            hashtable[hash_val].setValue("");
            curr_size--;
            cout << "success" << endl;                
            break;                
        }
            
        //checks if the search is in the last possible index to delete or if the slot in the hashtable has never been used 
        else if (((i == (max_size - 1)) && (hashtable[hash_val].getKey() != k)) || (hashtable[hash_val].getUsedNode() == false)) {
            cout << "failure" << endl;
            break;            
        }

        //if the hashtable index is already filled, increment i by 1
        else if (hashtable[hash_val].getKey() != k) {
            i++;
        }
    }
}