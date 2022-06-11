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
        vector<vector<Episode*>> episodes;
        int seasons;

    public:
        // Constructor and Destructor Method
        Serie();
        Serie(vector<Episode*> episodes, int seasons);

        string toString();
        float averageRating();

};


#endif