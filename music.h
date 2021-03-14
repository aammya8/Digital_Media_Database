//music header file

#ifndef music_H
#define music_H

#include <string>
#include "digital_media.h"

using namespace std;

class music: public digital_media {
public:
	music(string t, string a, int y, int d, string p);
	string getPublisher();
	string getArtist();
	int getDuration();
private:
	string artist;
	string publisher;
	int duration;
};


#endif