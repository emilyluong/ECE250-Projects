all: qtdriver

qtdriver: qttest.cpp QuadTree.cpp QuadTree.h QuadNode.cpp QuadNode.h
	g++ -std=c++11 -o qtdriver qttest.cpp QuadTree.cpp QuadNode.cpp

clean:
	rm qtdriver *.o