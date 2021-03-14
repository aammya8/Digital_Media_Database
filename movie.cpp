
//------------------------------------------------------------CHILD CLASS------------------------------------------------------------
//-----------------------------------------------------EXTENDS digital_media CLASS---------------------------------------------------

#include <string>
#include "movie.h"

using namespace std;

movie::movie(string t, string dir, int y, int dur, int r) {
	digital_media::title = t;
	director = dir;
	digital_media::year = y;
	duration = dur;
	rating = r;
	digital_media::media_type = "MOVIE";
}

string movie::getDirector() {
	return director;
}

int movie::getRating() {
	return rating;
}

int movie::getDuration() {
	return duration;
}