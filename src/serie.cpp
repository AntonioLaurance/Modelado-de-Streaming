#include "serie.h"

Serie::Serie() : Video()
{
    seasons = 0;
}

Serie::Serie(string ID, string name, string genre,  vector<vector<Episode*> > episodes) : Video()
{
    this -> episodes = episodes;
    seasons = episodes.size();
    setID(ID);
    setName(name);
    setDuration(totalDuration());
    setGenre(genre);
    setRating(averageRating());
    setRaters(totalRaters());
}

Serie::~Serie()
{
    episodes.clear(); 
}

string Serie::toString()
{
    string txt = "";
    txt += "[*]【Series】" + name + "\n";
    vector<vector<Episode*> >::iterator itSeasons;
    vector<Episode*>::iterator itEpisodes;
    for(itSeasons = episodes.begin(); itSeasons != episodes.end(); itSeasons++){
        for(itEpisodes = (*itSeasons).begin(); itEpisodes != (*itSeasons).end() - 1; itEpisodes++){
            txt += (*itEpisodes)->toString() + "\n";
        }
        txt += (*(itEpisodes))->toString();
        if(itSeasons != episodes.end() -1){
            txt += "\n";
        }
    }
    return txt;
} 

float Serie::averageRating()
{
    return 0;
}

int Serie::totalDuration()
{
    return 0;
}

int Serie::totalRaters()
{
    return 0;
}