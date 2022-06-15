
/* ACTUALMENTE ESTE MAIN ES DE PRUEBA Y PARA PROBAR EL CODIGO Y SU FUNCIONAMIENTO */

#include "video.h"
#include "movie.h"
#include "episode.h"
#include "serie.h"
#include "catalogue.h"

int main()
{
    int option;
    Catalogue* c1 = new Catalogue("dataBase.csv");

    do{
        // Mostramos el menú de acciones para nuestros usuarios
        cout << "Options:" << endl;
        cout << "\t1) Review any video" << endl;
        cout << "\t2) Show catalogue" << endl;
        cout << "\t3) Exit" << endl;
        cout << "\n>>> ";

        try
        {
            cin >> option;

            /*
            if(typeof(option) == string || typeof(option == char *))
                throw "Dato no numérico introducido";
            */

        } catch(bad_cast){
            cout << "The input data is not a number" << endl;
            cin >> option;
        }
        
        cout << endl;

        if(option == 1)
        {
            vector<Video *> videos = c1 -> getVideos();
            vector<Video *>::iterator it;
            int i = 1, election;  // [Counter, election of video to rank]
            float grade;

            cout << "Choose the video that you want to review:" << endl;

            for(it = videos.begin(); it != videos.end(); ++it)
            {
                cout << "\t" << i << ") " << (*it) -> getName() << endl;
                i++;
            }

            cout << "\n>>> ";
            cin >> election;

            string videoType = (videos[election - 1] -> getID()).substr(0, 1);

            if(videoType == "P")
            {
                // Ask the user for the rating
                cout << "\nRating (0 - 5): ";
                cin >> grade;

                // Access to the selected item
                videos[election - 1] -> addReview(grade);
            }
            else
            {
                int position = election;
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

                // Ask the user for the rating
                cout << "\nRating (0 - 5): ";
                cin >> grade;

                int counter = 0;
                for(itSeason = seriesEpisodes.begin(); itSeason != seriesEpisodes.end(); itSeason++){
                    for(itEpisode = (*itSeason).begin(); itEpisode != (*itSeason).end(); itEpisode++){
                        counter += 1;
                        if(counter == election){
                            (*itEpisode)->addReview(grade);
                            break;
                        }
                    }
                }
                videos.at(position - 1) = series;
            }

        } 
        else if(option == 2)
        {
            cout << c1 -> toString() << endl;
        } 
        else if(option != 3)
        {
            cout << "Incorrect option." << endl;
        }
    }while(option != 3);
    
    c1 -> toCsv();
    free(c1);

    return 0;
}