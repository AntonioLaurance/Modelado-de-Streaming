#include "video.h"

Video::Video(long unsigned int ID, string name, Time duration, char genre, int status)
{
	this -> ID = ID;
	this -> name = name;
	this -> duration = duration;	
	this -> genre = genre;
	this -> status = status;
}

Video::Video(long unsigned int ID, string name, Time duration, string genre, int status)
{
	this -> ID = ID;
	this -> name = name;
	this -> duration = duration;
	this -> genre = genre;

	if(genre == "Drama" || genre == "drama" || genre == "D" || genre == "d")
		this -> genre = 'D';
	else if(genre == "Acción" || genre == "Accion" || genre == "acción" || genre == "accion" || genre == "A" || genre = "a")
		this -> genre = 'A';
	else if(genre == "Misterio" || genre == "misterio" || genre == "M" || genre == "m")
		this -> genre = 'M';
	else
		this -> genre = 'O';	// Other 

	this -> status = status;	
}

Video::~Video()
{

}

long unsigned int Video::getID()
{
	return ID;
}

string Video::getName()
{
	return name;
}

Time Video::getDuration()
{
	return duration;
}

char Video::getGenre()
{
	return genre;
}

short float Video::getStatus()
{
	return status;
}

void Video::setID(long unsigned int ID)
{
	this -> ID = ID;
}

void Video::setName(string name)
{
	this -> name = name;
}

void Video::setDuration(Time duration)
{
	this -> duration = duration;
}

void Video::setGenre(char genre)
{
	this -> genre = genre;
}

void Video::setGenre(string genre)
{
	if(genre == "Drama" || genre == "drama" || genre == "D" || genre == "d")
		this -> genre = 'D';
	else if(genre == "Acción" || genre == "Accion" || genre == "acción" || genre == "accion" || genre == "A" || genre = "a")
		this -> genre = 'A';
	else if(genre == "Misterio" || genre == "misterio" || genre == "M" || genre == "m")
		this -> genre = 'M';
	else
		this -> genre = 'O';  // Other 
}

void Video::setStatus(short float status)
{
	this -> status = status;
}

string Video::toString()
{

}

