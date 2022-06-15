
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

            try
            {
                i = 1;
                string videoType = (videos[election - 1] -> getID()).substr(0, 1);
                if(videoType == "P")
                {
                    throw "This is not a series";
                }
                else
                {
                    int position = election;
                    Video* B_ptr = &(*videos[election - 1]);
                    Serie* derived_ptr1=static_cast<Serie*>(B_ptr);
                    cout << videos[election - 1] -> toReviewString();
                    cout << "\n>>> ";
                    cin >> election;

                    // Ask the user for the rating
                    cout << "\nRating (0 - 5): ";
                    cin >> grade;

                    vector<vector<Episode*> > episodes = derived_ptr1->getEpisodes();
                    vector<vector<Episode*> >::iterator itSeasons;
                    vector<Episode*>::iterator itEpisodes;

                    int counter = 0;
                    for(itSeasons = episodes.begin(); itSeasons != episodes.end(); itSeasons++){
                        for(itEpisodes = (*itSeasons).begin(); itEpisodes != (*itSeasons).end(); itEpisodes++){
                            counter += 1;
                            if(counter == election){
                                (*itEpisodes)->addReview(grade);
                                break;
                            }
                        }
                    }

                    videos.at(position - 1) = derived_ptr1;
                }
            }
            catch(...)
            {
                // Ask the user for the rating
                cout << "\nRating (0 - 5): ";
                cin >> grade;

                // Access to the selected item
                videos[election - 1] -> addReview(grade);
            }
            

        } else if(option == 2)
        {
            cout << c1 -> toString() << endl;
        } else if(option != 3)
        {
            cout << "Incorrect option." << endl;
        }
    }while(option != 3);
    
    c1 -> toCsv();
    free(c1);

    return 0;
}