#include "video.h"

class Movie: public Video
{
    public:
        // Constructors & Destructor 
        Movie(long unsigned int ID, string name, Time duration, char genre, short float status = -1);
	Movie(long unsigned int ID, string name, Time duration, string genre, short float status = -1);
        ~Movie();

        // Overriding method
        string toString();     
};

