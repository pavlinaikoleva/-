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
	//������������
	//��� ��������� ����� � ����� ������� � �� ��������� ��� ���������, ����� �� ����� � ������� � heap-�, ����� ������ �� �������� ������������� ��������
	Company();
	Company(const char * _CEO, const char *_nameOfCompany, const char * _addressOfCompany);
	//get ������
	const char * getCEO()const;
	const char *getNameOfCompany()const;
	const char *getAddressOfCompany()const;
	//set ������
	void setCEO(const char * _CEO);
	void setNameOfCompany(const char * _nameOfCompany);
	void setAddressOfCompany(const char * _address);
	void editEmployee(const char *_EGN);
	//print ������
	void printEmployeesOfCompany()const;
	void printInformationAboutCompany()const;
	void printEmployeesByPosition(const char* _position)const;
	void printEmployeesByTeams()const;
	//�������� �� ��������
	void addEmployee(Employee* newEmployee);
	void addEmployee();
	//������ �� ������ � �������
	void addNewTeamWithOutMembers(const char * nameOfNewTeam);
	void moveEmployeeFromOneTeamToAnother(const char *_EGN, const char * nameOfFutureTeam);
	void deleteTeam();
	//������ �� �������
	Employee * searchEmployee(const char * _EGN);
	//���������� �� �������� ��� ���������� �� ����
	void fireEmployee(const char * _EGN);
	//����������
	~Company();
};
#endif