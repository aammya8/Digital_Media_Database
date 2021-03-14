//digital_media header file

// #include guards
#ifndef digital_media_H
#define digital_media_H

#include <string>
using namespace std;

class digital_media {
public:
	digital_media();
	digital_media(string t, int y);
	string title;
	int year;
	string media_type;
};

#endif