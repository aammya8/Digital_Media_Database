//video_game header file

// #include guards
#ifndef video_game_H
#define video_game_H

#include <string>
#include "digital_media.h"
using namespace std;

class video_game: public digital_media {
public:
	video_game(string t, int y, string p, int r);
	string getPublisher();
	int getRating();
private:
	string publisher;
	int rating;
};

#endif