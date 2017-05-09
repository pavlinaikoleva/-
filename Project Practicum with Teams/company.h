#pragma once
#ifndef __COMPANY_H__
#define __COMPANY_H__
#include <vector>
#include "employee.h"
#include "Team.h"
class Company
{
private:
	char CEO[150];
	char nameOfCompany[150];
	char addressOfCompany[200];
	std::vector<Employee*> employees;
	std::vector<Team> teams;
public:
	//конструктори
	//има динамична памет в класа вектора е от указатели към служители, всеки от които е заделен в heap-а, значи трябва да осигурим фантастичната четворка
	Company();
	Company(const char * _CEO, const char *_nameOfCompany, const char * _addressOfCompany);
	//get методи
	const char * getCEO()const;
	const char *getNameOfCompany()const;
	const char *getAddressOfCompany()const;
	//set методи
	void setCEO(const char * _CEO);
	void setNameOfCompany(const char * _nameOfCompany);
	void setAddressOfCompany(const char * _address);
	void editEmployee(const char *_EGN);
	//print методи
	void printEmployeesOfCompany()const;
	void printInformationAboutCompany()const;
	void printEmployeesByPosition(const char* _position)const;
	void printEmployeesByTeams()const;
	//добавяне на работник
	void addEmployee(Employee* newEmployee);
	void addEmployee();
	//методи за работа с екипите
	void addNewTeamWithOutMembers(const char * nameOfNewTeam);
	void moveEmployeeFromOneTeamToAnother(const char *_EGN, const char * nameOfFutureTeam);
	void deleteTeam();
	//методи за търсене
	Employee * searchEmployee(const char * _EGN);
	//уволняване на работник или премахване на екип
	void fireEmployee(const char * _EGN);
	//деструктор
	~Company();
};
#endif