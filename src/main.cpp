
/* ACTUALMENTE ESTE MAIN ES DE PRUEBA Y PARA PROBAR EL CODIGO Y SU FUNCIONAMIENTO */
#include <ctype.h>
#include "video.h"
#include "movie.h"
#include "episode.h"
#include "serie.h"
#include "catalogue.h"

bool isnumber(string str){
    bool res = true;
    string::iterator it;
    for(it = str.begin(); it != str.end(); it++){
        if(*it == '.'){
            continue;
        }
        res = res && isdigit(*it);
        if(!res){
            break;
        }
    }
    return res;
}

int string2int(string someValue, int lowerLim, int upperLim){
    int someValueInt;
    while(true){
        try
        {
            if(!isnumber(someValue))
            {
                throw "Dato no numérico introducido";
            }
            else
            {
                stringstream ss;
                ss << someValue;
                ss >> someValueInt;
                if(someValueInt > upperLim || someValueInt < lowerLim)
                {
                    throw "Dato numérico mayor o menor a los posibles introducido";
                }
                else
                {
                    break;
                }
            }
        }
        catch(...)
        {
            cout << "The input data is not a number or is out of bounds" << endl;
            cout << "\n>>> ";
            someValue.clear();
        }
        cin >> someValue;
    }
    return someValueInt;
}

float string2float(string someValue, float lowerLim, float upperLim){
    float someValueFloat;
    while(true){
        try
        {
            if(!isnumber(someValue))
            {
                throw "Dato no numérico introducido";
            }
            else
            {
                stringstream ss;
                ss << someValue;
                ss >> someValueFloat;
                if(someValueFloat > upperLim || someValueFloat < lowerLim)
                {
                    throw "Dato numérico mayor o menor a los posibles introducido";
                }
                else
                {
                    break;
                }
            }
        }
        catch(...)
        {
            cout << "The input data is not a number or is out of bounds" << endl;
            cout << "\n>>> ";
            someValue.clear();
        }
        cin >> someValue;
    }
    return someValueFloat;
}

int main()
{
    Catalogue* c1 = new Catalogue("dataBase.csv");

    do{
        string option;
        int optionNum;
        stringstream ss;
        
        // Mostramos el menú de acciones para nuestros usuarios
        cout << "Options:" << endl;
        cout << "\t1) Rate any video" << endl;
        cout << "\t2) Show catalogue" << endl;
        cout << "\t3) Show movie or episode with a specific rating" << endl;
        cout << "\t4) Show movie or episode with a specific genre" << endl;
        cout << "\t5) Show the episodes of a specific series with a specific rating" << endl;
        cout << "\t6) Show the movies with a specific rating" << endl;
        cout << "\t7) Show movie or episode with a specific rating" << endl;

        cout << "\t8) Exit" << endl;
        cout << "\n>>> ";

        cin >> option;

        try
        {

            if(!isnumber(option))
            {
                throw "Dato no numérico introducido";
            }
            else
            {
                ss << option;
                ss >> optionNum;
            }
        
        } 
        catch(...)
        {
            cout << "The input data is not a number" << endl;
            continue;
        }
        
        cout << endl;

        if(optionNum == 1)
        {
            vector<Video *> videos = c1 -> getVideos();
            vector<Video *>::iterator it;
            int i = 1, electionNum, gradeNum;  // [Counter, election of video to rank]
            string grade;
            string election;

            cout << "Choose the video that you want to review:" << endl;

            for(it = videos.begin(); it != videos.end(); ++it)
            {
                cout << "\t" << i << ") " << (*it) -> getName() << endl;
                i++;
            }

            cout << "\n>>> ";
            cin >> election;

            electionNum = string2int(election, 1, i);

            string videoType = (videos[electionNum - 1] -> getID()).substr(0, 1);

            if(videoType == "P")
            {
                // Ask the user for the rating
                cout << "\nRating (1 - 5): ";
                cin >> grade;

                gradeNum = string2float(grade, 1.0f, 5.0f);

                // Access to the selected item
                videos[electionNum - 1] -> addReview(gradeNum);
            }
            else
            {
                int position = electionNum;
                Serie* series = static_cast<Serie*>(&(*videos[position - 1]));

                vector<vector<Episode*> > seriesEpisodes = series -> getEpisodes();

                int index = 1;
                vector<vector<Episode*> >::iterator itSeason;
                vector<Episode*>::iterator itEpisode;

                for(itSeason = seriesEpisodes.begin(); itSeason != seriesEpisodes.end(); itSeason++){
                    for(itEpisode = (*itSeason).begin(); itEpisode != (*itSeason).end(); itEpisode++){
                        cout << "\t" <<index << ") " << (*itEpisode)->getTitle() << endl;
                        index += 1;
                    }
                }
                
                cout << "\n>>> ";
                cin >> election;

                electionNum = string2int(election, 1, index);

                // Ask the user for the rating
                cout << "\nRating (1 - 5): ";
                cin >> grade;

                gradeNum = string2float(grade, 1.0f, 5.0f);

                int counter = 0;
                for(itSeason = seriesEpisodes.begin(); itSeason != seriesEpisodes.end(); itSeason++){
                    for(itEpisode = (*itSeason).begin(); itEpisode != (*itSeason).end(); itEpisode++){
                        counter += 1;
                        if(counter == electionNum){
                            (*itEpisode)->addReview(gradeNum);
                            break;
                        }
                    }
                }
                videos.at(position - 1) = series;
            }

        } 
        else if(optionNum == 2)
        {
            cout << c1 -> toString() << endl;
        }
        else if (optionNum == 3)
        {
            ;
        }
        else if (optionNum == 4)
        {
            ;
        }
        else if (optionNum == 5)
        {
            ;
        }
        else if (optionNum == 6)
        {
            ;
        }
        else if (optionNum == 7)
        {
            ;
        }
        else if(optionNum == 8)
        {
            break;
        } 
        else if(optionNum != 8)
        {
            cout << "Incorrect option." << endl;
        }
    }while(true);
    
    c1 -> toCsv();
    free(c1);

    return 0;
}