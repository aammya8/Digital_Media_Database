//Project Description: Create a database that includes video games, music, and movies. Allow user to add, search, and delete database items.
//Name: Aammya Sapra
//Date: 3-13-2021


//------------------------------------------------------------MAIN CLASS------------------------------------------------------------


#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include "digital_media.h"
#include "video_game.h"
#include "movie.h"
#include "music.h"

using namespace std;

vector<digital_media*> database;  //vector containing parent class
vector<digital_media*>::iterator it; //iterator

//function prototypes
void add_video_game(vector<digital_media*> &database);
void add_music(vector<digital_media*> &database);
void add_movie(vector<digital_media*> &database);
void search(vector<digital_media*> &database, string filter);
void delete_media(vector<digital_media*> &database, string filter);


//main function
int main() {

	//print out instructions/commands
	cout << '\n' << "To add item to media database type \'ADD\'." << endl;
	cout << "To search media database type \'SEARCH\'." << endl;
	cout << "To delete item from media database type \'DELETE\'." << endl;
	cout << "To quit type \'QUIT\'." << endl << endl;

	string command; //stores the command (ADD, SEARCH, DELETE, QUIT) inputted by the user
	string filter; //stores user response to whether item(s) being searched/deleted by title or year
	string type; //stores user response to what type of media is being added
	bool inputting = true;

	while (inputting) {
		cin >> command;
		if (command == "ADD") { 
			//ask for type of media being added
			cout << "To add a video game type \'VIDEOGAME\'." << endl;
			cout << "To add music type \'MUSIC\'." << endl;
			cout << "To add a movie type \'MOVIE\'." << endl << endl;
			cin >> type;
			if (type == "VIDEOGAME") {
				add_video_game(database); //call add video game function
			} else if (type == "MUSIC") {
				add_music(database); //call add music function
			} else if (type == "MOVIE") {
				add_movie(database); //call add movie function
			} else {
				cout << "Please enter either \'VIDEOGAME\', \'MUSIC\', or \'MOVIE\'" << endl;
			}
		} else if (command == "SEARCH") { 
			cout << "To search by title type \'TITLE\'" << endl;
			cout << "To search by year type \'YEAR\'" << endl;
			cin >> filter;
			while (filter != "TITLE" && filter != "YEAR") { //check for valid input
				cout << "Please enter either \'TITLE\' or \'YEAR\'" << endl;
				cin >> filter;
			}
			search(database, filter); //call search function
		} else if (command == "DELETE") { 
			cout << "To delete by title type \'TITLE\'" << endl;
			cout << "To delete by year type \'YEAR\'" << endl;
			cin >> filter;
			while (filter != "TITLE" && filter != "YEAR") { //check for valid input
				cout << "Please enter either \'TITLE\' or \'YEAR\'" << endl;
				cin >> filter;
			}
			delete_media(database, filter); //call delete function
		} else if (command == "QUIT") { //quit
			inputting = false;
			break;
		} else { //prompt user to re-enter command if something invalid was entered
			cout << "Please enter either \'ADD\', \'SEARCH\', \'DELETE\', or \'QUIT\'." << endl;
		}
	} 
	return 0;
}


//function to add video game to database
void add_video_game(vector<digital_media*> &database) {
	string title;
	int year;
	string publisher;
	int rating;

	cout << "Input title: ";
	cin >> title;
	cout << "Input year: ";
	cin >> year;
	cout << "Input publisher: ";
	cin >> publisher;
	cout << "Input rating: ";
	cin >> rating;

	video_game* g = new video_game(title, year, publisher, rating); // create new video game
	database.push_back(g); // add video game to digital media database
	cout << "Video game has been added. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl << endl;
	return;
}


//function to add music to database
void add_music(vector<digital_media*> &database) {
	string title;
	string artist;
	int year;
	int duration;
	string publisher;

	cout << "Input title: ";
	cin >> title;
	cout << "Input artist: ";
	cin >> artist;
	cout << "Input year: ";
	cin >> year;
	cout << "Input duration (min): ";
	cin >> duration;
	cout << "Input publisher: ";
	cin >> publisher;

	music* mu = new music(title, artist, year, duration, publisher); // create new music item
	database.push_back(mu); // add music to digital media database
	cout << "Music has been added. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl << endl;
	return;

}


//function to add movie to database
void add_movie(vector<digital_media*> &database) {
	string title;
	string director;
	int year;
	int duration;
	int rating;

	cout << "Input title: ";
	cin >> title;
	cout << "Input director: ";
	cin >> director;
	cout << "Input year: ";
	cin >> year;
	cout << "Input duration (min): ";
	cin >> duration;
	cout << "Input rating: ";
	cin >> rating;

	movie* m = new movie(title, director, year, duration, rating); // create new movie item
	database.push_back(m); // add movie to digital media database
	cout << "Movie has been added. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl << endl;
	return;
}


