#ifndef __EPISODE
#define __EPISODE

#pragma once
#include <iostream>
#include <string>
#include "content.h"

class Episode: public Content
{
	private:
		string title;
		int season;

	public:
		// Constructors & Destructor 
		Episode();
		Episode(string ID, string name, int duration, string genre, float rating, int raters, string title, int season);
		~Episode();

		// getters
		string getTitle();

		// Overriding methods
		string toString();
		string toCsvString(int &indexNum);
};

#endif