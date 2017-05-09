#include <iostream>
#include <assert.h>
#include "tester.h"
using std::cin;
using std::cout;
using std::endl;
Tester::Tester(){}
Tester::Tester(const char * _name, const char * _address, const char * _EGN, const char *_date, Employee * _boss, const char * _position, const char * _nameOfTestedProject, const char * _OS)
	:Employee(_name, _address, _EGN, _date, _boss)
{
	this->setPosition(_position);
	(*this).setNameOfTestedProject(_nameOfTestedProject);
	this->setOS(_OS);
}
void Tester::print() const
{
	cout << "Information for Junior Tester: "
		<< name << " "
		<< address << " "
		<< EGN << " "
		<< date.get_day() << "."
		<< date.get_month() << "."
		<< date.get_year() << " "
		<< (*boss).getName() << " "
		<< position << " "
		<< nameOfTestedProject << " "
		<< OS << endl;
}
const char * Tester::getNameOfTestedProject() const
{
	return nameOfTestedProject;
}
void Tester::setNameOfTestedProject(const char * newName)
{
	strcpy_s(nameOfTestedProject, strlen(newName) + 1, newName);
}
const char *Tester::getOS() const
{
	return OS;
}
void Tester::setOS(const char* _OS)
{
	strcpy_s(OS, strlen(_OS) + 1, _OS);
}
const char * Tester::getNameOfCurrentProject() const
{
	assert(false);
	return "false";
}
void Tester::setNameOfCurrentProject(const char * newName)
{
	assert(false);
	return;
}