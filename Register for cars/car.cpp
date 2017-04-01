#include "car.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
Car::Car()
{

}
Car::Car(const char * _name, const char * _ID, unsigned _power)
{
	init(_name, _ID, _power);
}
void Car::init(const char * _name, const char * _ID, unsigned _power)
{
	strcpy_s(name, strlen(_name) + 1, _name);
	strcpy_s(ID, strlen(_ID) + 1, _ID);
	power = _power;
}
void Car::print(ofstream& file)const
{
	file << name << endl;
	file << ID << endl;
	file<< power << endl;
}
const char * Car::getCarName() const
{
	return name;
}
unsigned Car::getPower() const
{
	return power;
}