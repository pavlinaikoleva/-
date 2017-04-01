#pragma once
#include "date.h"
#ifndef __EVENT_H__
#define __EVENT_H__
class Event
{
private:
	char name[100];
	char place[100];
	int maxVisitors;
	Date date;
public:
	Event();
	Event(const char * _name, const char * _place, int _maxVisitors, int _day, int _month, int _year);
	void init(const char * _name, const char * _place, int _maxVisitors, int _day, int _month, int _year);
	const char * getName() const;
	const char * getPlace() const;
	int getMaxVisitors() const;
	void print() const;
};

#endif
