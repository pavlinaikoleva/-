#include<iostream>
#include "employee.h"
#include<cstring>
using std::cout;
using std::endl;
Employee::Employee(){}
Employee::Employee(const char * _name, const char * _address, const char * _EGN, const char *_date, Employee * _boss)
{
	strcpy_s(name, strlen(_name) + 1, _name);
	strcpy_s(address, strlen(_address) + 1, _address);
	strcpy_s(EGN, strlen(_EGN) + 1, _EGN);
	date.init(_date);
	if(!_boss)
	{
		setBoss(this);
	}
	else { boss = _boss; }
}
const char * Employee::getName()const
{
	return name;
}
const char * Employee::getAddress() const
{
	return address;
}
const char * Employee::getEGN() const
{
	return EGN;
}
const Date& Employee::getDate() const
{
	return date;
}
const Employee* Employee::getBoss()const
{
	return boss;
}
const char* Employee::getPosition()const
{
	return position;
}
void Employee::setName(const char * _name)
{
	strcpy_s(name, strlen(_name) + 1, _name);
}
void Employee::setAddress(const char * _address)
{
	strcpy_s(address, strlen(_address) + 1, _address);
}
void Employee::setEGN(const char * _EGN)
{
	strcpy_s(EGN, strlen(_EGN) + 1, _EGN);
}
void Employee::setDate(const Date& _date)
{
	date = _date;
}
void Employee::setDate(const char* _date)
{
	date.init(_date);
}
void Employee::setBoss(Employee * _boss)
{
	boss = _boss;
}
void Employee::setPosition(const char * _position)
{
	strcpy_s(position, strlen(_position)+1, _position);
}
