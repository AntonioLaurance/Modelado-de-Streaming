#include "episode.h"

Episode::Episode() : Video(){
	title = "";
	season = 0;
}

Episode::Episode(string ID, string name, int duration, string genre, float rating, int raters, string title, int season) : Video(ID, name, duration, genre, rating, raters){
	this -> title = title;
	this -> season = season;
}

Episode::~Episode(){
	; // Null statement
}

string Episode::toString(){
	return "Todavía no implementado";
}