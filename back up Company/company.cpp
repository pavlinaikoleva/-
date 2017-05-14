#include<iostream>
#include <cstring>
#include "company.h"
#include "junior.h"
#include "tester.h"
#include "master.h"
using std::cin;
using std::cout;
using std::endl;
//конструктори
Company::Company() {}
Company::Company(const char * _CEO, const char *_nameOfCompany, const char * _addressOfCompany)
{
	(*this).setCEO(_CEO);
	(*this).setNameOfCompany(_nameOfCompany);
	(*this).setAddressOfCompany(_addressOfCompany);
}
Company::Company(const Company & other)
{
	this->setNameOfCompany(other.nameOfCompany);
	this->setCEO(other.CEO);
	this->setAddressOfCompany(other.addressOfCompany);
	size_t cntOtherEmployees = other.employees.size();
	for (size_t i = 0;i < cntOtherEmployees;i++)
	{
		switch (other.employees[i]->getPosition()[0])
		{
		case 'j':
		{
			Employee* pBoss = nullptr;
			bool flag = true;
			for (size_t j = 0;j < employees.size() && flag;j++)
			{
				if (!(strcmp(employees[j]->getName(), other.employees[i]->getBoss()->getName())))
				{
					flag = false;
					pBoss = employees[j];
				}
			}
			if (pBoss)
			{
				employees.push_back(new Junior(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), pBoss, "junior programmer", other.employees[i]->getNameOfCurrentProject()));
			}
			else
			{
				pBoss = new Junior(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), nullptr, "junior programmer", other.employees[i]->getNameOfCurrentProject());
				pBoss->setBoss(pBoss);
				employees.push_back(pBoss);
			}
			size_t cntTeams = teams.size();
			bool addNewTeam = true;
			for (size_t p = 0;p < cntTeams&&addNewTeam;p++)
			{
				if (!strcmp(teams[p].getNameTeamProject(), other.employees[i]->getNameOfCurrentProject()))
				{
					teams[p].addMember(employees[employees.size() - 1]);
					addNewTeam = false;
				}
			}
			if (addNewTeam)
			{
				Team newTeam(employees[employees.size() - 1], other.employees[i]->getNameOfCurrentProject());
				newTeam.addMember(employees[employees.size() - 1]);
				teams.push_back(newTeam);
			}
			break;}
		case 't':
		{
			Employee* pBoss = nullptr;
			bool flag = true;
			for (size_t j = 0;j < employees.size() && flag;j++)
			{
				if (!(strcmp(employees[j]->getName(), other.employees[i]->getBoss()->getName())))
				{
					flag = false;
					pBoss = employees[j];
				}
			}
			if (pBoss)
			{
				employees.push_back(new Tester(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), pBoss, "tester", other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS()));
			}
			else
			{
				pBoss = new Tester(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), nullptr, "tester", other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS());
				pBoss->setBoss(pBoss);
				employees.push_back(pBoss);
			}
			size_t cntTeams = teams.size();
			bool addNewTeam = true;
			for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
			{
				if (!strcmp(teams[j].getNameTeamProject(), other.employees[i]->getNameOfTestedProject()))
				{
					teams[j].addMember(employees[employees.size() - 1]);
					addNewTeam = false;
				}
			}
			if (addNewTeam)
			{
				Team newTeam(employees[employees.size() - 1], other.employees[i]->getNameOfTestedProject());
				newTeam.addMember(employees[employees.size() - 1]);
				teams.push_back(newTeam);
			}
			break;
		}
		case 'm':
		{
			Employee* pBoss = nullptr;
			bool flag = true;
			for (size_t j = 0;j < employees.size() && flag;j++)
			{
				if (!(strcmp(employees[j]->getName(), other.employees[i]->getBoss()->getName())))
				{
					flag = false;
					pBoss = employees[j];
				}
			}
			if (pBoss)
			{
				employees.push_back(new Master(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(),pBoss, "master programmer", other.employees[i]->getNameOfCurrentProject(), other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS()));
			}
			else
			{
				pBoss = new Master(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), nullptr, "master programmer", other.employees[i]->getNameOfCurrentProject(), other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS());
				pBoss->setBoss(pBoss);
				employees.push_back(pBoss);
			}
			size_t cntTeams = teams.size();
			bool addNewTeam = true;
			for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
			{
				if (!strcmp(teams[j].getNameTeamProject(), other.employees[i]->getNameOfCurrentProject()))
				{
					teams[j].addMember(employees[employees.size() - 1]);
					addNewTeam = false;
				}
			}
			if (addNewTeam)
			{
				Team newTeam(employees[employees.size() - 1], other.employees[i]->getNameOfCurrentProject());
				newTeam.addMember(employees[employees.size() - 1]);
				teams.push_back(newTeam);
			}
			break;
		}
		}
	}
}
//get методи
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
//print методи
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

