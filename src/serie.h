#ifndef __SERIE
#define __SERIE

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "episode.h"

class Serie
{
    private:
        vector<vector<Episode*> > episodes;
        int seasons;

    public:
        // Constructor and Destructor Method
        Serie();
        Serie(vector<vector<Episode*> > episodes, int seasons);
        ~Serie();

        string toString();
        float averageRating();

};

#endif