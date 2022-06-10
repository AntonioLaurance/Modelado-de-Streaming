#pragma once
#include <iostream>
#include <string>

using namespace std;

class Video
{
	private:
		long unsigned int ID;
		string name;
		short unsigned int duration;
		char genre;
		short float status;

	public:
		// Constructor & Destructor
		Video(long unsigned int ID, string name, Time duration, char genre, short float status = -1);
		Video(long unsigned int ID, string name, Time duration, string genre, short float status = -1);
		~Video();

		// Getters
		long unsigned int getID();
		string getName();
		Time getDuration();
		char getGenre();
		short float getStatus();

		// Setters 
		void setID(long unsigned int ID);
		void setName(string name);
		void setDuration(Time duration);
		void setGenre(char genre);
		void setGenre(string genre);
		void setStatus(short float status);

		// Other functions 
		virtual string toString();
};

