#include<iostream>
#include "Show.h"
using std::cin;
using std::cout;
using std::endl;
Show::Show(){}
Show::Show(unsigned int _hour, unsigned int _minutes, unsigned int _dayOfProjection, unsigned _room,unsigned _cntSeats,unsigned _cntFreeSeats) :Hour(_hour, _minutes),dayOfProjection(_dayOfProjection)
{
	numberOfRoom = _room;
	countSeats = _cntSeats;
	countFreeSeats = _cntFreeSeats;
}
unsigned Show::getNumberOfRoom()const
{
	return numberOfRoom;
}
unsigned Show::getCountSeats()const
{
	return countSeats;
}
unsigned Show::getCountFreeSeats()const
{
	return countFreeSeats;
}
void Show::setCountFreeSeats(unsigned _cnt)
{
	countSeats = _cnt;
}
void Show::setCountSeats(unsigned _cnt)
{
	countFreeSeats = _cnt;
}
unsigned Show::getDayOfProjection()const
{
	return dayOfProjection;
}
void Show::setDayOfProjection(unsigned int _day)
{
	dayOfProjection = _day;
}
void Show::setNumberOfRoom(unsigned _room)
{
	numberOfRoom = _room;
}

void Show::print()const
{
	switch (dayOfProjection)
	{
	case '1': {cout << "Monday "; break; }
	case '2': {cout << "Tuesday "; break; }
	case '3': {cout << "Wednesday "; break; }
	case '4': {cout << "Thursday "; break; }
	case '5': {cout << "Friday "; break; }
	case '6': {cout << "Saturday "; break; }
	case '7': {cout << "Sunday "; break; }
	}
	Show::printHour();
}