void Company::printEmployeesByPosition(const char* _position)const
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
void Company::printEmployeesByTeams()const
{
	size_t cntTeams = teams.size();
	for (size_t i = 0;i < cntTeams;i++)
	{
		teams[i].printMembersOfTeam();
		cout << endl;
	}
}
void Company::SaveCompanyOnFile(std::ofstream& out)
{
	out << nameOfCompany << endl;
	out << CEO << endl;
	out << addressOfCompany << endl;
	out << employees;
}
void Company::loadCompanyFromFile(std::ifstream& input)
{
	char  bufferNameCompany[150];
	char bufferNameCEO[150];
	char bufferAddress[200];
	input.getline(bufferNameCompany, 150);
	input.getline(bufferNameCEO, 150);
	input.getline(bufferAddress, 200);
	setNameOfCompany(bufferNameCompany);
	setCEO(bufferNameCEO);
	setAddressOfCompany(bufferAddress);
	int countEmployees;
	input >> countEmployees;
	for (int i = 0;i < countEmployees;i++)
	{
		loadEmployee(input);
	}
}
//set методи
void Company::setCEO(const char * _CEO)
{
	strcpy_s(CEO, strlen(_CEO) + 1,_CEO);
}

void Company::setNameOfCompany(const char * _nameOfCompany)
{
	strcpy_s(nameOfCompany, strlen(_nameOfCompany) + 1, _nameOfCompany);
}

void Company::setAddressOfCompany(const char * _address)
{
	strcpy_s(addressOfCompany, strlen(_address) + 1, _address);
}

void Company::loadEmployee(std::ifstream& input)
{
	char key;
	char _name[150];
	char _address[200];
	char _EGN[12];
	char _date[12];
	char nameOfBoss[150];
	char _nameOfCurrentProject[150];
	char _nameOfTestedProject[150];
	char bin[50];
	char _OS[60];
	size_t cntemployees = employees.size();
	do
	{
		input >> key;
		input.ignore();
		switch (key)
		{
		case 'j':
		{//уреди проблема със cin.getline къде ще поставиш ignore()
			input.getline(_name, 150);
			input.getline(_address, 200);
			input.getline(_EGN, 12);
			input.getline(_date, 12);
			input.getline(nameOfBoss, 150);
			input.getline(bin, 50);
			input.getline(_nameOfCurrentProject, 150);
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
			size_t cntTeams = teams.size();
			bool addNewTeam = true;
			for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
			{
				if (!strcmp(teams[j].getNameTeamProject(), _nameOfCurrentProject))
				{
					teams[j].addMember(employees[employees.size() - 1]);
					addNewTeam = false;
				}
			}
			if (addNewTeam)
			{
				Team newTeam(employees[employees.size() - 1], _nameOfCurrentProject);
				newTeam.addMember(employees[employees.size() - 1]);
				teams.push_back(newTeam);
			}
			break;}
		case 't':
		{
		input.getline(_name, 150);
		input.getline(_address, 200);
		input.getline(_EGN, 12);
		input.getline(_date, 12);
		input.getline(nameOfBoss, 150);
		input.getline(bin, 50);
		input.getline(_nameOfTestedProject, 150);
		input.getline(_OS, 60);
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
			employees.push_back(new Tester(_name, _address, _EGN, _date, pBoss, "tester", _nameOfTestedProject, _OS));
		}
		else
		{
			pBoss = new Tester(_name, _address, _EGN, _date, nullptr, "tester", _nameOfTestedProject, _OS);
			pBoss->setBoss(pBoss);
			employees.push_back(pBoss);
		}
		size_t cntTeams = teams.size();
		bool addNewTeam = true;
		for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
		{
			if (!strcmp(teams[j].getNameTeamProject(), _nameOfTestedProject))
			{
				teams[j].addMember(employees[employees.size() - 1]);
				addNewTeam = false;
			}
		}
		if (addNewTeam)
		{
			Team newTeam(employees[employees.size() - 1], _nameOfTestedProject);
			newTeam.addMember(employees[employees.size() - 1]);
			teams.push_back(newTeam);
		}
		break;
		}
		case 'm':
		{
		input.getline(_name, 150);
		input.getline(_address, 200);
		input.getline(_EGN, 12);
		input.getline(_date, 12);
		input.getline(nameOfBoss, 150);
		input.getline(bin, 50);
		input.getline(_nameOfCurrentProject, 150);
		input.getline(_nameOfTestedProject, 150);
		input.getline(_OS, 60);
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
			employees.push_back(new Master(_name, _address, _EGN, _date, pBoss, "master programmer", _nameOfCurrentProject, _nameOfTestedProject, _OS));
		}
		else
		{
			pBoss = new Master(_name, _address, _EGN, _date, nullptr, "master programmer", _nameOfCurrentProject, _nameOfTestedProject, _OS);
			pBoss->setBoss(pBoss);
			employees.push_back(pBoss);
		}
		size_t cntTeams = teams.size();
		bool addNewTeam = true;
		for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
		{
			if (!strcmp(teams[j].getNameTeamProject(), _nameOfCurrentProject))
			{
				teams[j].addMember(employees[employees.size() - 1]);
				addNewTeam = false;
			}
		}
		if (addNewTeam)
		{
			Team newTeam(employees[employees.size() - 1], _nameOfCurrentProject);
			newTeam.addMember(employees[employees.size() - 1]);
			teams.push_back(newTeam);
		}
		break;
		}
		default: {break;}
		}
	} while (key != 'm'&&key != 'j'&&key != 't');
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
			bool flag2 = true;
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
//методи за добавяне на служител (автоматично при добавянето му се определя и екипа, към който работи)
void Company::addEmployee(Employee* newEmployee)
{
	employees.push_back(newEmployee);
	size_t cntTeams = teams.size();
	bool addNewTeam = true;
	for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
	{
		if (!strcmp(teams[j].getNameTeamProject(), newEmployee->getNameOfCurrentProject()))
		{
			teams[j].addMember(employees[employees.size() - 1]);
			addNewTeam = false;
		}
	}
	if (addNewTeam)
	{
		Team newTeam(employees[employees.size() - 1], newEmployee->getNameOfCurrentProject());
		newTeam.addMember(employees[employees.size() - 1]);
		teams.push_back(newTeam);
	}
}

