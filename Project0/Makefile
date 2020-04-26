all: playlistdriver

playlistdriver: playlistdriver.cpp playlist.h playlist.cpp songs.h songs.cpp
	g++ -std=c++11 -o playlistdriver playlistdriver.cpp playlist.cpp songs.cpp

clean:
	rm playlistdriver *.o