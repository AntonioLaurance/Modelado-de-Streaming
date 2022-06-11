#include "catalogue.h"

Catalogue::Catalogue(string fileName){
    // Leemos el csv y guardamos los datos en un vector de vectores de string
    // Por cada video hacemos una nueva linea
    ifstream inputFile;
    inputFile.open(fileName);

    string line = "", cell = "";
    vector<vector<string> > catalogueData;
    vector<string> videoData;
    while(getline(inputFile, line))
    {
        videoData.clear();
        stringstream s(line);
        while (getline(s, cell, ','))
        {
            videoData.push_back(cell);
        }
        catalogueData.push_back(videoData);
    }
    inputFile.close();

    // recorremos el vector catalogueData, instanciamos objetos de tipo Movie,
    // Episode y Serie y guardamos todo eso en el vector videos
    vector<vector<string> >::iterator itCatalogueData;
    string movieType = "movie";
    for(itCatalogueData = catalogueData.begin(); itCatalogueData != catalogueData.end(); itCatalogueData++)
    {
        if((*itCatalogueData)[1] == movieType)
        {
            string ID = "P_" + (*itCatalogueData)[0];
            string name = (*itCatalogueData)[1];
            int duration = (*itCatalogueData)[0];	
            string genre = genre;
            float rating = rating;
            int raters = raters;
            videos.push_back(new Movie())
        }
    }
}

Catalogue::~Catalogue(){
    ; // Null statement
}

string Catalogue::toString(){
    return "Hello WOrld!";
}