void Company::addEmployee()
{
	char key;
	cout << "What type of employee you want to add, for junior programmer press 'j', for junior tester press 't', for master programmer press 'm'" << endl;
	char _name[150];
	char _address[200];
	char _EGN[12];
	char _date[12];
	char nameOfBoss[150];
	char _nameOfCurrentProject[150];
	char _nameOfTestedProject[150];
	char _OS[60];
	size_t cntemployees = employees.size();
	do 
	{
		cin >> key;
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
			size_t cntTeams = teams.size();
			bool addNewTeam = true;
			for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
			{
				if (!strcmp(teams[j].getNameTeamProject(), _nameOfCurrentProject))
				{
					teams[j].addMember(employees[employees.size() - 1]);
					addNewTeam = false;
				}
			}
			if (addNewTeam)
			{
				Team newTeam(employees[employees.size() - 1], _nameOfCurrentProject);
				newTeam.addMember(employees[employees.size() - 1]);
				teams.push_back(newTeam);
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
			employees.push_back(new Tester(_name, _address, _EGN, _date, pBoss, "tester", _nameOfTestedProject, _OS));
		}
		else
		{
			pBoss = new Tester(_name, _address, _EGN, _date, nullptr, "tester", _nameOfTestedProject, _OS);
			pBoss->setBoss(pBoss);
			employees.push_back(pBoss);
		}
		size_t cntTeams = teams.size();
		bool addNewTeam = true;
		for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
		{
			if (!strcmp(teams[j].getNameTeamProject(), _nameOfTestedProject))
			{
				teams[j].addMember(employees[employees.size() - 1]);
				addNewTeam = false;
			}
		}
		if (addNewTeam)
		{
			Team newTeam(employees[employees.size() - 1], _nameOfTestedProject);
			newTeam.addMember(employees[employees.size() - 1]);
			teams.push_back(newTeam);
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
			employees.push_back(new Master(_name, _address, _EGN, _date, pBoss, "master programmer", _nameOfCurrentProject, _nameOfTestedProject, _OS));
		}
		else
		{
			pBoss = new Master(_name, _address, _EGN, _date, nullptr, "master programmer", _nameOfCurrentProject, _nameOfTestedProject, _OS);
			pBoss->setBoss(pBoss);
			employees.push_back(pBoss);
		}
		size_t cntTeams = teams.size();
		bool addNewTeam = true;
		for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
		{
			if (!strcmp(teams[j].getNameTeamProject(), _nameOfCurrentProject))
			{
				teams[j].addMember(employees[employees.size() - 1]);
				addNewTeam = false;
			}
		}
		if (addNewTeam)
		{
			Team newTeam(employees[employees.size() - 1], _nameOfCurrentProject);
			newTeam.addMember(employees[employees.size() - 1]);
			teams.push_back(newTeam);
		}
		break;
		}
		default: {cout << "There isn't such position in this company, please try again to choose position" << endl;break;}
		}
	}while (key != 'm'&&key != 'j'&&key != 't');
	//в този момент функцията задължително е добавила нов служител в employees остава да го зачислим към екип
}
//метод за търсене на работник
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
//метод за отстраняване на работник
//когато уволняваме служител трябва да се погрижим да го махнем и от екипа, в който се е намирал 
void Company::fireEmployee(const char * EGN)
{
	size_t cntEmployees = employees.size();
	size_t cntTeams = teams.size();
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
			switch (employeeToRemove->getPosition()[0])
			{
			case 'm': {
				for (size_t j = 0;j < cntTeams;j++)
			{
				if (!strcmp(teams[j].getNameTeamProject(), employeeToRemove->getNameOfCurrentProject()))
				{
					teams[j].removeMember(EGN);
				}
			}
				break;}
			case 't': {for (size_t j = 0;j < cntTeams;j++)
			{
				if (!strcmp(teams[j].getNameTeamProject(), employeeToRemove->getNameOfTestedProject()))
				{
					teams[j].removeMember(EGN);
				}
			}
				break;}
			case 'j': {for (size_t j = 0;j < cntTeams;j++)
			{
				if (!strcmp(teams[j].getNameTeamProject(), employeeToRemove->getNameOfCurrentProject()))
				{
					teams[j].removeMember(EGN);
				}
			}
					  break;}
			}
			delete employeeToRemove;
			employees.erase(employees.begin() + i);
		}
	}
}
//методи за работа с екипите
void Company::addNewTeamWithOutMembers(const char * nameOfNewTeam)
{
	Team newTeam(nameOfNewTeam);
	teams.push_back(newTeam);
}
void Company::deleteTeam()
{
	size_t cntTeams = teams.size();
	for (size_t i = 0;i < cntTeams;i++)
	{
		if (teams[i].getCountMembers() == 0)
		{
			teams.erase(teams.begin() + i);
		}
	}
}
void Company::moveEmployeeFromOneTeamToAnother(const char *_EGN, const char * nameOfFutureTeam)
{
	size_t cntEmployees = employees.size();
	size_t cntTeams = teams.size();
	bool flag = true;
	for (size_t i = 0;i < cntEmployees&&flag;i++)
	{
		if (!strcmp(employees[i]->getEGN(), _EGN))
		{
			flag = false;
			char buffer[150];
			switch (employees[i]->getPosition()[0])
			{
			case 'm': {
				strcpy_s(buffer, strlen(employees[i]->getNameOfCurrentProject()) + 1, employees[i]->getNameOfCurrentProject());
				employees[i]->setNameOfCurrentProject(buffer);
				employees[i]->setNameOfTestedProject(buffer);
				break;}
			case 'j': {strcpy_s(buffer, strlen(employees[i]->getNameOfCurrentProject()) + 1, employees[i]->getNameOfCurrentProject());
				employees[i]->setNameOfCurrentProject(buffer);
				break;}
			case 't': {strcpy_s(buffer, strlen(employees[i]->getNameOfTestedProject()) + 1, employees[i]->getNameOfTestedProject());
				employees[i]->setNameOfTestedProject(buffer);
				break;}
			}
			for (size_t j = 0;j < cntTeams;j++)
			{
			if (!strcmp(teams[j].getNameTeamProject(), buffer))
				{
					teams[j].removeMember(_EGN);
				}
			if (!strcmp(teams[j].getNameTeamProject(), nameOfFutureTeam))
			{
				teams[j].addMember(employees[i]);
			}
			}
		}
	}
}
Company& Company::operator = (const Company & other)
{
	if (this != &other)
	{
		size_t cntThisEmployees = employees.size();
		for (size_t i = 0;i < cntThisEmployees;i++)
		{
			delete	employees[i];
		}
		employees.clear();
		teams.clear();
		this->setNameOfCompany(other.nameOfCompany);
		this->setCEO(other.CEO);
		this->setAddressOfCompany(other.addressOfCompany);
		size_t cntOtherEmployees = other.employees.size();
		for (size_t i = 0;i < cntOtherEmployees;i++)
		{
			switch (other.employees[i]->getPosition()[0])
			{
			case 'j':
			{
				Employee* pBoss = nullptr;
				bool flag = true;
				for (size_t j = 0;j < employees.size() && flag;j++)
				{
					if (!(strcmp(employees[j]->getName(), other.employees[i]->getBoss()->getName())))
					{
						flag = false;
						pBoss = employees[j];
					}
				}
				if (pBoss)
				{
					employees.push_back(new Junior(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), pBoss, "junior programmer", other.employees[i]->getNameOfCurrentProject()));
				}
				else
				{
					pBoss = new Junior(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), nullptr, "junior programmer", other.employees[i]->getNameOfCurrentProject());
					pBoss->setBoss(pBoss);
					employees.push_back(pBoss);
				}
				size_t cntTeams = teams.size();
				bool addNewTeam = true;
				for (size_t p = 0;p < cntTeams&&addNewTeam;p++)
				{
					if (!strcmp(teams[p].getNameTeamProject(), other.employees[i]->getNameOfCurrentProject()))
					{
						teams[p].addMember(employees[employees.size() - 1]);
						addNewTeam = false;
					}
				}
				if (addNewTeam)
				{
					Team newTeam(employees[employees.size() - 1], other.employees[i]->getNameOfCurrentProject());
					newTeam.addMember(employees[employees.size() - 1]);
					teams.push_back(newTeam);
				}
				break;}
			case 't':
			{
				Employee* pBoss = nullptr;
				bool flag = true;
				for (size_t j = 0;j < employees.size() && flag;j++)
				{
					if (!(strcmp(employees[j]->getName(), other.employees[i]->getBoss()->getName())))
					{
						flag = false;
						pBoss = employees[j];
					}
				}
				if (pBoss)
				{
					employees.push_back(new Tester(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), pBoss, "tester", other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS()));
				}
				else
				{
					pBoss = new Tester(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), nullptr, "tester", other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS());
					pBoss->setBoss(pBoss);
					employees.push_back(pBoss);
				}
				size_t cntTeams = teams.size();
				bool addNewTeam = true;
				for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
				{
					if (!strcmp(teams[j].getNameTeamProject(), other.employees[i]->getNameOfTestedProject()))
					{
						teams[j].addMember(employees[employees.size() - 1]);
						addNewTeam = false;
					}
				}
				if (addNewTeam)
				{
					Team newTeam(employees[employees.size() - 1], other.employees[i]->getNameOfTestedProject());
					newTeam.addMember(employees[employees.size() - 1]);
					teams.push_back(newTeam);
				}
				break;
			}
			case 'm':
			{
				Employee* pBoss = nullptr;
				bool flag = true;
				for (size_t j = 0;j < employees.size() && flag;j++)
				{
					if (!(strcmp(employees[j]->getName(), other.employees[i]->getBoss()->getName())))
					{
						flag = false;
						pBoss = employees[j];
					}
				}
				if (pBoss)
				{
					employees.push_back(new Master(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), pBoss, "master programmer", other.employees[i]->getNameOfCurrentProject(), other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS()));
				}
				else
				{
					pBoss = new Master(other.employees[i]->getName(), other.employees[i]->getAddress(), other.employees[i]->getEGN(), other.employees[i]->getDate(), nullptr, "master programmer", other.employees[i]->getNameOfCurrentProject(), other.employees[i]->getNameOfTestedProject(), other.employees[i]->getOS());
					pBoss->setBoss(pBoss);
					employees.push_back(pBoss);
				}
				size_t cntTeams = teams.size();
				bool addNewTeam = true;
				for (size_t j = 0;j < cntTeams&&addNewTeam;j++)
				{
					if (!strcmp(teams[j].getNameTeamProject(), other.employees[i]->getNameOfCurrentProject()))
					{
						teams[j].addMember(employees[employees.size() - 1]);
						addNewTeam = false;
					}
				}
				if (addNewTeam)
				{
					Team newTeam(employees[employees.size() - 1], other.employees[i]->getNameOfCurrentProject());
					newTeam.addMember(employees[employees.size() - 1]);
					teams.push_back(newTeam);
				}
				break;
			}
			}
		}
	}
	return *this;
}
//деструктор
Company::~Company()
{size_t cntEmployees=employees.size();
	for (size_t i = 0;i < cntEmployees;i++)
		{
			delete employees[i];
		}
}
