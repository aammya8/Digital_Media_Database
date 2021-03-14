//movie header file

// #include guards
#ifndef movie_H
#define movie_H

#include <string>
#include "digital_media.h"
using namespace std;

class movie: public digital_media {
public:
	movie(string t, string dir, int y, int dur, int r);
	string getDirector();
	int getDuration();
	int getRating();
private:
	string director;
	int duration;
	int rating;
};

#endif