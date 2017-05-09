#include<iostream>
#include <cstring>
#include "company.h"
#include "junior.h"
#include "tester.h"
#include "master.h"
using std::cin;
using std::cout;
using std::endl;
Company::Company() {}
Company::Company(const char * _CEO, const char *_nameOfCompany, const char * _addressOfCompany)
{
	(*this).setCEO(_CEO);
	(*this).setNameOfCompany(_nameOfCompany);
	(*this).setAddressOfCompany(_addressOfCompany);
}
const char * Company::getCEO()const
{
	return CEO;
}
const char *Company::getNameOfCompany()const
{
	return nameOfCompany;
}
const char *Company::getAddressOfCompany()const
{
	return addressOfCompany;
}
void Company::printInformationAboutCompany()const
{
	cout << "CEO: " << CEO << " Name: " << nameOfCompany << " ADDRESS: " << addressOfCompany << endl;
}
void Company::printEmployeesOfCompany()const
{
	size_t cntEmployees = employees.size();
	for (size_t i = 0;i < cntEmployees;i++)
	{
		employees[i]->print();
	}
}
void Company::setCEO(const char * _CEO)
{
	strcpy_s(CEO, strlen(CEO) + 1,_CEO);
}
void Company::setNameOfCompany(const char * _nameOfCompany)
{
	strcpy_s(nameOfCompany, strlen(_nameOfCompany) + 1, _nameOfCompany);
}
void Company::setAddressOfCompany(const char * _address)
{
	strcpy_s(addressOfCompany, strlen(_address) + 1, _address);
}
void Company::addEmployee(Employee* newEmployee)
{
	employees.push_back(newEmployee);
}
void Company::addEmployee()
{
	char key;
	cout << "What type of employee you want to add, for junior programmer press 'j', for junior tester press 't', for master programmer press 'm'" << endl;
	cin >> key;
	char _name[150];
	char _address[200];
	char _EGN[12];
	char _date[12];
	char nameOfBoss[150];
	char _nameOfCurrentProject[150];
	char _nameOfTestedProject[150];
	char _OS[60];
	cin.ignore();
	switch (key)
	{
	case 'j':
	{//уреди проблема със cin.getline къде ще поставиш ignore()
		cout << "Enter information about new Junior Programmer" << endl;
		cout << "Name: " << endl;
		cin.getline(_name, 150);
		cout << "Address: " << endl;
		cin.getline(_address, 200);
		cout << "EGN: " << endl;
		cin.getline(_EGN, 12);
		cout << "Date on which he/she was hired: " << endl;
		cin.getline(_date, 12);
		cout << "His/her boss is: " << endl;
		cin.getline(nameOfBoss, 150);
		cout << "Name of the project on which he/she is working at the moment: " << endl;
		cin.getline(_nameOfCurrentProject, 150);
		size_t cntemployees = employees.size();
		Employee* pBoss = nullptr;
		bool flag = true;
		for (size_t i = 0;i < cntemployees&&flag;i++)
		{
			if (!(strcmp(employees[i]->getName(), nameOfBoss)))
			{
				flag = false;
				pBoss = employees[i];
			}
		}
		if (pBoss)
		{
			employees.push_back(new Junior(_name, _address, _EGN, _date, pBoss, "junior programmer", _nameOfCurrentProject));
		}
		else
		{
			pBoss = new Junior(_name, _address, _EGN, _date, nullptr, "junior programmer", _nameOfCurrentProject);
			pBoss->setBoss(pBoss);
			employees.push_back(pBoss);
		}
		break;}
	case 't': 
	{cout << "Enter information about new Junior Tester" << endl;
	cout << "Name: " << endl;
	cin.getline(_name, 150);
	cout << "Address: " << endl;
	cin.getline(_address, 200);
	cout << "EGN: " << endl;
	cin.getline(_EGN, 12);
	cout << "Date on which he/she was hired: " << endl;
	cin.getline(_date, 12);
	cout << "His/her boss is: " << endl;
	cin.getline(nameOfBoss, 150);
	cout << "Name of the project which he/she is testing at the moment: " << endl;
	cin.getline(_nameOfTestedProject, 150);
	cout << "Name of the OS on which the project is tested: " << endl;
	cin.getline(_OS, 60);
	size_t cntemployees = employees.size();
	Employee* pBoss = nullptr;
	bool flag = true;
	for (size_t i = 0;i < cntemployees&&flag;i++)
	{
		if (!(strcmp(employees[i]->getName(), nameOfBoss)))
		{
			flag = false;
			pBoss = employees[i];
		}
	}
	if (pBoss)
	{
		employees.push_back(new Tester(_name, _address, _EGN, _date, pBoss, "junior tested",_nameOfTestedProject,_OS));
	}
	else
	{
		pBoss = new Tester(_name, _address, _EGN, _date, nullptr, "junior tester", _nameOfTestedProject,_OS);
		pBoss->setBoss(pBoss);
		employees.push_back(pBoss);
	}
		break;
	}
	case 'm':
	{cout << "Enter information about new Master Programmer" << endl;
	cout << "Name: " << endl;
	cin.getline(_name, 150);
	cout << "Address: " << endl;
	cin.getline(_address, 200);
	cout << "EGN: " << endl;
	cin.getline(_EGN, 12);
	cout << "Date on which he/she was hired: " << endl;
	cin.getline(_date, 12);
	cout << "His/her boss is: " << endl;
	cin.getline(nameOfBoss, 150);
	cout << "Name of the project on which he/she is working at the moment: " << endl;
	cin.getline(_nameOfCurrentProject, 150);
	cout << "Name of the project which he/she is testing at the moment: " << endl;
	cin.getline(_nameOfTestedProject, 150);
	cout << "Name of the OS on which the project is tested: " << endl;
	cin.getline(_OS, 60);
	size_t cntemployees = employees.size();
	Employee* pBoss = nullptr;
	bool flag = true;
	for (size_t i = 0;i < cntemployees&&flag;i++)
	{
		if (!(strcmp(employees[i]->getName(), nameOfBoss)))
		{
			flag = false;
			pBoss = employees[i];
		}
	}
	if (pBoss)
	{
		employees.push_back(new Master(_name, _address, _EGN, _date, pBoss, "master programmer",_nameOfCurrentProject, _nameOfTestedProject, _OS));
	}
	else
	{
		pBoss = new Master(_name, _address, _EGN, _date, nullptr, "master programmer",_nameOfCurrentProject, _nameOfTestedProject, _OS);
		pBoss->setBoss(pBoss);
		employees.push_back(pBoss);
	}
	break;
	}
	default: {cout << "There isn't such position in this company" << endl;break;}
	}
}
Employee * Company::searchEmployee(const char * _EGN)
{
	size_t cntEmployees = employees.size();
	for (size_t i = 0;i < cntEmployees;i++)
	{
		if (!strcmp(employees[i]->getEGN(), _EGN))
		{
			employees[i]->print();
			return employees[i];
		}
	}
	return nullptr;
}
void Company::fireEmployee(const char * EGN)
{
	size_t cntEmployees = employees.size();
	Employee* employeeToRemove;
	bool flag = true;
	for (size_t i = 0;i < cntEmployees&&flag;i++)
	{
		if (!strcmp(employees[i]->getEGN(), EGN))
		{
			flag = false;
			employeeToRemove = employees[i];
			for (size_t j = 0;j < i;j++)
			{
				if (employees[j]->getBoss() == employeeToRemove)
				{
					employees[j]->setBoss(employees[j]);
				}
			}
			for (size_t j = i+1;j < cntEmployees;j++)
			{
				if (employees[j]->getBoss() == employeeToRemove)
				{
					employees[j]->setBoss(employees[j]);
				}
			}
			delete employeeToRemove;
			employees.erase(employees.begin() + i);
		}
	}
}
void Company::printEmployeesByPosition(const char* _position)
{
	size_t cntEmployees = employees.size();
	for (size_t i = 0;i < cntEmployees;i++)
	{
		if (!strcmp(employees[i]->getPosition(), _position))
		{
			employees[i]->print();
		}
	}
}
void Company::editEmployee(const char *EGN)
{
	size_t cntEmployees = employees.size();
	bool flag = true;
	Employee * pBoss = nullptr;
	char _name[150];
	char _address[200];
	char _date[12];
	char nameOfBoss[150];
	char _nameOfCurrentProject[150];
	char _nameOfTestedProject[150];
	char _OS[60];
	for (size_t i = 0;i < cntEmployees&&flag;i++)
	{
		if (!strcmp(employees[i]->getEGN(), EGN))
		{
			flag = false;
			cout << "what do you want to edit:" << endl;
			cout << "Name: " << endl;
			cin.getline(_name, 150);
			cout << "Address: " << endl;
			cin.getline(_address, 200);
			cout << "Date on which he/she was hired: " << endl;
			cin.getline(_date, 12);
			cout << "His/her boss is: " << endl;
			cin.getline(nameOfBoss, 150);
			char key = employees[i]->getPosition()[0];
			employees[i]->setName(_name);
			employees[i]->setAddress(_address);
			employees[i]->setDate(_date);
			bool flag2=true;
			for (size_t j = 0;j < cntEmployees&&flag2;j++)
			{
				if (!strcmp(employees[j]->getName(), nameOfBoss))
				{
					flag2 = false;
					pBoss = employees[j];
				}
			}
			employees[i]->setBoss(pBoss);
			switch (key)
			{
			case 'm':
			{
			cout << "Name of the project on which he/she is working at the moment: " << endl;
			cin.getline(_nameOfCurrentProject, 150);
			cout << "Name of the project which he/she is testing at the moment: " << endl;
			cin.getline(_nameOfTestedProject, 150);
			cout << "Name of the OS on which the project is tested: " << endl;
			cin.getline(_OS, 60);
			employees[i]->setNameOfCurrentProject(_nameOfCurrentProject);
			employees[i]->setNameOfTestedProject(_nameOfTestedProject);
			employees[i]->setOS(_OS);

				break;
			}
			case 'j':
			{cout << "Name of the project on which he/she is working at the moment: " << endl;
			cin.getline(_nameOfCurrentProject, 150);
			employees[i]->setNameOfCurrentProject(_nameOfCurrentProject);
				break;
			}
			case 't':
			{cout << "Name of the project which he/she is testing at the moment: " << endl;
			cin.getline(_nameOfTestedProject, 150);
			cout << "Name of the OS on which the project is tested: " << endl;
			cin.getline(_OS, 60);
			employees[i]->setNameOfTestedProject(_nameOfTestedProject);
			employees[i]->setOS(_OS);
				break;
			}
			}
		}
	}
}
Company::~Company()
{size_t cntEmployees=employees.size();
for (size_t i = 0;i < cntEmployees;i++)
{
	delete employees[i];
}
}
