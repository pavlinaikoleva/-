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
	firma.addEmployee(new Master("Svetla", "monaco", "7401238564", "21.04.2008", nullptr, "master programmer", "firma", "firma", "windows"));
	firma.addEmployee();
	firma.addEmployee();
	firma.printEmployeesOfCompany();
	firma.searchEmployee("9704167554");
	firma.fireEmployee("7401238564");
	firma.printEmployeesOfCompany();
}
int main()
{
	//testBaseClasses();
	testCompanyClass();
	system("pause");
	return 0;
}