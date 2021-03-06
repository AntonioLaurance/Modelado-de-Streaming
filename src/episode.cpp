#include "episode.h"

Episode::Episode() : Content()
{
	title = "";
	season = 0;
}

Episode::Episode(string ID, string name, int duration, string genre, float rating, int raters, string title, int season) : Content(ID, name, duration, genre, rating, raters)
{
	this -> title = title;
	this -> season = season;
}

Episode::~Episode()
{
    title.clear();
}

string Episode::toString()
{
    string txt = "";
    txt += "[*] " + name + ", Season "+ to_string(season) + ", Episode \"" + title + "\" : " + ID + "\n";
    txt += "\t-Duration: " + to_string(duration) + " min.\n";
    txt += "\t-Genre:    " + genre + ".\n";
    txt += "\t-Rating:   ";

    // Add stars to the ranting
    for(int i = 0; i < (int) rating; i++)
        txt += "⭐️ ";   //  character in unicode: "\U00012B50 "

    txt += to_string(rating) + " stars.\n";
    txt += "\t-Raters:   " + to_string(raters) + " raters.";

    return txt;
}

string Episode::toCsvString(int &indexNum)
{
    string txt = to_string(indexNum) + ",series," + name + "," + to_string(duration) + "," + genre + "," + to_string(rating) + "," + to_string(raters) + "," + title + "," + to_string(season);

    return txt;
}

string Episode::getTitle(){
    return title;
}