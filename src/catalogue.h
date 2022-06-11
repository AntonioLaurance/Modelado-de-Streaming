#ifndef __CATALOGUE
#define __CATALOGUE

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include "video.h"
#include "movie.h"
#include "episode.h"
#include "serie.h"

class Catalogue
{
    private:
        vector<Video*> videos;

    public:
        Catalogue(string fileName);
        ~Catalogue();

        string toString();
        void toCsv();
};

#endif