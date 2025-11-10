#ifndef __SONG_H__
#define __SONG_H__

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "priority_queue.h"

using namespace std;

class Song {
  public:
    std::string artist,title;
    int count;

    Song() { }
    Song(const Song &s) : artist(s.artist), title(s.title), count(s.count) { }
    Song(std::string artist,std::string title,int count) :  artist(artist), title(title), count(count) { }

    friend std::ostream& operator<<(std::ostream &out,const Song &s) {
      return out << "Artist: " << s.artist << " Title: " << s.title << " count: " << s.count;
    }

};

struct mn{
  bool operator()(const Song& s,const Song& b){
    if(s.artist != b.artist) return s.artist > b.artist;
    if(s.title  != b.title) return s.title > b.title;
    return s.count>b.count;
  }
};
struct mx{
  bool operator()(const Song &s,const Song &b){
    if (s.count != b.count) return s.count < b.count;     
    if (s.artist != b.artist) return s.artist > b.artist; 
    return s.title > b.title;
  }
};

CP::priority_queue<Song,mn> pq1;
CP::priority_queue<Song,mx> pq2;



#endif
