#include <iostream>
#include<fstream>
#include <cstring>
#include "car.h"
#include "holder.h"
#include "register.h"
using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ios;
Register::Register()
{

}
Register::Register(size_t n)
{
	reg = new Holder[n];
	size = n;
	for (size_t i = 0;i < size;i++)
	{
		cout << "enter new holder:" << endl;
		cout << "enter his name:" << endl;
		char _name[23];
		char _ID[30];
		unsigned r;
		char _namecar[50];
		unsigned power;
		cin.getline(_name, 23);
		cout << "enter ID of car:" << endl;
		cin.getline(_ID, 30);
		cout << "enter register number of car:" << endl;
		cin >> r;
		cin.ignore();
		cout << "enter mark of car:" << endl;
		cin.getline(_namecar, 50);
		cout << "enter power of car:" << endl;
		cin >> power;
		cin.ignore();
		Car a(_namecar, _ID, power);
		Holder person(_name, _ID, r, a);
		bool flag = true;
		for (size_t j = 0;j < i&&flag;j++)
		{
			if (!strcmp(reg[j].getID(), _ID))
			{
				flag = false;
				cout << "this car is already registrated enter next car" << endl;
				cout << "enter his name:" << endl;
				cin.getline(_name, 23);
				cout << "enter ID of car:" << endl;
				cin.getline(_ID, 30);
				cout << "enter register number of car:" << endl;
				cin >> r;
				cin.ignore();
				cout << "enter mark of car:" << endl;
				cin.getline(_namecar, 50);
				cout << "enter power of car:" << endl;
				cin >> power;
				cin.ignore();
				Car a(_namecar, _ID, power);
				Holder person(_name, _ID, r, a);
				reg[i] = person;
			}
		}
		if(flag) reg[i] = person;
	}
}
Register::Register(const Register& other)
{
	reg = new Holder[other.size];
	for (size_t i = 0;i < other.size;i++)
	{
		reg[i] = other.reg[i];
	}
	size = other.size;
}
void Register::addOwner()
{
	cout << "enter new holder:" << endl;
	cout << "enter his name:" << endl;
	char _name[23];
	char _ID[30];
	unsigned r;
	char _namecar[50];
	unsigned power;
	cin.getline(_name, 23);
	cout << "enter ID of car:" << endl;
	cin.getline(_ID, 30);
	cout << "enter register number of car:" << endl;
	cin >> r;
	cin.ignore();
	cout << "enter mark of car:" << endl;
	cin.getline(_namecar, 50);
	cout << "enter power of car:" << endl;
	cin >> power;
	cin.ignore();
	Car a(_namecar, _ID, power);
	Holder person(_name, _ID, r, a);
	for (size_t i = 0;i < size;i++)
	{
		if (!strcmp(reg[i].getID(), _ID))
		{
			cout << "this car is already registrated" << endl;
			return;
		}
	}
	Holder * newarr = new Holder[size + 1];
	for (size_t i = 0;i < size;i++)
	{
		newarr[i] = reg[i];
	}
	newarr[size] = person;
	delete reg;
	reg = newarr;
	size++;
}
void Register::print(ofstream& file) const
{
	for(size_t i=0;i<size;i++)
	{
		reg[i].print(file);
	}
}
Register& Register::operator=(const Register & other)
{
	if (this != &other)
	{
		delete reg;
		reg = new Holder[other.size];
		for (size_t i = 0;i < other.size;i++)
		{
			reg[i] = other.reg[i];
		}
		size = other.size;
	}
	return *this;
}
void Register::mostCommonCar(ofstream& file)
{
	char buff[50]="";
	int maxCnt = 0;
	for (size_t i = 0;i < size;i++)
	{
		int currentCount = 1;
		for (size_t j = i + 1;j < size;j++)
		{
			if (!strcmp(reg[i].getCarName(), reg[j].getCarName()))
				currentCount++;
		}

		if (currentCount > maxCnt)
		{
			strcpy(buff,reg[i].getCarName());
			maxCnt = currentCount;
		}
	}
	file << buff<<endl;
}
double Register::averagePowerOfAllCars()
{
	double ave=0;
	for (size_t i = 0;i < size;i++)
	{
		ave += reg[i].getCarPower();
	}
	return ave / size;
}
size_t Register::getSize() const
{
	return size;
}
Holder* Register::getReg()
{
	return reg;
}