#include "video.h"

class Episode: public Video
{
	private:
		string title;
		short unsigned int season;

	public:
		// Constructors & Destructor 
		Episode(long usigned int ID, string name, Time duration, char genre, string title, short unsigned int season, short float status = -1);
		Episode(long usigned int ID, string name, Time duration, string genre, string title, short unsigned int season, short float status = -1);
		~Episode();

		// Overriding method
		string toString();
};

