#include "serie.h"

Serie::Serie() : Video()
{
    seasons = 0;
}

Serie::Serie(string ID, string name, string genre, vector<vector<Episode*> > episodes) : Video()
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

vector<vector<Episode*> > Serie::getEpisodes(){
    return episodes;
}

string Serie::toString()
{
    string txt = "";
    txt += "[*]【Series】" + name + " : " + ID + "\n";
    txt += "\t-Total Duration: " + to_string(duration) + " min.\n";
    txt += "\t-Genre:          " + genre + ".\n";
    txt += "\t-Average Rating: ";

    // Add stars to the ranting
    for(int i = 0; i < (int) rating; i++)
        txt += "⭐️ ";   //  character in unicode: "\U00012B50 "

    txt += to_string(rating) + " stars.\n";
    txt += "\t-Total Raters:   " + to_string(raters) + " raters.\n";
    
    vector<vector<Episode*> >::iterator itSeasons;
    vector<Episode*>::iterator itEpisodes;

    for(itSeasons = episodes.begin(); itSeasons != episodes.end(); itSeasons++){
        for(itEpisodes = (*itSeasons).begin(); itEpisodes != (*itSeasons).end() - 1; itEpisodes++){
            txt += (*itEpisodes)->toString() + "\n";
        }
        txt += (*(itEpisodes))->toString();
        if(itSeasons != episodes.end() - 1){
            txt += "\n";
        }
    }
    return txt;
}

string Serie::toReviewString(){
    int index = 1;
    string txt = "";
    vector<vector<Episode*> >::iterator itSeasons;
    vector<Episode*>::iterator itEpisodes;

    for(itSeasons = episodes.begin(); itSeasons != episodes.end(); itSeasons++){
        for(itEpisodes = (*itSeasons).begin(); itEpisodes != (*itSeasons).end(); itEpisodes++){
            txt += "\t" + to_string(index) + ") " + (*itEpisodes)->getTitle() + "\n";
            index += 1;
        }

    }
    return txt;
}

string Serie::toCsvString(int &indexNum)
{
    string txt = "";
    vector<vector<Episode *> >::iterator it;
    vector<Episode *>::iterator chapter;

    // For season
    for(it = episodes.begin(); it != episodes.end(); ++it)
    {
        // For episode
        for(chapter = (*it).begin(); chapter != (*it).end(); ++chapter)
        {
            txt += (*chapter) -> toCsvString(indexNum) + "\n";
            indexNum += 1;
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
                Video* res = (*(*itSeason) + *(*(itSeason + 1)));
                
                totalRating += res->getRating();
                totalRaters += res->getRaters();
                totalDuration += res->getDuration();

                totalEpisodes += 2;
            }
        }
        else
        {
            for(itSeason = (*itEpisodes).begin(); itSeason != (*itEpisodes).end() - 1; itSeason += 2)
            {
                Video* res = (*(*itSeason) + *(*(itSeason + 1)));

                totalRating += res->getRating();
                totalRaters += res->getRaters();
                totalDuration += res->getDuration();

                totalEpisodes += 2;
            }
            
            Video* res = (*(*itSeason) + *(*itSeason));
                
            totalRating += res->getRating() / 2;
            totalRaters += res->getRaters() / 2;
            totalDuration += res->getDuration() / 2;

            totalEpisodes += 1;
        }
    }
    setRaters(totalRaters);
    setDuration(totalDuration);
    return totalRating / totalEpisodes;
}

int Serie::totalDuration()
{
    return duration;
}

int Serie::totalRaters()
{
    return raters;
}