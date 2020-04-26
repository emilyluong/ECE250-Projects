/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include <string>  
#include "deque.h"
#include "node.h" 

using namespace std;

int main() {

    while(!(cin.eof())) {

        string line; 
        deque list;

        while(getline(cin, line)) {

            if (line.substr(0, 13) == "enqueue_front") {
                string ef_str = line.substr(14, string::npos);
                int ef_int = stoi(ef_str);
                list.enqueue_front(ef_int);
            }
                    
            else if (line.substr(0, 12) == "enqueue_back") {
                string eb_str = line.substr(13, string::npos);
                int eb_int = stoi(eb_str);
                list.enqueue_back(eb_int);
            }

            else if (line.substr(0, 13) == "dequeue_front") {
                try {
                    list.dequeue_front();
                }
                catch (deque_empty) {
                    cout << "failure" << endl; 
                }
            }

            else if (line.substr(0, 12) == "dequeue_back") {
                try {
                    list.dequeue_back();
                }
                catch (deque_empty) {
                    cout << "failure" << endl; 
                }            
            }

            else if (line.substr(0,5) == "clear") {
                list.clear();
            }

            else if (line.substr(0, 5) == "front") {
                try {
                    string f_str = line.substr(6, string::npos);
                    int f_int = stoi(f_str);
                    list.front(f_int);
                }
                catch (deque_empty) {
                    cout << "failure" << endl; 
                }
            }

            else if (line.substr(0, 4) == "back") {
                try {
                    string b_str = line.substr(5, string::npos);
                    int b_int = stoi(b_str);
                    list.back(b_int);
                }
                catch (deque_empty) {
                    cout << "failure" << endl; 
                }
            }

            else if (line.substr(0, 5) == "empty") {
                list.empty();
            }

            else if (line.substr(0, 4) == "size") {
                list.size();
            }

            else if (line.substr(0, 5) == "print") {
                list.print();
            }

            else {

            }
        }
    }
}