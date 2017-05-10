#pragma once
#ifndef __EMPLOYEE_H__
#define __EMPLOYEE_H__
#include "date.h"
#include <iostream>
#include <vector>
class Employee //ще бъде абстрактен клас,родител на класовете от различни позиции
{
protected:
	char name[150];
	char address[200];
	char EGN[12];
	Date date;
	Employee *boss;
	char position[50];
public:
	//констуктура по подразбиране върши работа
	Employee();
	virtual void print()const = 0;
	virtual const char * getNameOfCurrentProject() const = 0;
	virtual void setNameOfCurrentProject(const char * newName) = 0;
	virtual const char * getNameOfTestedProject() const = 0;
	virtual void setNameOfTestedProject(const char * newName) = 0;
	virtual const char *getOS() const = 0;
	virtual void setOS(const char* _OS) = 0;
	Employee(const char * _name, const char * _address, const char * _EGN, const char *_date, Employee * _boss = nullptr);
	const char * getName()const;
	const char * getAddress() const;
	const char * getEGN() const;
	const Date& getDate() const;
	const Employee* getBoss()const;
	const char* getPosition()const;
	void setName(const char * _name);
	void setAddress(const char * _address);
	void setEGN(const char * _EGN);
	void setDate(const Date& _date);
	void setDate(const char* _date);
	void setBoss(Employee * _boss);
	void setPosition(const char * _position);
	virtual void save(std::ostream& out)const = 0;
	friend std::ostream& operator << (std::ostream &, std::vector<Employee*>);
	//friend std::istream& operator >> (std::istream &, std::vector<Employee*>&);
};
#endif // !__EMPLOYEE_H__
