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
            stringstream ssd;
			stringstream ssrg;
            stringstream ssrs;
            
            string ID = "P_" + (*itCatalogueData)[0];
            string name = (*itCatalogueData)[2];
            int duration;
            ssd << (*itCatalogueData)[3];
            ssd >> duration;
            string genre = (*itCatalogueData)[4];
            float rating;
            ssrg << (*itCatalogueData)[5];
            ssrg >> rating;
            int raters;
            ssrs << (*itCatalogueData)[6];
            ssrs >> raters;

            videos.push_back(new Movie(ID, name, duration, genre, rating, raters));
        }else{
            /*FALTA IMPLEMENTA ESTE TIPO DE IDEA PARA LAS SERIES*/
            // Tomar en cuenta que cada serie tiene varios capitulos, cada capitulo tiene tíyulo, rating, raters, etc propios
            // lo cual, se va a almacenar en la base de datos de la siguinete manera
            // 2,series,Breaking Bad,123;35;65;56,Action,4.5;2.2;3.8;4.9,1246;3245;765;9856,Titulo 1;Titulo 2; Titulo 3; Titulo 4,1;1;2;3
            // lo que esta entre comas (,) es lo que tienen en comun todos los episodios de la serie, lo que esta entre punto y coma (;) son las características propias del
            // episodio
        }
    }
}

Catalogue::~Catalogue(){
    ; // Null statement
}

string Catalogue::toString(){
    string txt = "";
    txt += "#############\n";
    txt += "# CATALOGUE #\n";
    txt += "#############\n\n";

    vector<Video*>::iterator it;
    for(it = videos.begin(); it != videos.end(); it++){
        txt += (*it)->toString();
        txt += "\n\n";
    }
    return txt;
}