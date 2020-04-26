all: dequedriver
  
dequedriver: dequedriver.cpp node.h node.cpp deque.h deque.cpp deque_empty.h
	g++ -std=c++11 -o dequedriver dequedriver.cpp node.cpp deque.cpp

clean:
	rm dequedriver *.o                                
