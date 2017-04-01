#include "holder.h"

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
Holder::Holder()
{

}
void Holder::init(const char* _name, const char * _ID, unsigned _regNUM,Car a)
{
	strcpy_s(name, strlen(_name) + 1, _name);
	strcpy_s(ID, strlen(_ID) + 1, _ID);
	regNUM = _regNUM;
	hisCar = a;
}
const char * Holder::getID() const
{
	return ID;
}
Holder::Holder(const char* _name, const char * _ID, unsigned _redNUM,Car a)
{
	init(_name, _ID, _redNUM,a);
}
void Holder::print(ofstream& file) const
{
	file << name << endl;
	file << ID << endl;
	file << regNUM << endl;
	hisCar.print(file);
}
const char * Holder::getCarName() const
{
	return hisCar.getCarName();
}
unsigned Holder::getCarPower() const
{
	return hisCar.getPower();
}
