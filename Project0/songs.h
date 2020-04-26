#ifndef SONGS_H
#define SONGS_H

using namespace std;

class Songs {
private:
    string song_title;
    string song_artist;

public:
    Songs();

    ~Songs();

    //song title function declaration
    void setTitle(string title);

    string getTitle();

    //song artist function declaration
    void setArtist(string artist);
    
    string getArtist();
};

#endif //SONGS_H