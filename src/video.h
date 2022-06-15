#ifndef __VIDEO
#define __VIDEO

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Video
{
	protected:
		string ID;
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
		virtual string toCsvString(int &indexNumber) = 0;
		Video* operator + (Video& otherVideo);
		void addReview(float review);
};

#endif