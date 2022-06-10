#ifndef __VIDEO
#define __VIDEO

#pragma once
#include <iostream>
#include <string>

using namespace std;

<<<<<<< HEAD
struct ID{
	char type;
	int number;
	int season;     // If type = 'P' no prints 
	int episode;	// If type = 'P' no prints 
}

typedef struct ID ID;

class Video
{
	protected:
		ID identifier;
=======
class Video
{
	protected:
		string ID;
>>>>>>> refs/remotes/origin/main
		string name;
		int duration;
		string genre;
		float rating;
		int raters; 

	public:
		// Constructor & Destructor
		Video();
		Video(string ID, string name, int duration, string genre, float rating, int raters);
		~Video();

		// Getters
		string getID();
		string getName();
		int getDuration();
		string getGenre();
		float getRating();
		int getRaters();

		// Setters 
		void setID(string ID);
		void setName(string name);
		void setDuration(int duration);
		void setGenre(string genre);
		void setRating(float rating);
		void setRaters(int raters);

		// Other functions 
		virtual string toString() = 0;
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> refs/remotes/origin/main
