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
void Junior::save(std::ostream& out)const
{
	char bufM[3];
	bufM[0] = date.get_month() / 10 + '0';
	bufM[1] = date.get_month() % 10 + '0';
	bufM[2] = '\0';
	char bufD[3];
	bufD[0] = date.get_day() / 10 + '0';
	bufD[1] = date.get_day() % 10 + '0';
	bufD[2] = '\0';
	/*if (date.get_month() >= 10)
	{
		bufM[0] = '1';
		switch (date.get_month())
		{
		case'10': {bufM[1] = '0';break;}
		case'11': {bufM[1] = '1';break;}
		case'12': {bufM[2] = '2';break;}
		}
	}
	else {
		bufM[0] = '0';
		bufM[1] = date.get_month() + '0';
	}*/

	out << "j "<<endl
		<< name << endl
		<< address << endl
		<< EGN << endl
		<< bufD << "."
		<< bufM<<"."
		<< date.get_year() << endl
		<< (*boss).getName() << endl
		<< position << endl
		<< nameOfCurrentProject << endl;

}