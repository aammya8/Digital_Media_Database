
//------------------------------------------------------------CHILD CLASS------------------------------------------------------------
//-----------------------------------------------------EXTENDS digital_media CLASS---------------------------------------------------

#include <string>
#include "music.h"

using namespace std;


music::music(string t, string a, int y, int d, string p) {
	digital_media::title = t;
	artist = a;
	digital_media::year = y;
	duration = d;
	digital_media::media_type = "MUSIC";
	publisher = p;
}

string music::getArtist() {
	return artist;
}

int music::getDuration() {
	return duration;
}

string music::getPublisher() {
	return publisher;
}

