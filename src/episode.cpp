#include "episode.h"

Episode::Episode() : Video()
{
	title = "";
	season = 0;
}

Episode::Episode(string ID, string name, int duration, string genre, float rating, int raters, string title, int season) : Video(ID, name, duration, genre, rating, raters)
{
	this -> title = title;
	this -> season = season;
}

Episode::~Episode()
{
	; // Null statement
}

string Episode::toString()
{
    string txt = "";
    txt += "[*] " + name + ", Season "+ to_string(season) + ", Episode \"" + title + "\" : " + ID + "\n";
    txt += "\t-Duration: " + to_string(duration) + " min.\n";
    txt += "\t-Genre:    " + genre + ".\n";
    txt += "\t-Rating:   " + to_string(rating) + " stars.\n";
    txt += "\t-Raters:   " + to_string(raters) + " raters.";

    return txt;
}