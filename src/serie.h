#ifndef __SERIE
#define __SERIE

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "content.h"
#include "movie.h"
#include "episode.h"

class Serie : public Content
{
    private:
        vector<vector<Episode*> > episodes;
        int seasons;

    public:
        // Constructor and Destructor Method
        Serie();
        Serie(string ID, string name, string genre, vector<vector<Episode*> > episodes);
        ~Serie();

        // Getter method for the array of arrays of episodes
        vector<vector<Episode*> > getEpisodes();

        // Aditional methods
        string toString();
        string toCsvString(int &indexNum);
        float averageRating();
        int totalDuration();
        int totalRaters();
};

#endif