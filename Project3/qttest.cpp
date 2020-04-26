#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "QuadTree.h"
#include "QuadNode.h"

using namespace std;

int main() {

    while(!(cin.eof())) {

        string line; 
        QuadTree tree;

       while(getline(cin, line)) { 
           //Print tree in order traversal
            if (line.substr(0, 5) == "print") {
                tree.print();
            }

            //Clear tree
            else if (line.substr(0, 5) == "clear") {
                tree.clear();
            }

            //Return size of tree
            else if (line.substr(0, 4) == "size") {
                tree.size();
            }

           //Insert to tree    
            else if (line.substr(0, 1) == "i") {
                string c_info = line.substr(2, string::npos);

                string info; 
                stringstream ss(c_info);
                vector<string> info_vec;

                while(getline(ss, info, ';')){
                    info_vec.push_back(info);
                }

                string city = info_vec[0];
                double long_dou = stod(info_vec[1]);
                double lat_dou = stod(info_vec[2]);
                unsigned int pop_int = stoi(info_vec[3]);
                unsigned int lcost_dou = stoi(info_vec[4]);
                unsigned int nsalary_dou = stoi(info_vec[5]);

                tree.insertInfo(city, long_dou, lat_dou, pop_int, lcost_dou, nsalary_dou);
            }

            //Search tree
            else if ((line.substr(0, 1) == "s") && !(line.substr(0, 4) == "size")) {
                string x_str = line.substr(2, line.find(";") - 2);
                string y_str = line.substr(line.find(";") + 1, string::npos);

                double x_dou = stod(x_str);
                double y_dou = stod(y_str);

                tree.searchCity(x_dou, y_dou);
            }

            //Find max attribute of tree in specific direction 
            else if (line.substr(0, 5) == "q_max") {
                string max_info = line.substr(6, string::npos);

                string info; 
                stringstream ss(max_info);
                vector<string> max_vec;

                while(getline(ss, info, ';')){
                    max_vec.push_back(info);
                }

                double long_dou = stod(max_vec[0]);
                double lat_dou = stod(max_vec[1]);
                string dir = max_vec[2];
                string attr = max_vec[3];

                tree.maxValue(long_dou, lat_dou, dir, attr);
            }

            //Find min attribute of tree in specific direction 
            else if (line.substr(0, 5) == "q_min") {
                string min_info = line.substr(6, string::npos);

                string info; 
                stringstream ss(min_info);
                vector<string> min_vec;

                while(getline(ss, info, ';')){
                    min_vec.push_back(info);
                }

                double long_dou = stod(min_vec[0]);
                double lat_dou = stod(min_vec[1]);
                string dir = min_vec[2];
                string attr = min_vec[3];

                tree.minValue(long_dou, lat_dou, dir, attr);
            }

            //Find total attribute of tree in specific direction 
            else if (line.substr(0, 7) == "q_total") {
                string tot_info = line.substr(8, string::npos);

                string info; 
                stringstream ss(tot_info);
                vector<string> tot_vec;

                while(getline(ss, info, ';')){
                    tot_vec.push_back(info);
                }

                double long_dou = stod(tot_vec[0]);
                double lat_dou = stod(tot_vec[1]);
                string dir = tot_vec[2];
                string attr = tot_vec[3];

                tree.totalValue(long_dou, lat_dou, dir, attr);
            }

            //Otherise, do nothing
            else {

            }
        }
    }
}