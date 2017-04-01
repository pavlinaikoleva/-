#include "date.h"
#include "doctor.h"
#include "patient.h"
#include <iostream>
#include <assert.h>
using std::cin;
using std::cout;
using std::endl;
Doctor::Doctor()
{

}
Doctor::Doctor(size_t n)
{
	patients = new Patient[n];
	countPatients = n;
	for (size_t i = 0;i < n;i++)
	{
		cout << "enter new patient: " << endl;
		char _name[32];
		cout << "enter name" << endl;
		cin.getline(_name, 32);
		int d, m, y;
		cout << "enter birthdate: " << endl;
		cin >> d >> m >> y;
		Date p;
		p.init(d, m, y);
		unsigned cnt;
		cout << "enter count of visits during this year: " << endl;
		cin >> cnt;
		cin.ignore();
		patients[i].init(_name, p, cnt);
	}
}
Doctor::Doctor(const Doctor & other)
{
	patients = new Patient[other.countPatients];
	for (size_t i = 0;i < other.countPatients;i++)
	{
		patients[i] = other.patients[i];
	}
	countPatients = other.countPatients;
}
Doctor&  Doctor::operator = (const Doctor & other)
{
	if (this != &other)
	{
		delete patients;
		patients = new Patient[other.countPatients];
		for (size_t i = 0;i < other.countPatients;i++)
		{
			patients[i] = other.patients[i];
		}
		countPatients = other.countPatients;
	}
	return *this;
}
double Doctor::averageVisits(unsigned visits)
{
	double sum=0;
	double cnt=0;
	for (size_t i = 0;i < countPatients;i++)
	{
		if (patients[i].getCountVisits() > visits)
		{
			cnt++;
			sum += patients[i].getCountVisits();
		}
	}
	return sum / cnt;
}
Patient& Doctor::operator[](size_t index)
{
	assert(index >= 0 && index < countPatients);
	return patients[index];
}
void Doctor::searchPatient(const char * _name)
{
	for (size_t i = 0;i < countPatients;i++)
	{
		if (!strcmp(patients[i].getName(), _name))
		{
			patients[i].setCountVisits(patients[i].getCountVisits + 1);
		}
	}
}
void Doctor::addPatient()
{
	cout << "enter new patient: " << endl;
	char _name[32];
	cout << "enter name" << endl;
	cin.getline(_name, 32);
	int d, m, y;
	cout << "enter birthdate: " << endl;
	cin >> d >> m >> y;
	Date p;
	p.init(d, m, y);
	unsigned cnt;
	cout << "enter count of visits during this year: " << endl;
	cin >> cnt;
	cin.ignore();
	Patient* newarr = new Patient[countPatients + 1];
	for (size_t i = 0;i < countPatients;i++)
	{
		newarr[i] = patients[i];
	}
	newarr[countPatients].init(_name, p, cnt);
	delete patients;
	patients = newarr;
	countPatients++;
}
void Doctor::print()const
{
	for (size_t i = 0;i < countPatients;i++)
		patients[i].print();
}
Doctor::~Doctor()
{
	delete patients;
}