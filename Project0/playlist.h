#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "songs.h"

using namespace std;

class Playlist {
private:
    int playlist_size;
    Songs *playlist_ptr;

public:
    Playlist(int max);

    Playlist();

    ~Playlist();

    void addSong(string s, string a);

    void playSongInPosition(int n);

    void deleteSongInPosition(int n);
};

#endif //PLAYLIST_H