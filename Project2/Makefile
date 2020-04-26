all: openhttest orderedhttest
  
openhttest: openhttest.cpp hashentryopen.h hashentryopen.cpp hashmapopen.h hashmapopen.cpp 
	g++ -std=c++11 -o openhttest openhttest.cpp hashmapopen.cpp hashentryopen.cpp

orderedhttest: orderedhttest.cpp hashentrychain.h hashentrychain.cpp hashmapchain.h hashmapchain.cpp 
	g++ -std=c++11 -o orderedhttest orderedhttest.cpp hashmapchain.cpp hashentrychain.cpp

clean:
	rm -f openhttest orderedhttest *.o