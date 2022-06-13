#include "movie.h"

Movie::Movie() : Video()
{
    ; // Null statement
}

Movie::Movie(string ID, string name, int duration, string genre, float rating, int raters): Video(ID, name, duration, genre, rating, raters)
{
    ; // Null statement
}

Movie::~Movie()
{
    ID.clear();
    name.clear();
    genre.clear();
}

string Movie::toString()
{
    string txt = "";
    txt += "[*]【Movie】" + name + " : " + ID + "\n";
    txt += "\t-Duration: " + to_string(duration) + " min.\n";
    txt += "\t-Genre:    " + genre + ".\n";
    txt += "\t-Rating:   " ;
    
    // Add stars to the ranting
    for(int i = 0; i < (int) rating; i++)
        txt += "⭐️ ";   //  character in unicode: "\U00012B50 "

    txt +=  to_string(rating) + " stars.\n";
    txt += "\t-Raters:   " + to_string(raters) + " raters.";

    return txt;
}

string Movie::toCsvString()
{
    string txt = "movie," + name + "," + to_string(duration) + "," + genre + ",";
    txt += to_string(rating) + "," + to_string(raters);

    return txt;
}