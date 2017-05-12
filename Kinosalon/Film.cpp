#include<cstring>
#include<iostream>
#include "Film.h"
using std::cin;
using std::cout;
using std::endl;
Film::Film(){}
Film::Film(const char * name)
{
	strcpy_s(nameOfFilm, strlen(name) + 1, name);
}
Film::Film(const char * name, const  vector<Show>& init)
{
	strcpy_s(nameOfFilm, strlen(name) + 1, name);
	showsOfFilm = init;
}
const char * Film::getNameOfFilm()const
{
	return nameOfFilm;
}
void Film::setNameOfFilm(const char * name)
{
	strcpy_s(nameOfFilm, strlen(name) + 1, name);
}
int Film::getCountOfShows()
{
	return showsOfFilm.size();
}