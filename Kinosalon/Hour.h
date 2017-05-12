#pragma once
#ifndef __HOUR_H__
#define __HOUR_H__
class Hour
{
protected:
	unsigned int hour;
	unsigned int minutes;
public:
	Hour();
	Hour(unsigned int _hour, unsigned int _minutes);
	unsigned getHour()const;
	unsigned getMinutes()const;
	void printHour()const;
	void setHour(unsigned _hour);
	void setMinutes(unsigned _minutes);
};
#endif // !__HOUR_H__
