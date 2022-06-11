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
    txt += "\t-Duration:    " + to_string(duration) + " min.\n";
    txt += "\t-Genre:       " + genre + ".\n";
    txt += "\t-Avg. Rating: " + to_string(rating) + "\n";
    
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
    float totalRating = 0, totalEpisodes = 0;
    int totalRaters = 0, totalDuration = 0;

    vector<vector<Episode*> >::iterator itEpisodes;
    vector<Episode*>::iterator itSeason;
    for(itEpisodes = episodes.begin(); itEpisodes != episodes.end(); itEpisodes++)
    {
        if((*itEpisodes).size() % 2 == 0)
        {
            for(itSeason = (*itEpisodes).begin(); itSeason != (*itEpisodes).end(); itSeason += 2)
            {
                
                totalRating += (*(*itSeason) + *(*(itSeason + 1)))->getRating();
                totalEpisodes += 2;
            }
        }
        else
        {
            for(itSeason = (*itEpisodes).begin(); itSeason != (*itEpisodes).end() - 1; itSeason += 2)
            {
                totalRating += (*(*itSeason) + *(*(itSeason + 1)))->getRating();
                totalEpisodes += 2;
            }
            totalRating += (*(*itSeason) + *(*(itSeason)))->getRating() / 2;
            totalEpisodes += 1;
        }
    }
    return totalRating / totalEpisodes;
}

int Serie::totalDuration()
{
    return 0;
}

int Serie::totalRaters()
{
    int totalRaters = 0;

    return 0;
}