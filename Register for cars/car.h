#pragma once

#ifndef __CAR_H__
#include <fstream>
using std::ofstream;
#define __CAR_H__
class Car
{
private:
	char name[50];
	char ID[30];
	unsigned power;
public:
	Car();
	Car(const char * _name, const char * _ID, unsigned _power);
	void init(const char * _name, const char * _ID, unsigned _power);
	void print(ofstream& file)const;
	const char * getCarName() const;
	unsigned getPower() const;

};
#endif
