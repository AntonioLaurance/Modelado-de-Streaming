
/* ACTUALMENTE ESTE MAIN ES DE PRUEBA Y PARA PROBAR EL CODIGO Y SU FUNCIONAMIENTO */

#include "video.h"
#include "movie.h"
#include "episode.h"
#include "serie.h"
#include "catalogue.h"

int main()
{
    int option;

    // Movie* m1 = new Movie("P_00001", "El Lobo de Wallstreet", 120, "Acción", 4.5, 3242);

    // Episode* e1 = new Episode("P_00001_001_00001", "Breaking Bad", 35, "Drama", 4.9, 12043, "La muerte de Jessee", 1);
    // Episode* e2 = new Episode("P_00001_001_00002", "Breaking Bad", 45, "Drama", 3.8, 15039, "La llegada del mal", 1);
    // Episode* e3 = new Episode("P_00001_002_00001", "Breaking Bad", 38, "Drama", 4.6, 15039, "La llegada del mal", 2);

    Catalogue* c1 = new Catalogue("dataBase.csv");

    do{
        // Mostramos el menú de acciones para nuestros usuarios
        cout << "Options:" << endl;
        cout << "\t1) Review any video" << endl;
        cout << "\t2) Show catalogue" << endl;
        cout << "\t3) Exit" << endl;
        cout << "\n>>> ";

        cin >> option;
        cout << endl;

        if(option == 1)
        {
            vector<Video *> videos = c1 -> getVideos();
            vector<Video *>::iterator it;
            int i = 1, election;  // [Counter, election of video to rank]
            float grade;

            cout << "Chosse the video that you want to review:" << endl;

            for(it = videos.begin(); it != videos.end(); ++it)
            {
                cout << "\t" << i << ") " << (*it) -> getName() << endl;
                i++;
            }

            cout << "\n>>> ";
            cin >> election;

            // Ask the user for the rating
            cout << "\nRating (0 - 5): ";
            cin >> grade;

            // Access to the selected item
            videos[election - 1] -> addReview(grade);

        } else if(option == 2)
        {
            cout << c1 -> toString() << endl;
        }
    }while(option != 3);
    
    c1 -> toCsv();
    return 0;
}