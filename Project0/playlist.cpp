#include <iostream>
#include "playlist.h"
#include "songs.h"

Playlist::Playlist(int max) {
    playlist_ptr = new Songs[max];
    playlist_size = max;
    cout << "success" << endl;
}

Playlist::Playlist() {
    playlist_ptr = new Songs[1];
    playlist_size = 1;
    cout << "success" << endl;
}

Playlist::~Playlist() {
    delete [] playlist_ptr;
}

void Playlist::addSong(string s, string a) {
    bool is_duplicate = false;
    int index = -1;
    bool indexIsNeeded = true;
    for (int i = 0; i < playlist_size; i++) {
        if (playlist_ptr[i].getArtist() == a && playlist_ptr[i].getTitle() == s) {
            is_duplicate = true;
        }
        if (playlist_ptr[i].getArtist() == "" && playlist_ptr[i].getTitle() == "" && indexIsNeeded == true) {
            index = i;
            indexIsNeeded = false;
        }
    }
    if (is_duplicate == true) {
        cout << "can not insert " << s << ';' << a << endl;
    }
    else if (index == -1) {
        cout << "can not insert " << s << ';' << a << endl;
    }
    else {
        playlist_ptr[index].setTitle(s);
        playlist_ptr[index].setArtist(a);
        cout << "success" << endl;
    }
}

void Playlist::playSongInPosition(int n) {
    if (playlist_ptr[n - 1].getTitle() != "" && playlist_ptr[n - 1].getArtist() != "") {
        string title_pos = playlist_ptr[n - 1].getTitle();
        string artist_pos = playlist_ptr[n - 1].getArtist();
        cout << "played " << n << ' ' << title_pos << ';' << artist_pos << endl;
    }
    else {
        cout << "can not play " << n << endl;
    }
}

void Playlist::deleteSongInPosition(int n) {
    if (playlist_ptr[n - 1].getTitle() != "" && playlist_ptr[n - 1].getArtist() != "") {
        for (int i = (n - 1); i < playlist_size; i++) {
            if (i == (playlist_size - 1)) {
                playlist_ptr[i].setTitle("");
                playlist_ptr[i].setArtist("");
            }
            else {
                playlist_ptr[i].setTitle(playlist_ptr[i + 1].getTitle());
                playlist_ptr[i].setArtist(playlist_ptr[i + 1].getArtist());
            }
        }
        cout << "success" << endl;
    }
    else {
        cout << "can not erase " << n << endl;
    }
}
