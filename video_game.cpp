
//------------------------------------------------------------CHILD CLASS------------------------------------------------------------
//-----------------------------------------------------EXTENDS digital_media CLASS---------------------------------------------------

#include "video_game.h"

using namespace std;

video_game::video_game(string t, int y, string p, int r) {
	digital_media::title = t;
	digital_media::year = y;
	publisher = p;
	rating = r;
	digital_media::media_type = "VIDEOGAME";
}


string video_game::getPublisher() {
	return publisher;
}

int video_game::getRating() {
	return rating;
}



