
/* ACTUALMENTE ESTE MAIN ES DE PRUEBA Y PARA PROBAR EL CODIGO Y SU FUNCIONAMIENTO */

#include "video.h"
#include "movie.h"
#include "episode.h"
#include "serie.h"

int main()
{
    Movie* m1 = new Movie("P_00001", "El Lobo de Wallstreet", 120, "Acción", 4.5, 3242);

    Episode* e1 = new Episode("P_00001_001_00001", "Breaking Bad", 35, "Drama", 4.9, 12043, "La muerte de Jessee", 1);
    Episode* e2 = new Episode("P_00001_001_00002", "Breaking Bad", 45, "Drama", 3.8, 15039, "La llegada del mal", 1);
    Episode* e3 = new Episode("P_00001_002_00001", "Breaking Bad", 38, "Drama", 4.6, 15039, "La llegada del mal", 2);

    vector<vector<Episode*> > episodes;

    episodes.push_back({e1, e2});
    episodes.push_back({e3});

    Serie* s1 = new Serie(episodes, 2);

    cout << s1 -> toString() << endl << endl;
    cout << m1 -> toString() << endl << endl;
    cout << e1 -> toString() << endl << endl;

    cout << "Promedio de ratings: " << (*m1 + *e1)->getRating() / 2 << endl;

    return 0;
}
