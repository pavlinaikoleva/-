#include<iostream>
#include "junior.h"
#include <assert.h>
using std::cin;
using std::cout;
using std::endl;
Junior::Junior(){}
Junior::Junior(const char * _name, const char * _address, const char * _EGN, const char *_date, Employee * _boss, const char * _position,const char * _nameOfCurrentProject):Employee(_name,_address,_EGN,_date,_boss)
{
	this->setPosition(_position);
	this->setNameOfCurrentProject(_nameOfCurrentProject);
}
void Junior::print() const
{
	cout << "Information for Junior Programmer: "
		<< name << " "
		<< address << " "
		<< EGN << " "
		<< date.get_day()<< "."
		<< date.get_month() << "."
		<< date.get_year() << " "
		<< (*boss).getName() << " "
		<< position << " "
		<< nameOfCurrentProject << endl;
}
const char * Junior::getNameOfCurrentProject() const
{
	return nameOfCurrentProject;
}
void Junior::setNameOfCurrentProject(const char * newName)
{
	strcpy_s(nameOfCurrentProject, strlen(newName) + 1, newName);
}
const char * Junior::getNameOfTestedProject() const
{
	assert(false);
	return "false";
}
void Junior::setNameOfTestedProject(const char * newName)
{
	assert(false);
	return;
}
const char *Junior::getOS() const
{
	assert(false);
	return "false";
}
void Junior::setOS(const char* _OS)
{
	assert(false);
	return;
}