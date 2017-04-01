#include<iostream>
#include "date.h"
#include "doctor.h"
#include "patient.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	Doctor a(5);
	a.addPatient();
	a.print();
	cout << a.averageVisits(4)<<endl;
	system("pause");
	return 0;
}