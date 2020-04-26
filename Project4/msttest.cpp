/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "illegal_argument.h"
#include "Node.h"
#include "Edge.h"
#include "Graph.h"
#include "DisjointSet.h"

using namespace std;

int main() {
    //while not end of file
    while(!(cin.eof())) {

        string line;
        getline(cin, line);

        Graph* G;   //Graph type pointer 
        //n is first command of input file and it will allocate memory to create a new graph
        if (line.substr(0, 1) == "n") {
            string node_str = line.substr(2, string::npos);
            int node_int = stoi(node_str);
            try {
                G = new Graph(node_int);
            }

            catch (illegal_argument) {
                cout << "failure" << endl;
                break;
            } 

            while(getline(cin, line)) {   
                //insert edge command
                if (line.substr(0, 1) == "i") {
                    string i_info = line.substr(2, string::npos);

                    string info; 
                    stringstream ss(i_info);
                    vector<string> i_vec;

                    while(getline(ss, info, ';')){
                        i_vec.push_back(info);
                    }

                    int ver1 = stoi(i_vec[0]);
                    int ver2 = stoi(i_vec[1]);
                    double wei = stod(i_vec[2]);

                    try { 
                        G -> insertEdge(ver1, ver2, wei); 
                    }
                    catch (illegal_argument) {
                        cout << "failure" << endl;
                    }
                }
                
                //degree of vertex command
                else if (line.substr(0, 6) == "degree") {
                    int ver = stoi(line.substr(7, string::npos));

                    try {
                        G -> degreeVertex(ver);
                    }
                    catch (illegal_argument) {
                        cout << "failure" << endl;
                    }
                }

                //delete edge command
                else if (line.substr(0, 1) == "d") {
                    int ver1 = stoi(line.substr(2, line.find(";") - 2));
                    int ver2 = stoi(line.substr(line.find(";") + 1, string::npos));
                    
                    try {
                        G -> deleteEdge(ver1, ver2);
                    }
                    catch (illegal_argument) {
                        cout << "failure" << endl;
                    }
                }

                //total edge in graph command
                else if (line.substr(0, 10) == "edge_count") {
                    G -> edgeTotal();
                }

                //clear graph command
                else if (line.substr(0, 5) == "clear") {
                    G -> clearGraph();
                }
                
                //mst command
                else if (line.substr(0, 3) == "mst") {
                    G -> kruskalMST();
                }

                else {

                }
            }
            //delete allocated Graph type G
            delete G;
        }
    }
}
