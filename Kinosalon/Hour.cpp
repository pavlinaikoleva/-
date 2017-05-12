#include<iostream>
#include "Hour.h"
using std::cin;
using std::cout;
using std::endl;
Hour::Hour() {};
Hour::Hour(unsigned int _hour, unsigned int _minutes) :hour(_hour), minutes(_minutes){}
unsigned Hour::getHour()const
{
	return hour;
}
unsigned Hour::getMinutes()const
{
	return minutes;
}
void Hour::printHour()const
{
	cout << hour << ":" << minutes << endl;
}
void Hour::setHour(unsigned _hour)
{
	hour = _hour;
}
void Hour::setMinutes(unsigned _minutes)
{
	minutes = _minutes;
}