
/* ACTUALMENTE ESTE MAIN ES DE PRUEBA Y PARA PROBAR EL CODIGO Y SU FUNCIONAMIENTO */

#include "video.h"
#include "movie.h"
#include "episode.h"
#include "serie.h"
#include "catalogue.h"

int main()
{
    Movie* m1 = new Movie("P_00001", "El Lobo de Wallstreet", 120, "Acción", 4.5, 3242);

    Episode* e1 = new Episode("P_00001_001_00001", "Breaking Bad", 35, "Drama", 4.9, 12043, "La muerte de Jessee", 1);
    Episode* e2 = new Episode("P_00001_001_00002", "Breaking Bad", 45, "Drama", 3.8, 15039, "La llegada del mal", 1);
    Episode* e3 = new Episode("P_00001_002_00001", "Breaking Bad", 38, "Drama", 4.6, 15039, "La llegada del mal", 2);

    Catalogue* c1 = new Catalogue("dataBase.csv");


    cout << c1->toString() << endl;



    


    return 0;
}