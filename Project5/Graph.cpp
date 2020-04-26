#include <iostream>
#include <cmath>
#include "Graph.h"

Graph::Graph() {
    num_node = 0;
    num_edge = 0;
}

Graph::~Graph() {
    //delete memory allocated nodes and clears node_list vector
    if (node_list.empty() == false) {
        for (int i = 0; i < node_list.size(); i++) {
            delete node_list[i];
        }
        node_list.clear();
    }   
}

//insert node to graph function
void Graph::insertNode(string c) {
    //if city in graph, print out failure
    if ((cityFound(c) == true)) {
        cout << "failure" << endl;
    }
    //else add city to graph
    else {
        Node* n = new Node;
        n -> city = c;
        node_list.push_back(n);

        num_node++; 
        cout << "success" << endl;
    }
}

//sets distance between two cities function
void Graph::setDistance(string c1, string c2, double d) {
    //checks for failure conditions of setting distance between two cities
    if ((cityFound(c1) == false) || (cityFound(c2) == false) || (c1 == c2) || (d <= 0)) {
        cout << "failure" << endl;
    }

    //else add edge to the adjacency list
    else {
        bool update1 = false;
        bool update2 = false;
        for (int i = 0; i < node_list.size(); i++) {
            //checks if there is already an edge between the two cities, if so update distance in both city adj_list
            if (node_list[i] -> city == c1) {   
                for (int j = 0; j < (node_list[i] -> adj_list).size(); j++) {
                    if ((node_list[i] -> adj_list)[j].city == c2) {
                        (node_list[i] -> adj_list)[j].dist = d;
                        update1 = true;
                        break;
                    }
                }
            }
            else if (node_list[i] -> city == c2) {
                for (int j = 0; j < (node_list[i] -> adj_list).size(); j++) {
                    if ((node_list[i] -> adj_list)[j].city == c1) {
                        (node_list[i] -> adj_list)[j].dist = d;
                        update2 = true;
                        break;
                    }
                }
            }
            //if both nodes have been updated in the nodes list, break out of loop
            if ((update1 && update2) == true) {
                break;
            }
        }

        //update edge list distance
        if((update1 && update2) == true) {
            for (int i = 0; i < edge_list.size(); i++) {
                if (((edge_list[i].city1) -> city  == c1) && ((edge_list[i].city2) -> city == c2)) {
                    edge_list[i].dist = d;
                }
                else if (((edge_list[i].city1) -> city == c2) && ((edge_list[i].city2) -> city == c1)) {
                    edge_list[i].dist = d;
                }
            }
            cout << "success" << endl;
        }
        //if no updates were done, add edge to graph
        else {
            Node* city1;
            Node* city2;
            for (int i = 0; i < node_list.size(); i++) { 
                if (node_list[i] -> city == c1) {
                    city1 = node_list[i];
                }
                else if (node_list[i] -> city == c2) {
                    city2 = node_list[i];
                }
            }
            //adds to edge list
            Edge e(city1, city2, d);
            edge_list.push_back(e);

            //adds adjnodes to graph
            (city1 -> degree)++;
            AdjNode n1;
            n1.city = c2;
            n1.dist = d;
            (city1 -> adj_list).push_back(n1);

            (city2 -> degree)++;
            AdjNode n2;
            n2.city = c1;
            n2.dist = d;
            (city2 -> adj_list).push_back(n2);

            //increment num_edges in graph
            cout << "success" << endl;
            num_edge++;
        }
    }
}

//helper function to find nodes
bool Graph::cityFound(string c) {
    //loops through node list to find city
    bool found = false;
    for (int i = 0; i < node_list.size(); i++) {
        //if city is found
        if (node_list[i] -> city == c) {
            found = true;
            break;
        }
    }
    return found;
}

//searches for city function
void Graph::searchCity(string c) {
    if (cityFound(c) == true) {
        cout << "found " << c << endl;
    }
    else {
        cout << "not found" << endl;
    }
}

//prints out degree of city function
void Graph::degreeCity(string c) {
    //loops through node list to find city
    bool found = false;
    for (int i = 0; i < node_list.size(); i++) {
        //if city is found
        if (node_list[i] -> city == c) {
            found = true;
            cout << "degree of " << c << " " << node_list[i] -> degree << endl;
            break;
        }
    }
    //if node does not exists
    if (found == false) {
        cout << "failure" << endl;
    }
}

//prints out number of nodes in the graph
void Graph::printNodes() {
    cout << "number of nodes " << num_node << endl;
}

//prints out number of edges in the graph
void Graph::printEdges() {
    cout << "number of edges " << num_edge << endl;
}

