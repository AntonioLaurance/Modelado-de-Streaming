#ifndef __EPISODE
#define __EPISODE

#pragma once
#include <iostream>
#include <string>
#include "video.h"

class Episode: public Video
{
	private:
		string title;
		int season;

	public:
		// Constructors & Destructor 
		Episode();
		Episode(string ID, string name, int duration, string genre, float rating, int raters, string title, int season);
		~Episode();

		// Overriding methods
		string override toString();
		string override toCsvString();
};

#endif