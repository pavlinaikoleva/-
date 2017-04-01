#include<iostream>
#include <cstring>
#include "patient.h"
using std::cout;
using std::cin;
using std::endl;
Patient::Patient()
{
}
Patient::Patient(const char * _name, Date _date, unsigned _countVisits)
{
	init(_name, _date, _countVisits);
}
void Patient::init(const char * _name, Date _date, unsigned _countVisits)
{
	strcpy_s(name, strlen(_name) + 1, _name);
	dateOfBirth = _date;
	countVisits = _countVisits;
}
const char * Patient::getName() const
{
	return name;
}
Date Patient::getDateOfBirth() const
{
	return dateOfBirth;
}

unsigned Patient::getCountVisits() const
{
	return countVisits;
}
void Patient::print() const
{
	cout << "Patient " << name << "  ";
	dateOfBirth.print_date();
	cout << countVisits << endl;
}
void Patient::setName(const char * _newName)
{
	strcpy_s(name, strlen(_newName) + 1, _newName);
}
void Patient::setDate(Date _date)
{
	dateOfBirth = _date;
}
void Patient::setCountVisits(unsigned newCount)
{
	countVisits = newCount;
}