//prints out the distance between 2 cities
void Graph::printDistance(string c1, string c2) {
    //if cities are same, if either cities are not found
    if ((c1 == c2) || (cityFound(c1) == false) || (cityFound(c2) == false)) {
        cout << "failure" << endl;
    }
    //otherwise
    else {
        //loops through edge list to find the edge distance between two cities
        bool has_edge = false;
        for (int i = 0; i < edge_list.size(); i++) {
            if ((((edge_list[i].city1) -> city  == c1) && ((edge_list[i].city2) -> city == c2)) || (((edge_list[i].city1) -> city == c2) && ((edge_list[i].city2) -> city == c1))) {
                has_edge = true;
                cout << "direct distance " << c1 << " to " << c2 << " " << edge_list[i].dist << endl;
                break;
            }
        }

        //if no edge exists in edge list, output failure
        if (has_edge == false) {
            cout << "failure" << endl;
        }
    }
}

//clears the graph 
void Graph::clearGraph() {
    //clears the edges of the graph
    for (int i = 0; i < node_list.size(); i++) {
        (node_list[i] -> adj_list).clear();
        delete node_list[i];
    }
    //clears the nodes of the graph
    node_list.clear();
    //clears the edge_list of the graph
    edge_list.clear();
    //sets the number of edges and number of nodes to zero
    num_edge = 0;
    num_node = 0;

    cout << "success" << endl;
}

//relax function used in dijkstraAlgo function
void Graph::relax(Node* u, Node* v) {
    double dist_uv;
    for (int i = 0; i < (u -> adj_list.size()); i++) {
        if ((u -> adj_list)[i].city == v -> city) {
            dist_uv = (u -> adj_list)[i].dist;
        }
    }
    //if the distance of node v is greater than the distance of u and the edge distance between u and v, set the distance of v to distance of u + distance between u and v, as well as setting the partent of v to u
    if (isinf(v -> dist) == true || v -> dist > (u -> dist + dist_uv)) {
        v -> setDist(u -> dist + dist_uv);
        v -> setParent(u);
    }
}

//dijkstras algorithm used in shortestDistance function and printPath function
void Graph::dijkstraAlgo(string c1, string c2) {
    //sets the distance and parents of each node
    for (int i = 0; i < node_list.size(); i++) {
        if (node_list[i] -> city == c1) {
            node_list[i] -> setDist(0.0);
            node_list[i] -> setParent(NULL);
        }
        else {
            node_list[i] -> setDist(INFINITY);
            node_list[i] -> setParent(NULL);
        } 
    }

    //initializes priority queue and inserts all unvisited node of graph into queue
    PriorityQueue Q(node_list);
    vector <Edge> unvisited_e = edge_list;
    while (Q.isEmpty() != true) {
        Node* u = Q.extractMin();
        //stores visted node or node extracted from the priority queue into visted_n vector
        vector <Node*> adj;
        //gets all the adjacent nodes (nodes that were not visited yet) into adj
        for (int i = 0; i < unvisited_e.size(); i++) {
            if (unvisited_e[i].city1 == u) {
                adj.push_back(unvisited_e[i].city2);
                unvisited_e[i].city1 = NULL;
                unvisited_e[i].city2 = NULL;
            }
            else if (unvisited_e[i].city2 == u) {
                adj.push_back(unvisited_e[i].city1);
                unvisited_e[i].city1 = NULL;
                unvisited_e[i].city2 = NULL;
            }
        }
        //for all adjacent nodes, relax it and modify the keys in the priority queue
        for (int i = 0; i < adj.size(); i++) {
            relax(u, adj[i]);
            Q.modifyKey(adj[i]);
        }
    }
}

void Graph::shortestDistance(string c1, string c2) {
    //if cities are same, if either cities are not found
    if ((c1 == c2) || (cityFound(c1) == false) || (cityFound(c2) == false)) {
        cout << "failure" << endl;
    }
    else {
        dijkstraAlgo(c1, c2);

        //finds the node c2 in the node_list
        Node* city2;
        for (int i = 0; i < node_list.size(); i++) {
            if (node_list[i] -> city == c2) {
                city2 = node_list[i];
                break;
            }
        }
        //if there is no undirect path to c2 from c1
        if (city2 -> dist == INFINITY) {
            cout << "failure" << endl;
        }
        else {
            cout << "shortest distance " << c1 << " to " << c2 << " " << city2 -> dist << endl;
        }
    }
}

void Graph::printPath(string c1, string c2) {
    //if cities are same, if either cities are not found
    if ((c1 == c2) || (cityFound(c1) == false) || (cityFound(c2) == false)) {
        cout << "failure" << endl;
    }
    else {
        dijkstraAlgo(c1, c2);

        //finds the node c2 in the node_list
        Node* city2;
        for (int i = 0; i < node_list.size(); i++) {
            if (node_list[i] -> city == c2) {
                city2 = node_list[i];
                break;
            }
        }
        //if there is no undirect path to c2 from c1
        if (city2 -> dist == INFINITY) {
            cout << "failure" << endl;
        }
        else {
            //stores path into path vector
            Node* curr = city2;
            vector <Node*> path;
            while (curr != NULL) {
                path.push_back(curr);
                curr = curr -> parent;
            }

            //prints out the path in order from c1 to c2
            for (int i = (path.size() - 1); i > 0; i--) {
                cout << path[i] -> city << " ";
            }

            cout << path[0] -> city << endl;
        }
    }
}