#ifndef __SERIE
#define __SERIE

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "video.h"
#include "movie.h"
#include "episode.h"

class Serie : public Video
{
    private:
        vector<vector<Episode*> > episodes;
        int seasons;

    public:
        // Constructor and Destructor Method
        Serie();
        Serie(string ID, string name, string genre,  vector<vector<Episode*> > episodes);
        ~Serie();

        // Getter method for the array of arrays of episodes
        vector<vector<Episode*> > getEpisodes();

        // Aditional methods
        string toString();
        float averageRating();
        int totalDuration();
        int totalRaters();

};

#endif