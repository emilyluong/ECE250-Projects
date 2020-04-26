/* 
Name: Emily Luong
StudentID: e4luong
*/

#include <iostream>
#include "Graph.h"
#include <algorithm>

//graph constructor that initalizes the adjacent matrix and sets all the elements in the matrix to false, indicating no adjacent vertices
Graph::Graph(int n) {
    if (n > 0) {
        edge_num = 0;
        node_num = n;
        adj_matrix = new double*[n];
        
        //creating adjacency matrix
        for (int i = 0; i < n; i++) {
            adj_matrix[i] = new double[n];
            for (int j = 0; j < n; j++) {
                adj_matrix[i][j]  = 0.0;
            }
        }
        //Creating all nodes
        for (int i = 0; i < node_num; i++) {
            Node* node = new Node;
            node -> key = i;
            node -> parent = node;
            nodes.push_back(node);
        }

        cout << "success" << endl;
    }
    else {
        throw illegal_argument();
    }
}

//default constructor
Graph::Graph() {
    node_num = 0;
    edge_num = 0;
    adj_matrix = NULL;
}

//destructor
Graph::~Graph() {
    //deletes nodes created in nodes vector
    if (nodes.empty() == false) {
        for (auto p : nodes) {
            delete p;
        } 
        nodes.clear();
    }

    //deletes the actual matrix
    for (int i = 0; i < node_num; i++) {
        delete[] adj_matrix[i];
    }
    delete[] adj_matrix;
}

//inserting an edge between u and v with weight w
void Graph::insertEdge(int u, int v, double w) {
    //if u or v is not within valid range
    if ((!((u < node_num && u >= 0) && (v < node_num && v >= 0) && w > 0.0)) || u == v) {
        throw illegal_argument();
    }
    //if u or v is within valid range and w > 0, can insert edge
    else {    
        //if updating edge weight between two nodes
        if (adj_matrix[u][v] != 0) {
            Node* node_u = nodes[u]; 
            Node* node_v = nodes[v];

            for (int i = 0; i < e_set.size(); i++){
                if ((e_set[i].ver1 == node_u) && (e_set[i].ver2 == node_v)) {
                    e_set[i].weight = w;
                }

                else if (e_set[i].ver1 == node_v && e_set[i].ver2 == node_u) {
                    e_set[i].weight = w;
                }
            }
        }
        //if inserting edge between two nodes
        else {
            edge_num++;
            Edge e(nodes[u], nodes[v], w);
            e_set.push_back(e); 
        }

        adj_matrix[u][v] = w;
        adj_matrix[v][u] = w;

        cout << "success" << endl;
    }
}

//deleting an edge between u and v
void Graph::deleteEdge(int u, int v) {
    //if u or v outside of valid range
    if (!((u < node_num && u >= 0) && (v < node_num && v >= 0))) {
        throw illegal_argument();
    }
    //if there is no edge between u and v
    else if ((adj_matrix[u][v] && adj_matrix[v][u]) == 0.0) {
        cout << "failure" << endl;
    }
    //if there is an edge between u and v
    else {
        adj_matrix[u][v] = 0;
        adj_matrix[v][u] = 0;
        edge_num--;

        Node* node_u = nodes[u]; 
        Node* node_v = nodes[v];

        for (int i = 0; i < e_set.size(); i++){
            if (e_set[i].ver1 == node_u && e_set[i].ver2 == node_v) {
                e_set.erase(e_set.begin() + i);
			}
            else if (e_set[i].ver1 == node_v && e_set[i].ver2 == node_u) {
                e_set.erase(e_set.begin() + i);
			}
        }

        cout << "success" << endl;
    }
}

//returns degree of vertex u
void Graph::degreeVertex(int u) {
    //if u is not within valid range
    if (u >= node_num || u < 0) {
        throw illegal_argument();
    }
    //if u is within valid range
    else {
        int degree = 0;
        for (int i = 0; i < node_num; i++) {
            if (adj_matrix[u][i] > 0.0) {
                degree++;
            }
        }
        
        cout << "degree of " << u << " is " << degree << endl;
    }
}

//returns number of edges in grpah
void Graph::edgeTotal() {
    cout << "edge count is " << edge_num << endl;
}

//removes all edges from graph
void Graph::clearGraph() {
    if (edge_num > 0) {
        for (int i = 0; i < node_num; i++) {
            for (int j = 0; j < node_num; j++) {
                adj_matrix[i][j] = 0.0;
            }
        }
    }
    //clears set of edges
    e_set.clear();
    edge_num = 0;
    
    cout << "success" << endl;
}

//function used in kruskalMST to reset the nodes that were manipulated
void Graph::resetNodes(){
    for (Node* node : nodes){
        node -> parent = node;
        node -> next = NULL;
    }
}

//gets the total weight of edges from the MST
void Graph::kruskalMST() {
    //not connected if only 1 node in graph
    if (node_num == 1) {
        cout << "not connected" << endl;
    }

    else {
        //resets the manipulated nodes
        resetNodes();
        //Kruskal's Algorithm 
        //create DisjointSets type object by passing in nodes vector of Graph class to initialize the individual sets of the nodes
        DisjointSets set(nodes);   
        //sorts the edges weights in asending order
        sort(e_set.begin(), e_set.end(), [](Edge & i, Edge & j) {
            return i.weight < j.weight;
            });
    
        double total_w = 0.0;
        //for each edge in sorted edges perform disjointSet operations to find the minimum weight of graph
        for (auto i : e_set) {
            Node* parent_v1 = set.findSet(i.ver1);
            Node* parent_v2 = set.findSet(i.ver2);
            
            if (parent_v1 != parent_v2) {
                set.unionSet(parent_v1, parent_v2);
                total_w += i.weight;
            }
        }
        //checks number of sets in disjoint set 
        int num_sets = 0;
        for (int i = 0; i < set.disjoint_set.size(); i++) {
            if (set.disjoint_set[i] != NULL) {
                num_sets++;
            }
        }
        //if number of sets in disjoint set is greater than 1, then graph is disconnected
        if (num_sets > 1) {
            cout << "not connected" << endl;
        }
        //else graph is connected and can display total weight
        else {
            cout << "mst " << total_w << endl;
        }
    }
}
