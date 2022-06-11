#include "catalogue.h"

Catalogue::Catalogue(string fileName)
{
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
    string seriesType = "series";
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
        }
        else
        {
            // Each one of the durations are read
            stringstream ssd((*itCatalogueData)[3]);
            string duationString;
            int duationInt;
            vector<int> duartionsVector;
            while(getline(ssd, duationString, ';'))
            {
                stringstream ssdr;
                ssdr << duationString;
                ssdr >> duationInt;
                duartionsVector.push_back(duationInt);
            }

            // Each one of the ratings is read
            stringstream ssrg((*itCatalogueData)[5]);
            string ratingString;
            float ratingFloat;
            vector<float> ratingsVector;
            while(getline(ssrg, ratingString, ';'))
            {
                stringstream ssrgr;
                ssrgr << ratingString;
                ssrgr >> ratingFloat;
                ratingsVector.push_back(ratingFloat);
            }

            // Each one of the ratings is read
            stringstream ssrs((*itCatalogueData)[6]);
            string ratersString;
            int ratersInt;
            vector<int> ratersVector;
            while(getline(ssrs, ratersString, ';'))
            {
                stringstream ssrsr;
                ssrsr << ratersString;
                ssrsr >> ratersInt;
                ratersVector.push_back(ratersInt);
            }

            // Each one of the titles is read
            stringstream ssti((*itCatalogueData)[7]);
            string titlesString;
            vector<string> titlesVector;
            while(getline(ssti, titlesString, ';'))
            {
                titlesVector.push_back(titlesString);
            }

            // Each one of the seasons is read
            stringstream ssse((*itCatalogueData)[8]);
            string seasonsString;
            int seasonInt;
            vector<int> seasonsVector;
            while(getline(ssse, seasonsString, ';'))
            {
                stringstream ssser;
                ssser << seasonsString;
                ssser >> seasonInt;
                seasonsVector.push_back(seasonInt);
            }
            string name = (*itCatalogueData)[2];
            string genre = (*itCatalogueData)[4];

            // Creamos vector de episodios
            vector<vector<Episode*> > seriesEpisodes;
            vector<Episode*> seasonEpisodes;
            int countEpisode = 1;
            int tempSeason = 1;
            for(int i = 0; i < duartionsVector.size(); i++)
            {
                if(seasonsVector[i + 1] != tempSeason){

                    string ID = "S_" + (*itCatalogueData)[0] + "_" + to_string(seasonsVector[i]) + "_" + to_string(countEpisode);
                    seasonEpisodes.push_back(new Episode(ID, name, duartionsVector[i], genre, ratingsVector[i], ratersVector[i], titlesVector[i], seasonsVector[i]));
                    countEpisode += 1;

                    seriesEpisodes.push_back(seasonEpisodes);
                    seasonEpisodes.clear();
                    tempSeason += 1;
                    countEpisode = 1;

                }else{
                    string ID = "S_" + (*itCatalogueData)[0] + "_" + to_string(seasonsVector[i]) + "_" + to_string(countEpisode);
                    seasonEpisodes.push_back(new Episode(ID, name, duartionsVector[i], genre, ratingsVector[i], ratersVector[i], titlesVector[i], seasonsVector[i]));
                    countEpisode += 1;
                }
            }

            // Instanciamos un objeto de tipo Serie utilizando el vector generado
            string ID = "S_" + (*itCatalogueData)[0];
            videos.push_back(new Serie(ID, name, genre, seriesEpisodes));
            seriesEpisodes.clear();
        }
    }
}

Catalogue::~Catalogue()
{
    ; // Null statement
}

string Catalogue::toString()
{
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

void Catalogue::toCsv()
{
    ofstream outputFile;
    outputFile.open("dataBase2.csv");
    // 2,series,Breaking Bad,123;35;65;56,Action,4.5;2.2;3.8;4.9,1246;3245;765;9856,Titulo 1;Titulo 2;Titulo 3;Titulo 4,1;1;2;3
    outputFile << "index,type,name,duartion,genre,rating,raters,episodeTitles,seasonNumbers\n";
    outputFile << "1,movie,El Lobo de Wallstreet,123,Action,4.5,1246\n";
    outputFile << "2,series,Breaking Bad,123;35;65;56,Action,4.5;2.2;3.8;4.9,1246;3245;765;9856,Titulo 1;Titulo 2;Titulo 3;Titulo 4,1;1;2;3\n";
    outputFile << "3,movie,Mi Villano Favorito,63,Comedy,2.5,6632\n";
    outputFile << "4,movie,Lluvia de Hamburguesas,90,Action,4,14937\n";


    int indexNumber = 1;
    vector<Video*>::iterator it;
    for(it = videos.begin(); it != videos.end(); it++)
    {
        try{
            (*it)->getEpisodes();
            throw "Movies don't have episodes!";
        }
        //cout << "Sereies" << endl;
        catch(...){
            cout << "Movie" << endl;
        }
    }

    outputFile.close();
}