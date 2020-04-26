/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include "Graph.h"
#include "Node.h"
#include "AdjNode.h"
#include "Edge.h"
#include "PriorityQueue.h"

using namespace std;

int main() {
    //while not end of file
    while(!(cin.eof())) {

        string line;
        Graph G; 
        while(getline(cin, line)) {   
            //insert node command
            if (line.substr(0, 1) == "i") {
                string node = line.substr(2, string::npos);
                G.insertNode(node);
            }
            
            //set distance between cities command
            else if (line.substr(0, 4) == "setd") {
                string i_info = line.substr(5, string::npos);
                string info; 
                stringstream ss(i_info);
                vector<string> i_vec;

                while(getline(ss, info, ';')){
                    i_vec.push_back(info);
                }

                double d = stod(i_vec[2]);

                G.setDistance(i_vec[0], i_vec[1], d);
            }

            //finds shortest distance between two cities
            else if (line.substr(0, 10) == "shortest_d") {    
                string c1 = line.substr(11, line.find(";") - 11);
                string c2 = line.substr(line.find(";") + 1, string::npos);
                
                G.shortestDistance(c1, c2);
            }
            
            // prints path between cities
            else if (line.substr(0, 10) == "print_path") {
                string c1 = line.substr(11, line.find(";") - 11);
                string c2 = line.substr(line.find(";") + 1, string::npos);

                G.printPath(c1, c2);
            }

            //search for city command
            else if (line.substr(0, 1) == "s") {
                string node = line.substr(2, string::npos);
                G.searchCity(node);
            }

            //print degree of node command
            else if (line.substr(0, 6) == "degree") {
                string node = line.substr(7, string::npos);
                G.degreeCity(node);
            }

            //print number of nodes
            else if (line.substr(0, 11) == "graph_nodes") {
                G.printNodes();
            }

            //prints number of edges
            else if (line.substr(0, 11) == "graph_edges") {
                G.printEdges();
            }

            //prints distance between two adjacent cities
            else if (line.substr(0, 1) == "d") {
                string c1 = line.substr(2, line.find(";") - 2);
                string c2 = line.substr(line.find(";") + 1, string::npos);
                
                G.printDistance(c1, c2);
            }

            //clear graph command
            else if (line.substr(0, 5) == "clear") {
                G.clearGraph();
            }

            else {

            }
        }
    }
}
