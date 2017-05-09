#pragma once
#ifndef __MASTER_H__
#define __MASTER_H__
#include "employee.h"
class Master:public Employee
{
private:
	char nameOfCurrentProject[150];
	char nameOfTestedProject[150];
	char OS[60];
public:
	Master();
	Master(const char * _name, const char * _address, const char * _EGN, const char *_date, Employee * _boss = nullptr, const char * _position = "master programmer",const char* _nameOfCurrentProject="", const char * _nameOfTestedProject = "", const char * _OS = "");
	void print() const;
	const char * getNameOfCurrentProject() const;
	void setNameOfCurrentProject(const char * newName);
	const char * getNameOfTestedProject() const;
	void setNameOfTestedProject(const char * newName);
	const char *getOS() const;
	void setOS(const char* _OS);

};
#endif