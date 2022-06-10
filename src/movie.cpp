#include "movie.h"

Movie::Movie() : Video(){

}

Movie::Movie(string ID, string name, int duration, string genre, float rating, int raters): Video(ID, name, duration, genre, rating, raters)
{
    ; // Null statement
}

Movie::~Movie()
{
    ; // Null statement
}

string Movie::toString()
{
    string txt = "";
    txt += "[*] " + name + " : " + ID + "\n";
    txt += "\t-Duration: " + to_string(duration) + " min.\n";
    txt += "\t-Genre:    " + genre + ".\n";
    txt += "\t-Rating:   " + to_string(rating) + " stars.\n";
    txt += "\t-Raters:   " + to_string(raters) + " raters.";

    return txt;
}
