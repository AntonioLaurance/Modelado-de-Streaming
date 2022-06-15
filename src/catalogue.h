#ifndef __CATALOGUE
#define __CATALOGUE

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include "content.h"
#include "movie.h"
#include "episode.h"
#include "serie.h"

class Catalogue
{
    private:
        vector<Content*> contents;

    public:
        Catalogue(string fileName);
        ~Catalogue();

        // Geter & Setter
        vector<Content *> getContents();
        void setContents(vector<Content *> Contents);

        // Other methods
        string toString();
        void toCsv();
        vector<Content*> toSimpleVector();
        void organizeRatingAscendente(); //metodo para ordenar Contents de mayor a menor
        void organizeRatingDescendente(); //metodo para ordenar Contents de mayor a menor
        void organizeRatersDescendente();
        void organizeRatersAscendente();
        void organizeDuracionAscendente();
        void organizeDuracionDescendente();
};

#endif