#include "movie.h"

Movie::Movie(long unsigned int ID, string name, Time duration, char genre, short float status): Video(ID, name, duration, genre, status)
{

}

Movie::Movie(long unsigned int ID, string name, Time duration, string genre, short float status): Video(ID, name, duration, genre, status)
{

}

Movie::~Movie()
{

}

string Movie::toString()
{
    
}
