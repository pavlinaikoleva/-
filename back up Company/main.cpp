#include<iostream>
#include<fstream>
#include "date.h"
#include "employee.h"
#include "junior.h"
#include "master.h"
#include "tester.h"
#include "company.h"
using std::cin;
using std::cout;
using std::endl;
using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
void testBaseClasses()
{
	Employee* arr[3];
	Master greatboss;
	greatboss.setName("ico metdiev");
	Master rumen("dragan", "Plachkovci", "8741254710", "10.02.2001", &greatboss, "master programmer", "digitalizirane", "histogrami", "ubuntu");
	rumen.setName("Rumen Raikov");
	Tester i("Ivan Petrov", "boqna", "9102457148", "27.07.2009", &rumen, "tester", "navigation", "linux");
	Junior p("Pavlina Koleva", "Gvardejska", "9704167554", "16.04.2017", &i, "junior", "company");
	arr[0] = &p;
	arr[1] = &rumen;
	arr[2] = &i;
	for (int j = 0;j < 3;j++)
	{
		arr[j]->print();
	}
}
void testCompanyClass()
{
	Company firma;
	firma.addEmployee(new Master("Svetla", "Hristo Botev", "7401238564", "21.04.2008", nullptr, "master programmer", "Enigma", "Enigma", "windows"));
	firma.addEmployee();
	firma.addEmployee();
	firma.addEmployee();
	firma.printEmployeesOfCompany();
	cout << endl;
	firma.searchEmployee("9704167554");
	firma.editEmployee("7401238564");
	firma.printEmployeesByPosition("master programmer");
	cout <<endl;
	firma.fireEmployee("7401238564");
	firma.printEmployeesOfCompany();
}
void testTeams()
{
	Company NashtaFirma;
	NashtaFirma.addEmployee();
	NashtaFirma.addEmployee();
	NashtaFirma.addEmployee();
	NashtaFirma.addEmployee();
	NashtaFirma.printEmployeesByTeams();
	NashtaFirma.addNewTeamWithOutMembers("TeamVirtual");
	NashtaFirma.printEmployeesByTeams();
	NashtaFirma.deleteTeam();
	NashtaFirma.printEmployeesByTeams();
	NashtaFirma.moveEmployeeFromOneTeamToAnother("9704167554", "company");
	NashtaFirma.printEmployeesByTeams();
}
void testWriteOnFile()
{
	ofstream out("arhiv.txt", std::ios::app);
	Company NashtaFirma("Stefan","ITFuture","Vasil Levski");
	NashtaFirma.addEmployee();
	NashtaFirma.addEmployee();
	NashtaFirma.addEmployee();
	//NashtaFirma.addEmployee();
	NashtaFirma.SaveCompanyOnFile(out);
	out.close();
}
void testReadFromFile()
{
	ifstream input("arhiv.txt");
	Company newCompany;
	newCompany.loadCompanyFromFile(input);
	newCompany.printEmployeesOfCompany();
	newCompany.printEmployeesByTeams();
	input.close();
	Company CopyFirma;
	CopyFirma = newCompany;
	cout << "Check operator =" << endl;
	CopyFirma.printEmployeesOfCompany();
	CopyFirma.printEmployeesByTeams();
	cout << "promenqm copyFirma" << endl;
	CopyFirma.addEmployee();
	CopyFirma.printEmployeesOfCompany();
	CopyFirma.printEmployeesByTeams();
	cout << "promenila li se e parvata firma" << endl;
	newCompany.printEmployeesOfCompany();
	newCompany.printEmployeesByTeams();
}
int main()
{
	//testBaseClasses();
	//testCompanyClass();
	//testWriteOnFile();
	testReadFromFile();
	system("pause");
	return 0;
}