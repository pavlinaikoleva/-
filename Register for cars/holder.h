#pragma once
#include "car.h"
#include <fstream>
using std::ofstream;
#ifndef __OWN_H__
#define __OWN_H__
class Holder
{
private:
	char name[23];
	char ID[30];
	unsigned regNUM;
	Car hisCar;
public:
	Holder();
	void init(const char* _name, const char * _ID, unsigned _regNUM,Car a);
	Holder(const char* _name, const char * _ID, unsigned _redNUM,Car a);
	void print(ofstream& file) const;
	const char * getID() const;
	const char * getCarName() const;
	unsigned getCarPower() const;
};
#endif 

