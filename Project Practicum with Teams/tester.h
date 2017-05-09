#pragma once
#ifndef __TESTER_H__
#include "employee.h"
#define __TESTER_H__
class Tester:public Employee
{
private:
	char nameOfTestedProject[150];
	char OS[60];
public:
	Tester();
	Tester(const char * _name, const char * _address, const char * _EGN, const char *_date, Employee * _boss = nullptr, const char * _position = "tester", const char * _nameOfTestedProject = "",const char * _OS="");
	void print() const;
	const char * getNameOfCurrentProject() const;
	void setNameOfCurrentProject(const char * newName);
	const char * getNameOfTestedProject() const;
	void setNameOfTestedProject(const char * newName);
	const char *getOS() const;
	void setOS(const char* _OS);
};
#endif