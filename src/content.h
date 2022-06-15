#ifndef __CONTENT
#define __CONTENT

#pragma once
#include <iostream>
#include <string>

using namespace std;

class Content
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
		Content();
		Content(string ID, string name, int duration, string genre, float rating, int raters);
		~Content();

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
		Content* operator + (Content& otherContent);
		void addReview(float review);
};

#endif