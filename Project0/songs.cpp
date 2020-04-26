#include <string>
#include "songs.h"

Songs::Songs() {
    song_title = "";
    song_artist = "";
}

Songs::~Songs() {
    
}

void Songs::setTitle(string title) {
    song_title = title;
}

string Songs::getTitle() {
    return song_title;
}

void Songs::setArtist(string artist) {
    song_artist = artist;
}

string Songs::getArtist() {
    return song_artist;
}