#include "serie.h"

Serie::Serie()
{
    seasons = 0;
}

Serie::Serie(vector<vector<Episode*> > episodes, int seasons)
{
    this -> episodes = episodes;
    this -> seasons = seasons;
}

Serie::~Serie()
{
    episodes.clear(); 
}

string Serie::toString()
{
    string txt = "";
    txt += "[*] " + episodes[0][0]->getName() + "\n";
    vector<vector<Episode*> >::iterator itSeasons;
    vector<Episode*>::iterator itEpisodes;
    for(itSeasons = episodes.begin(); itSeasons != episodes.end(); itSeasons++){
        for(itEpisodes = (*itSeasons).begin(); itEpisodes != (*itSeasons).end(); itEpisodes++){
            txt += (*itEpisodes)->toString() + "\n";
        }
    }
    return txt;
}

float Serie::averageRating()
{
    return 0;
}