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
    vector<vector<Episode*> > episodesSeries;
    vector<Episode*> episodesSeason;
    int episodeNum = 1;
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
        else if((*itCatalogueData)[1] == seriesType)
        {
            stringstream ssd;
			stringstream ssrg;
            stringstream ssrs;
            stringstream ssse;

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
            string title = (*itCatalogueData)[7];
            int season;
            ssse << (*itCatalogueData)[8];
            ssse >> season;

            try
            {
                if(itCatalogueData + 1 == catalogueData.end()){
                    throw "allocation error";
                }

                if((*(itCatalogueData + 1))[1] == seriesType)
                {
                    int nextSeason;
                    ssse << (*(itCatalogueData + 1))[8];
                    ssse >> nextSeason;
                    if((*(itCatalogueData + 1))[2] != name)
                    {
                        string IdEpisode = "S_" + (*itCatalogueData)[0] + "_" + to_string(season) + "_" + to_string(episodeNum);
                        string IdSeries  = "S_" + (*itCatalogueData)[0];
                        episodesSeason.push_back(new Episode(IdEpisode, name, duration, genre, rating, raters, title, season));
                        episodesSeries.push_back(episodesSeason);
                        episodesSeason.clear();
                        videos.push_back(new Serie(IdSeries, name, genre, episodesSeries));
                        episodeNum = 1;
                        episodesSeries.clear();
                    }
                    else if(nextSeason > season)
                    {
                        string IdEpisode = "S_" + (*itCatalogueData)[0] + "_" + to_string(season) + "_" + to_string(episodeNum);
                        episodeNum = 1;
                        episodesSeason.push_back(new Episode(IdEpisode, name, duration, genre, rating, raters, title, season));
                        episodesSeries.push_back(episodesSeason);
                        episodesSeason.clear();
                    }
                    else
                    {
                        string IdEpisode = "S_" + (*itCatalogueData)[0] + "_" + to_string(season) + "_" + to_string(episodeNum);
                        episodeNum += 1;
                        episodesSeason.push_back(new Episode(IdEpisode, name, duration, genre, rating, raters, title, season));
                    }
                }
                else
                {
                    string IdEpisode = "S_" + (*itCatalogueData)[0] + "_" + to_string(season) + "_" + to_string(episodeNum);
                    string IdSeries  = "S_" + (*itCatalogueData)[0];
                    episodesSeason.push_back(new Episode(IdEpisode, name, duration, genre, rating, raters, title, season));
                    episodesSeries.push_back(episodesSeason);
                    episodesSeason.clear();
                    videos.push_back(new Serie(IdSeries, name, genre, episodesSeries));
                    episodeNum = 1;
                    episodesSeries.clear();
                }
            }
            catch(...)
            {
                string IdEpisode = "S_" + (*itCatalogueData)[0] + "_" + to_string(season) + "_" + to_string(episodeNum);
                string IdSeries  = "S_" + (*itCatalogueData)[0];
                episodesSeason.push_back(new Episode(IdEpisode, name, duration, genre, rating, raters, title, season));
                episodesSeries.push_back(episodesSeason);
                episodesSeason.clear();
                videos.push_back(new Serie(IdSeries, name, genre, episodesSeries));
                episodeNum = 1;
                episodesSeries.clear();
            }
        }
    }
}

Catalogue::~Catalogue()
{
    videos.clear(); 
}

vector<Video *> Catalogue::getVideos()
{
    return videos;
}

void Catalogue::setVideos(vector<Video *> videos)
{
    this -> videos = videos;
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
    outputFile.open("dataBase.csv");
    
    // HEADER
    outputFile << "index,type,name,duartion,genre,rating,raters,episodeTitles,seasonNumbers\n";
    
    int indexNumber = 1;
    vector<Video*>::iterator it;
    for(it = videos.begin(); it != videos.end(); ++it)
    {
        // We can process this polymorphically 
        outputFile << (*it) -> toCsvString(indexNumber);
    }

    outputFile.close();
}

void Catalogue::organizeRatingAscendente(){ //metodo para ordenar videos de mayor a menor RATING
    Video *auxiliar;
    
    for (int i=0;i<this->videos.size();i++){
        for(int j=0;j<this->videos.size()-1;j++){
            if (this->videos.at(j)->getRating() > this->videos.at(j+1)->getRating()){
                //ordena de mayor a menor por rating
                auxiliar=this->videos.at(j);
                this->videos.at(j)=this->videos.at(j+1);
                this->videos.at(j+1)=auxiliar;
                
            }
                
        }
    }
}//cierre de organizeAscendente

void Catalogue::organizeRatingDescendente(){ //ordenar videos de menor a mayor RATING
    
    Video *auxiliar;
    
    for (int i=0;i<this->videos.size();i++){
        for(int j=0;j<this->videos.size()-1;j++){
            if (this->videos.at(j)->getRating() < this->videos.at(j+1)->getRating()){
                //ordena de mayor a menor por rating
                auxiliar=this->videos.at(j);
                this->videos.at(j)=this->videos.at(j+1);
                this->videos.at(j+1)=auxiliar;
                
            }
                
        }
    }
}//cierre de organizeDescente

void Catalogue::organizeRatersDescendente(){
    
    
    Video *auxiliar;
    
    for (int i=0;i<this->videos.size();i++){
        for(int j=0;j<this->videos.size()-1;j++){
            if (this->videos.at(j)->getRaters() < this->videos.at(j+1)->getRaters()){
                //ordena de mayor a menor por NUM DE RATERS
                auxiliar=this->videos.at(j);
                this->videos.at(j)=this->videos.at(j+1);
                this->videos.at(j+1)=auxiliar;
                
            }       
        }
    } 
}//cierre de organizeRatersDescendente()

void Catalogue::organizeRatersAscendente(){
    Video *auxiliar;
    
    for (int i=0;i<this->videos.size();i++){
        for(int j=0;j<this->videos.size()-1;j++){
            if (this->videos.at(j)->getRaters() > this->videos.at(j+1)->getRaters()){
                //ordena de menor a mayor por NUM DE RATERS
                auxiliar=this->videos.at(j);
                this->videos.at(j)=this->videos.at(j+1);
                this->videos.at(j+1)=auxiliar;       
            }
        }
    }
}// cierre de organizeRatersAscendente()

void Catalogue::organizeDuracionAscendente(){
    
    Video *auxiliar;
    
    for (int i=0;i<this->videos.size();i++){
        for(int j=0;j<this->videos.size()-1;j++){
            if (this->videos.at(j)->getDuration() > this->videos.at(j+1)->getDuration()){
                //ordena de menor a mayor por DURACION
                auxiliar=this->videos.at(j);
                this->videos.at(j)=this->videos.at(j+1);
                this->videos.at(j+1)=auxiliar;
                
            }            
        }
    }
} // cierre organizeDuracionAscendente()

void Catalogue::organizeDuracionDescendente(){
    Video *auxiliar;
    
    for (int i=0;i<this->videos.size();i++){
        for(int j=0;j<this->videos.size()-1;j++){
            if (this->videos.at(j)->getDuration() < this->videos.at(j+1)->getDuration()){
                //ordena de mayor a menor por DURACION
                auxiliar=this->videos.at(j);
                this->videos.at(j)=this->videos.at(j+1);
                this->videos.at(j+1)=auxiliar;
                
            }         
        }
    }
} //cierre organizeDuracionDescendente()
