#include <iostream>
#include <cstring>
#include "event.h"
using namespace std;
const char * Event::getName() const
{
	return name;
}
const char * Event::getPlace() const
{
	return place;
}
int Event::getMaxVisitors() const
{
	return maxVisitors;
}
void Event::print() const
{
	cout << "Information about Event  " << name << "   " << place << "   " << maxVisitors << "   " << date.day << "   " << date.month << "    " << date.year << endl;
}
Event::Event()
{
	init("\0", "\0", 100, 1, 1, 2018);
}
void Event::init(const char * _name, const char * _place, int _maxVisitors, int _day, int _month, int _year)
{
	strcpy(name, _name);
	strcpy(place, _place);
	maxVisitors = _maxVisitors;
	date.day = _day;
	date.month = _month;
	date.year = _year;
}
Event::Event(const char * _name, const char * _place, int _maxVisitors, int _day, int _month, int _year)
{
	init(_name, _place, _maxVisitors, _day, _month, _year);
}
