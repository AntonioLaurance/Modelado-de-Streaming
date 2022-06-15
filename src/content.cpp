#include "content.h"
#include "movie.h"

Content::Content()
{
	ID = "";
	name = "";
	duration = 0;	
	genre = "";
	rating = 0;
	raters = 0;
}

Content::Content(string ID, string name, int duration, string genre, float rating, int raters)
{
	this -> ID = ID;
	this -> name = name;
	this -> duration = duration;	
	this -> genre = genre;
	this -> rating = rating;
	this -> raters = raters;
}

Content::~Content(){
	ID.clear();
	name.clear();
	genre.clear();
}

string Content::getID()
{
	return ID;
}

string Content::getName()
{
	return name;
}

int Content::getDuration()
{
	return duration;
}

string Content::getGenre()
{
	return genre;
}

float Content::getRating(){
	return rating;
}

int Content::getRaters(){
	return raters;
}

void Content::setID(string ID)
{
	this -> ID = ID;
}

void Content::setName(string name)
{
	this -> name = name;
}

void Content::setDuration(int duration)
{
	this -> duration = duration;
}

void Content::setGenre(string genre)
{
	this -> genre = genre;
}

void Content::setRating(float rating){
	this -> rating = rating;
}

void Content::setRaters(int raters){
	this -> raters = raters;
}

string Content::toString(){
	return "string";
}

Content* Content::operator + (Content& otherContent){
	Content* res = new Movie();
	res->setRating(rating + otherContent.getRating());
	res->setDuration(duration + otherContent.getDuration());
	res->setRaters(raters + otherContent.getRaters());

	return res;
}

void Content::addReview(float review)
{
    // new_average = (x_i - old average)/total 
	raters++;
    rating += (float) (review - rating)/(raters);
}