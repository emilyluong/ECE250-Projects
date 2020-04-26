/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include <string>
#include "hashentryopen.h"
#include "hashmapopen.h"

using namespace std;

int main() {

    while(!(cin.eof())) {

        string line;
        HashMapOpen hashtable;

        while(getline(cin, line)) {

            //checks command for setting size of hashtable
            if (line.substr(0, 1) == "n") {
                string hs_str = line.substr(2, string::npos);
                long long hs_long = stoll(hs_str);

                hashtable.setSize(hs_long);
            }

            //checks command for inserting key and caller into hashtable        
            else if (line.substr(0, 1) == "i") {
                string ik_str = line.substr(2, line.find(";") - 2);
                long long ik_long = stoll(ik_str);
                string iv_str = line.substr(line.find(";") + 1, string::npos);

                hashtable.insertEntry(ik_long, iv_str);
            }

            //checks command for searching for a key in hashtable
            else if (line.substr(0, 1) == "s") {
                string sk_str = line.substr(2, string::npos);
                long long sk_long = stoll(sk_str);

                hashtable.searchKey(sk_long);
            }

            //checks command for deleting a key in hashtable
            else if (line.substr(0, 1) == "d") {
                string dk_str = line.substr(2, string::npos);
                long long dk_long = stoll(dk_str);

                hashtable.deleteKey(dk_long);         
            }

            //invalid command, do nothing
            else {

            }
        }
    }
}