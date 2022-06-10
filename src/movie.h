#ifndef __MOVIE
#define __MOVIE

#pragma once
#include "video.h"

class Movie: public Video
{
    public:
        // Constructors & Destructor 
        Movie();
        Movie(string ID, string name, int duration, string genre, float rating, int raters);
        ~Movie();

        // Overriding method
        string toString();     
};

#endif