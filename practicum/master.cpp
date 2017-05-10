#include<iostream>
#include "master.h"
using std::cin;
using std::cout;
using std::endl;
Master::Master(){}
Master::Master(const char * _name, const char * _address, const char * _EGN, const char *_date, Employee * _boss, const char * _position, const char* _nameOfCurrentProject, const char * _nameOfTestedProject, const char * _OS)
	:Employee(_name, _address, _EGN, _date, _boss)
{
	this->setPosition(_position);
	this->setNameOfCurrentProject(_nameOfCurrentProject);
	(*this).setNameOfTestedProject(_nameOfTestedProject);
	this->setOS(_OS);
}
const char * Master::getNameOfCurrentProject() const
{
	return nameOfCurrentProject;
}
void Master::setNameOfCurrentProject(const char * newName)
{
	strcpy_s(nameOfCurrentProject, strlen(newName) + 1, newName);
}
void Master::print() const
{
	cout << "Information for Master Programmer: "
		<< name << " "
		<< address << " "
		<< EGN << " "
		<< date.get_day() << "."
		<< date.get_month() << "."
		<< date.get_year() << " "
		<< (*boss).getName() << " "
		<< position << " "
		<<nameOfCurrentProject<<" "
		<< nameOfTestedProject << " "
		<< OS << endl;
}

const char * Master::getNameOfTestedProject() const
{
	return nameOfTestedProject;
}
void Master::setNameOfTestedProject(const char * newName)
{
	strcpy_s(nameOfTestedProject, strlen(newName) + 1, newName);
}
const char *Master::getOS() const
{
	return OS;
}
void Master::setOS(const char* _OS)
{
	strcpy_s(OS, strlen(_OS) + 1, _OS);
}
void Master::save(std::ostream& out)const
{
	char bufM[3];
	bufM[0] = date.get_month() / 10 + '0';
	bufM[1] = date.get_month() % 10 + '0';
	bufM[2] = '\0';
	char bufD[3];
	bufD[0] = date.get_day() / 10 + '0';
	bufD[1] = date.get_day() % 10 + '0';
	bufD[2] = '\0';
	out << "m "<<endl
		<< name << endl
		<< address << endl
		<< EGN << endl
		<< bufD << "."
		<< bufM << "."
		<< date.get_year() << endl
		<< (*boss).getName() << endl
		<< position << endl
		<<nameOfCurrentProject<<endl
		<< nameOfTestedProject << endl
		<< OS << endl;
}