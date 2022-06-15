#include "catalogue.h"

Catalogue::Catalogue(string fileName)
{
    // Leemos el csv y guardamos los datos en un vector de vectores de string
    // Por cada content hacemos una nueva linea
    ifstream inputFile;
    inputFile.open(fileName);

    string line = "", cell = "";
    vector<vector<string> > catalogueData;
    vector<string> contentData;
    while(getline(inputFile, line))
    {
        contentData.clear();
        stringstream s(line);
        while (getline(s, cell, ','))
        {
            contentData.push_back(cell);
        }
        catalogueData.push_back(contentData);
    }
    inputFile.close();

    // recorremos el vector catalogueData, instanciamos objetos de tipo Movie,
    // Episode y Serie y guardamos todo eso en el vector contents
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

            contents.push_back(new Movie(ID, name, duration, genre, rating, raters));
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
                        contents.push_back(new Serie(IdSeries, name, genre, episodesSeries));
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
                    contents.push_back(new Serie(IdSeries, name, genre, episodesSeries));
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
                contents.push_back(new Serie(IdSeries, name, genre, episodesSeries));
                episodeNum = 1;
                episodesSeries.clear();
            }
        }
    }
}

Catalogue::~Catalogue()
{
    contents.clear(); 
}

vector<Content *> Catalogue::getContents()
{
    return contents;
}

void Catalogue::setContents(vector<Content *> contents)
{
    this -> contents = contents;
}

string Catalogue::toString()
{
    string txt = "";
    txt += "#############\n";
    txt += "# CATALOGUE #\n";
    txt += "#############\n\n";

    vector<Content*>::iterator it;
    for(it = contents.begin(); it != contents.end(); it++){
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
    vector<Content*>::iterator it;
    for(it = contents.begin(); it != contents.end(); ++it)
    {
        // We can process this polymorphically 
        outputFile << (*it) -> toCsvString(indexNumber);
    }

    outputFile.close();
}

void Catalogue::organizeRatingAscendente(){ //metodo para ordenar contents de mayor a menor RATING
    Content *auxiliar;
    
    for (int i=0;i<this->contents.size();i++){
        for(int j=0;j<this->contents.size()-1;j++){
            if (this->contents.at(j)->getRating() > this->contents.at(j+1)->getRating()){
                //ordena de mayor a menor por rating
                auxiliar=this->contents.at(j);
                this->contents.at(j)=this->contents.at(j+1);
                this->contents.at(j+1)=auxiliar;
                
            }
                
        }
    }
}//cierre de organizeAscendente

void Catalogue::organizeRatingDescendente(){ //ordenar contents de menor a mayor RATING
    
    Content *auxiliar;
    
    for (int i=0;i<this->contents.size();i++){
        for(int j=0;j<this->contents.size()-1;j++){
            if (this->contents.at(j)->getRating() < this->contents.at(j+1)->getRating()){
                //ordena de mayor a menor por rating
                auxiliar=this->contents.at(j);
                this->contents.at(j)=this->contents.at(j+1);
                this->contents.at(j+1)=auxiliar;
                
            }
                
        }
    }
}//cierre de organizeDescente

void Catalogue::organizeRatersDescendente(){
    Content *auxiliar;
    
    for (int i=0;i<this->contents.size();i++){
        for(int j=0;j<this->contents.size()-1;j++){
            if (this->contents.at(j)->getRaters() < this->contents.at(j+1)->getRaters()){
                //ordena de mayor a menor por NUM DE RATERS
                auxiliar=this->contents.at(j);
                this->contents.at(j)=this->contents.at(j+1);
                this->contents.at(j+1)=auxiliar;
                
            }       
        }
    } 
}//cierre de organizeRatersDescendente()

void Catalogue::organizeRatersAscendente(){
    Content *auxiliar;
    
    for (int i=0;i<this->contents.size();i++){
        for(int j=0;j<this->contents.size()-1;j++){
            if (this->contents.at(j)->getRaters() > this->contents.at(j+1)->getRaters()){
                //ordena de menor a mayor por NUM DE RATERS
                auxiliar=this->contents.at(j);
                this->contents.at(j)=this->contents.at(j+1);
                this->contents.at(j+1)=auxiliar;       
            }
        }
    }
}// cierre de organizeRatersAscendente()

void Catalogue::organizeDuracionAscendente(){
    
    Content *auxiliar;
    
    for (int i=0;i<this->contents.size();i++){
        for(int j=0;j<this->contents.size()-1;j++){
            if (this->contents.at(j)->getDuration() > this->contents.at(j+1)->getDuration()){
                //ordena de menor a mayor por DURACION
                auxiliar=this->contents.at(j);
                this->contents.at(j)=this->contents.at(j+1);
                this->contents.at(j+1)=auxiliar;
                
            }            
        }
    }
} // cierre organizeDuracionAscendente()

void Catalogue::organizeDuracionDescendente(){
    Content *auxiliar;
    
    for (int i=0;i<this->contents.size();i++){
        for(int j=0;j<this->contents.size()-1;j++){
            if (this->contents.at(j)->getDuration() < this->contents.at(j+1)->getDuration()){
                //ordena de mayor a menor por DURACION
                auxiliar=this->contents.at(j);
                this->contents.at(j)=this->contents.at(j+1);
                this->contents.at(j+1)=auxiliar;
                
            }         
        }
    }
} //cierre organizeDuracionDescendente()

vector<Content*> Catalogue::toSimpleVector()
{
    vector<Content*> simpleVector;
    vector<Content*>::iterator itcontents;
    for(itcontents = contents.begin(); itcontents != contents.end(); itcontents++){
        string contentType = ((*itcontents) -> getID()).substr(0, 1);
        if(contentType == "P"){
            simpleVector.push_back(*itcontents);
        }else{
            Serie* series = static_cast<Serie*>(&*(*itcontents));
            vector<vector<Episode*> > seriesEpisodes = series -> getEpisodes();
            vector<vector<Episode*> >::iterator itSeasons;
            vector<Episode*>::iterator itEpisodes;
            for(itSeasons = seriesEpisodes.begin(); itSeasons != seriesEpisodes.end(); itSeasons++){
                for(itEpisodes = (*itSeasons).begin(); itEpisodes != (*itSeasons).end(); itEpisodes++){
                    simpleVector.push_back(*itEpisodes);
                }
            }
        }
    }
    return simpleVector;
}