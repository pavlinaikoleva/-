#pragma once
#ifndef __COMPANY_H__
#define __COMPANY_H__
#include <vector>
#include "employee.h"
class Company
{
private:
	char CEO[150];
	char nameOfCompany[150];
	char addressOfCompany[200];
	std::vector<Employee*> employees;
public:
	//има динамична памет в класа вектора е от указатели към служители, всеки от които е заделен в heap-а, значи тр€бва да осигурим фантастичната четворка
	Company();
	Company(const char * _CEO, const char *_nameOfCompany, const char * _addressOfCompany);
	const char * getCEO()const;
	const char *getNameOfCompany()const;
	const char *getAddressOfCompany()const;
	void setCEO(const char * _CEO);
	void setNameOfCompany(const char * _nameOfCompany);
	void setAddressOfCompany(const char * _address);
	void printEmployeesOfCompany()const;
	void printInformationAboutCompany()const;
	void addEmployee(Employee* newEmployee);
	void addEmployee();
	Employee * searchEmployee(const char * _EGN);
	void fireEmployee(const char * _EGN);
	void printEmployeesByPosition(const char* _position);
	void editEmployee(const char *_EGN);
	~Company();
};
#endif