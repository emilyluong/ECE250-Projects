/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <string>
#include "hashentryopen.h"

//constructor
HashEntryOpen::HashEntryOpen() {
    key = -1;
    value = "";
    used_node = false;
}

//destructor
HashEntryOpen::~HashEntryOpen() {

}

//function used to set the key in the HashEntry
void HashEntryOpen::setKey(long long k) {
    key = k;
}

//function used to get key from HashEntry
long long HashEntryOpen::getKey() {
    return key;
}

//function used to set the value(caller) in the HashEntry
void HashEntryOpen::setValue(string caller) {
    value = caller;
}

//function used to get the value(caller) in the HashEntry
string HashEntryOpen::getValue() {
    return value;
}

//function used to set bool of a used node
void HashEntryOpen::setUsedNode(bool used_n) {
    used_node = used_n;
}

//function used to get bool of if a node has been used
bool HashEntryOpen::getUsedNode() {
    return used_node;
}