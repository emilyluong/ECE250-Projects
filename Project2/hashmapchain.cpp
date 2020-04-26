/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include <cmath>
#include <vector>
#include "hashmapchain.h"

//constructor
HashMapChain::HashMapChain() {
    max_size = 0;
    hashtable.resize(0);
}

//destructor
HashMapChain::~HashMapChain() {
    for (int i = 0; i < max_size; i++) {
        HashEntryChain *curr = hashtable[i];

        while (curr != NULL) {
            HashEntryChain *temp = curr;
            curr = curr -> next;
            delete temp;         
        }
    }
}
    
//hash function
long long HashMapChain::hash_func1(long long k) {
    return (k % max_size);
}

//set size of hashtable
void HashMapChain::setSize(int m) {
    max_size = m;
    hashtable.resize(m);

    //deletes the pre-existing allocated link list nodes
    for (int i = 0; i < max_size; i++) {
        HashEntryChain *curr = hashtable[i];

        if (hashtable[i] != NULL) {
            while (curr != NULL) {
                HashEntryChain *temp = curr;
                curr = curr -> next;
                delete temp;         
            }
        }
    } 

    hashtable.clear();   
    hashtable.resize(m);   
    cout << "success" << endl;
}

//insert key and caller into hashtable using hash function
void HashMapChain::insertEntry(long long k, string caller) {
    long long hash_val = hash_func1(k);
    HashEntryChain *head = hashtable[hash_val];

    //if the hashtable index is empty
    if (head == NULL) {
        hashtable[hash_val] = new HashEntryChain;
        hashtable[hash_val] -> key = k;
        hashtable[hash_val] -> value = caller;
        cout << "success" << endl;
    }

    //if the hashtable index has one HashEntryChain/node
    else if (head -> next == NULL) {
        if (head -> key == k) {
            cout << "failure" << endl;
        }

        else if (head -> key < k) {
            hashtable[hash_val] -> next = new HashEntryChain;
            (hashtable[hash_val] -> next) -> key = k;
            (hashtable[hash_val] -> next) -> value = caller;
            cout << "success" << endl;
        }

        else {
            hashtable[hash_val] = new HashEntryChain;
            hashtable[hash_val] -> next = head;
            hashtable[hash_val] -> key = k;
            hashtable[hash_val] -> value = caller;
            cout << "success" << endl;
        }
    }

    //if the hashtable index has multiple HashEntryChain/nodes
    else {
        HashEntryChain *curr = head;
        HashEntryChain *succ = head -> next;
        
        //if key is less than head and head -> next
        if (k < (curr -> key) && k < (succ -> key)) {
            hashtable[hash_val] = new HashEntryChain;
            hashtable[hash_val] -> next = curr;
            hashtable[hash_val] -> key = k;
            hashtable[hash_val] -> value = caller;
            cout << "success" << endl;
        }

        else {
            while (succ != NULL) {
                if (curr -> key == k || succ -> key == k) {
                    cout << "failure" << endl;
                    break;
                }

                else if (k > (curr -> key) && k < (succ -> key)) {
                    curr -> next = new HashEntryChain;
                    (curr -> next) -> key = k;
                    (curr -> next) -> value = caller;
                    (curr -> next) -> next = succ;
                    cout << "success" << endl;
                    break;
                }

                else {
                    curr = succ;
                    succ = succ -> next;
                }
            }
        
            if (succ == NULL) {
                curr -> next = new HashEntryChain;
                (curr -> next) -> key = k;
                (curr -> next) -> value = caller;
                cout << "success" << endl;
            }
        }
    }      
}

//search for key in hashtable using hash function
void HashMapChain::searchKey(long long k) {
    long long hash_val = hash_func1(k);
    HashEntryChain *curr = hashtable[hash_val];

    //if the hashtable index is empty
    if (curr == NULL) {
        cout << "not found" << endl;
    }

    //if the hashtable index is not empty
    else {
        while (curr != NULL) {
            if (curr -> key == k) {
                cout << "found " << (curr -> value) << " in " << hash_val << endl;
                break;
            }

            else {
                curr = curr -> next;
            }
        }

        if (curr == NULL) {
            cout << "not found" << endl;
        }
    }
}

//deletes a key in hashtable using hash function
void HashMapChain::deleteKey(long long k) {
    long long hash_val = hash_func1(k);
    HashEntryChain *head = hashtable[hash_val];

    //if the hashtable index is empty
    if (head == NULL) {
        cout << "failure" << endl;
    }

    //if the hashtable index have one HashEntryChain/node
    else if ((head -> next) == NULL) {
        if ((head -> key) == k) {
            delete head;
            hashtable[hash_val] = NULL; 
            cout << "success" << endl;
        }

        else {
            cout << "failure" << endl;
        }
    }

    //if the hashtable index have multiple HashEntryChain/nodes
    else {
        HashEntryChain *pred = head;
        HashEntryChain *succ = head -> next;
        
        //if key to delete is at the head
        if (pred -> key == k) {
            hashtable[hash_val] = succ;
            delete pred;
            delete head;
            cout << "success" << endl;
        }

        //if key to delete is in a HashEntryChain/node other than the head
        else {
            bool k_deleted = false;
            while (succ != NULL) {
                if (succ -> key == k) {
                    HashEntryChain *temp = succ;
                    succ = temp -> next;
                    pred -> next = succ;
                    delete temp;

                    k_deleted = true;
                    cout << "success" << endl;
                }

                else {
                    pred = succ;
                    succ = succ -> next;
                }
            }

            if (succ == NULL && k_deleted == false) {
                cout << "failure" << endl;
            }
        }
    }
}

//prints out the asending ordered chain in position i of hashtable
void HashMapChain::printChain(int i) {
    HashEntryChain *pred = hashtable[i];
    
    //if chain is empty
    if (pred == NULL) {

    }

    //if chain only has one node
    else if (pred -> next == NULL) {
        cout << pred -> key << endl;
    }

    //if chain has multiple nodes
    else {
        HashEntryChain *succ = hashtable[i] -> next;

        while (succ != NULL) {
            cout << pred -> key << ' ';

            pred = succ;
            succ = succ -> next;              
        }

        if (succ == NULL) {
            cout << pred -> key << endl;
        }
    }
}