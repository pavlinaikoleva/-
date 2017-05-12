#pragma once
#ifndef __SHOW_H_
#include "Hour.h"
#define __SHOW_H_
class Show:public Hour
{
protected:
	unsigned numberOfRoom;
	unsigned int dayOfProjection;
	unsigned int countSeats;
	unsigned int countFreeSeats;
public:
	Show();
	Show(unsigned int _hour, unsigned int _minutes, unsigned int _dayOfProjection,unsigned _room, unsigned _cntSeats = 40,unsigned _cntFreeSeats=40);
	unsigned getDayOfProjection()const;
	unsigned getCountSeats()const;
	unsigned getCountFreeSeats()const;
	unsigned getNumberOfRoom()const;
	void setCountFreeSeats(unsigned _cnt);
	void setCountSeats(unsigned _cnt);
	void setDayOfProjection(unsigned int _day);
	void setNumberOfRoom(unsigned _room);
	void print()const;

};
#endif // !__Projection_h_
