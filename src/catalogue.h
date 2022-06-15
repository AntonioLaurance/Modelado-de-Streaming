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

        // Geter & Setter
        vector<Video *> getVideos();
        void setVideos(vector<Video *> videos);

        // Other methods
        string toString();
        void toCsv();
        vector<Video*> toSimpleVector();
        void organizeRatingAscendente(); //metodo para ordenar videos de mayor a menor
        void organizeRatingDescendente(); //metodo para ordenar videos de mayor a menor
        void organizeRatersDescendente();
        void organizeRatersAscendente();
        void organizeDuracionAscendente();
        void organizeDuracionDescendente();
};

#endif