#include "video.h"

Video::Video(){
	ID = "";
	name = "";
	duration = 0;	
	genre = "";
	rating = 0;
	raters = 0;
}

Video::Video(string ID, string name, int duration, string genre, float rating, int raters)
{
	this -> ID = ID;
	this -> name = name;
	this -> duration = duration;	
	this -> genre = genre;
	this -> rating = rating;
	this -> raters = raters;
}

Video::~Video(){
	; // Null statement
}

string Video::getID()
{
	return ID;
}

string Video::getName()
{
	return name;
}

int Video::getDuration()
{
	return duration;
}

string Video::getGenre()
{
	return genre;
}

float Video::getRating(){
	return rating;
}

int Video::getRaters(){
	return raters;
}

void Video::setID(string ID)
{
	this -> ID = ID;
}

void Video::setName(string name)
{
	this -> name = name;
}

void Video::setDuration(int duration)
{
	this -> duration = duration;
}

void Video::setGenre(string genre)
{
	this -> genre = genre;
}

void Video::setRating(float rating){
	this -> rating = rating;
}

void Video::setRaters(int raters){
	this -> raters = raters;
}