//function to search database by year or title and print results
void search(vector<digital_media*> &database, string filter) {
	string t; //title
	int y; //year
	bool found = false;

	if (filter == "TITLE") { //search and print by title
		cout << "Enter title: ";
		cin >> t;
		for (it = database.begin(); it < database.end(); it++) {
			if (t == (*it)->title) {
				found = true;
				if((*it)->media_type == "VIDEOGAME") {  //print video game information if title matches
					cout << "\nVIDEO GAME" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Publisher: " << static_cast<video_game*>(*it)->getPublisher() << endl;
					cout << "Rating: " << static_cast<video_game*>(*it)->getRating() << endl;
				} else if ((*it)->media_type == "MUSIC") {   //print music information if title matches
					cout << "\nMUSIC" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Artist: " << static_cast<music*>(*it)->getArtist() << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Duration: " << static_cast<music*>(*it)->getDuration() << endl;
					cout << "Publisher: " << static_cast<music*>(*it)->getPublisher() << endl;
				} else if ((*it)->media_type == "MOVIE") {  //print movie information if title matches
					cout << "\nMOVIE" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Director: " << static_cast<movie*>(*it)->getDirector() << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Duration: " << static_cast<movie*>(*it)->getDuration() << endl;
					cout << "Rating: " << static_cast<movie*>(*it)->getRating() << endl;
				}
			}
		}
		cout << "All matching items have been printed. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl << endl;
	} else if (filter == "YEAR") { //search and print by year
		cout << "Enter year: ";
		cin >> y;
		for (it = database.begin(); it < database.end(); it++) {
			if (y == (*it)->year) {
				found = true;
				if((*it)->media_type == "VIDEOGAME") {  //print video game information if title matches
					cout << "\nVIDEO GAME" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Publisher: " << static_cast<video_game*>(*it)->getPublisher() << endl;
					cout << "Rating: " << static_cast<video_game*>(*it)->getRating() << endl;
				} else if ((*it)->media_type == "MUSIC") {   //print music information if title matches
					cout << "\nMUSIC" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Artist: " << static_cast<music*>(*it)->getArtist() << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Duration: " << static_cast<music*>(*it)->getDuration() << endl;
					cout << "Publisher: " << static_cast<music*>(*it)->getPublisher() << endl;
				} else if ((*it)->media_type == "MOVIE") {  //print movie information if title matches
					cout << "\nMOVIE" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Director: " << static_cast<movie*>(*it)->getDirector() << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Duration: " << static_cast<movie*>(*it)->getDuration() << endl;
					cout << "Rating: " << static_cast<movie*>(*it)->getRating() << endl;
				}
			}
		}
		cout << "All matching items have been printed. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl << endl;
	}

	if (found == false) {
		cout << "No matching items were found. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl;
	}

	return;
}


//function to delete database item(s) based on year or title
void delete_media(vector<digital_media*> &database, string filter) {
	string t;
	int y;
	bool found = false;
	string response;

	if (filter == "TITLE") { //delete by title
		cout << "Enter title: ";
		cin >> t;
		for (it = database.begin(); it < database.end(); it++) {
			if (t == (*it)->title) {
				found = true;
				delete *it;
				database.erase(it);
				it--; //since deleted above
			}
		}
		cout << "Item(s) titled \'" << t << "\' have been deleted. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl << endl;
	} else if (filter == "YEAR") { //delete by year
		cout << "Enter year: ";
		cin >> y;
		for (it = database.begin(); it < database.end(); it++) {
			if (y == (*it)->year) {
				found = true;
				cout << "Would you like to delete the following item? (Y/N) " << endl;
				if((*it)->media_type == "VIDEOGAME") {  //print video game information if title matches
					cout << "\nVIDEO GAME" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Publisher: " << static_cast<video_game*>(*it)->getPublisher() << endl;
					cout << "Rating: " << static_cast<video_game*>(*it)->getRating() << endl;
				} else if ((*it)->media_type == "MUSIC") {   //print music information if title matches
					cout << "\nMUSIC" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Artist: " << static_cast<music*>(*it)->getArtist() << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Duration: " << static_cast<music*>(*it)->getDuration() << endl;
					cout << "Publisher: " << static_cast<music*>(*it)->getPublisher() << endl;
				} else if ((*it)->media_type == "MOVIE") {  //print movie information if title matches
					cout << "\nMOVIE" << endl;
					cout << "Title: " << (*it)->title << endl;
					cout << "Director: " << static_cast<movie*>(*it)->getDirector() << endl;
					cout << "Year: " << (*it)->year << endl;
					cout << "Duration: " << static_cast<movie*>(*it)->getDuration() << endl;
					cout << "Rating: " << static_cast<movie*>(*it)->getRating() << endl;
				}
				cin >> response;
				while (response != "Y" && response != "N") {
					cout << "Please enter \'Y\' or \'N\'." << endl;
					cin >> response;
				}
				if (response == "Y") {
					delete *it;
					database.erase(it);
					it--;
				}
				
			}
		}
		cout << "Item(s) from the year \'" << y << "\' have been deleted. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl << endl;
	}

	if (found == false) {
		cout << "No matching items were found. Enter \'ADD\', \'SEARCH\', \'DELETE\' to continue or \'QUIT\' to exit." << endl;
	}

	return;
}

