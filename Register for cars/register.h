#pragma once
#include<fstream>
using std::ofstream;
#include "car.h"
#include "holder.h"
#ifndef __REGISTER_H__
#define __REGISTER_H__
class Register
{
private:
	Holder * reg;
	size_t size;
public:
	Register();
	Register(size_t n);
	Register(const Register& other);
	void addOwner();
	void print(ofstream& file) const;
	Register& operator=(const Register & other);
	void mostCommonCar(ofstream& file);
	double averagePowerOfAllCars();
	size_t getSize() const;
	Holder * getReg();
};
#endif