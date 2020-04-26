#include <iostream>
#include <string>
#include "songs.h"
#include "playlist.h"

using namespace std;

int main() {

    while(!(cin.eof())) {

        string line;
        getline(cin, line);

        if (line.substr(0, 1) == "m") {
            string max_str = line.substr(2, string::npos);
            int max_int = stoi(max_str);
            Playlist playlist_arr(max_int);

            while(getline(cin, line)) {     
                if (line.substr(0, 1) == "i") {
                    string song_t = line.substr(2, line.find(";") - 2);
                    string song_a = line.substr(line.find(";") + 1, string::npos);
                    playlist_arr.addSong(song_t, song_a);
                }

                else if (line.substr(0, 1) == "p") {
                    string play_str = line.substr(2, string::npos);
                    int play_int = stoi(play_str);
                    playlist_arr.playSongInPosition(play_int);
                }

                else if (line.substr(0, 1) == "e") {
                    string eras_str = line.substr(2, string::npos);
                    int eras_int = stoi(eras_str);
                    playlist_arr.deleteSongInPosition(eras_int);
                }
                else {

                }
            }
        }
    }
}