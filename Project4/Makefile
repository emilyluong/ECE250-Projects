all: mstdriver

mstdriver: msttest.cpp Node.cpp Edge.cpp Graph.cpp DisjointSet.cpp
	g++ -std=c++11 -o mstdriver msttest.cpp Node.cpp Edge.cpp Graph.cpp DisjointSet.cpp

clean:
	rm -f mstdriver *.o
