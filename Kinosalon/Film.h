#pragma once
#ifndef __FILE_H__
#define __FILE_H__
#include "Hour.h"
#include "Show.h"
#include<vector>
using std::vector;
class Film
{protected:
	char nameOfFilm[150];
	vector<Show> showsOfFilm;
	public:
		Film();
		Film(const char * name);
		Film(const char * name, const  vector<Show>& init);
		const char * getNameOfFilm()const;
		void setNameOfFilm(const char * name);
		int getCountOfShows();

	

};
#endif


