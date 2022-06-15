#ifndef __MOVIE
#define __MOVIE

#pragma once
#include "content.h"

class Movie: public Content
{
    public:
        // Constructors & Destructor 
        Movie();
        Movie(string ID, string name, int duration, string genre, float rating, int raters);
        ~Movie();

        // Overriding method
        string toString();  
        string toCsvString(int &indexNum);
};

#endif