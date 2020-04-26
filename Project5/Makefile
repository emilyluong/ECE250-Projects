all: undirectedGraphdriver

undirectedGraphdriver: undirectedGraphtest.cpp Graph.cpp Node.cpp AdjNode.cpp Edge.cpp PriorityQueue.cpp
	g++ -std=c++11 -o undirectedGraphdriver undirectedGraphtest.cpp Graph.cpp Node.cpp AdjNode.cpp Edge.cpp PriorityQueue.cpp

clean:
	rm -f undirectedGraphdriver *.o
