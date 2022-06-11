
/* ACTUALMENTE ESTE MAIN ES DE PRUEBA Y PARA PROBAR EL CODIGO Y SU FUNCIONAMIENTO */

#include "video.h"
#include "movie.h"
#include "episode.h"

int main()
{
    Movie* m1 = new Movie("P_00001", "El Lobo de Wallstreet", 120, "Acción", 4.5, 3242);

    Episode* e1 = new Episode("P_00001_001_00001", "Breaking Bad", 35, "Drama", 4.9, 12043, "La muerte de Jessee", 1);

    cout << m1->toString() << endl << endl;


    cout << e1 -> toString() << endl << endl;




    return 0;
}