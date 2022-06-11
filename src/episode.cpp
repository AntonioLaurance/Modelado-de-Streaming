#include "episode.h"

Episode::Episode(long usigned, int ID, string name, Time duration, char genre, string title, short unsigned int season, short float status): Video(ID, name, duration, genre, status)
{
	this -> season = season;
	this -> title = title;
}

Episode::~Episode()
{
	;
}


