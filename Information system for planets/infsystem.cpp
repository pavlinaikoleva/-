#include "infsystem.h"
#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
void InformationSystem::init()
{
	arr = new Planet[1];
	currentSizePlanets = 0;
	capacity = 1;
}
int InformationSystem::getCurrentSizePlanets() const
{
	return currentSizePlanets;
}
int InformationSystem::getCapacity() const
{
	return capacity;
}
Planet const * InformationSystem::getArr()
{
	return arr;
}
void InformationSystem::addNewPlanet()
{
	if (currentSizePlanets >= capacity)
	{
		Planet * pointer = new Planet[capacity * 2];
		for (int i = 0; i < currentSizePlanets; i++)
		{
			pointer[i] = arr[i];
		}
		delete[] arr;
		arr = pointer;
		capacity *= 2;
	}
	cout << "Enter new planet:" << endl;
	Planet a;
	char buffer[32];
	cin.getline(buffer, 32);
	a.setName(buffer);
	double temp;
	cin >> temp;
	a.setDistance(temp);
	cin >> temp;
	a.setDiameter(temp);
	cin >> temp;
	a.setMass(temp);
	cin.ignore();
	arr[currentSizePlanets++] = a;
}
void InformationSystem::addNewPlanetFromFile()
{
	if (currentSizePlanets >= capacity)
	{
		Planet * pointer = new Planet[capacity * 2];
		for (int i = 0; i < currentSizePlanets; i++)
		{
			pointer[i] = arr[i];
		}
		delete[] arr;
		arr = pointer;
		capacity *= 2;
	}
	cout << "enter name of file:  " << endl;
	char buffer[100];
	cin.ignore();
	cin.getline(buffer, 100);
	arr[currentSizePlanets++].readFromFilePlanet0(buffer);
}
void InformationSystem::addSomeNewPlanetsFromFile()
{
	cout << "enter name of file:  " << endl;
	char buffer[100];
	cin.ignore();
	cin.getline(buffer, 100);
	ifstream in;
	in.open(buffer);
	int size;
	in >> size;
	in.ignore();
	if (currentSizePlanets + size >= capacity)
	{
		Planet * pointer = new Planet[(capacity + size) * 2];
		for (int i = 0; i < currentSizePlanets; i++)
		{
			pointer[i] = arr[i];
		}
		delete[] arr;
		arr = pointer;
		capacity = (capacity + size) * 2;
	}
	for (int i = 0; i < size; i++)
	{
		char newName[32];
		in.getline(newName, 32);
		arr[currentSizePlanets].setName(newName);
		double temp;
		in >> temp;
		arr[currentSizePlanets].setDistance(temp);
		in >> temp;
		arr[currentSizePlanets].setDiameter(temp);
		in >> temp;
		arr[currentSizePlanets].setMass(temp);
		in.ignore();
		currentSizePlanets++;
	}
}
void InformationSystem::printArray()
{
	for (int i = 0; i < currentSizePlanets; i++)
	{
		arr[i].coutPlanet();
	}
}
void InformationSystem::savePlanetsInFile()
{
	cout << "enter name of file:  " << endl;
	char buffer[100];
	cin.ignore();
	cin.getline(buffer, 100);
	ofstream out;
	out.open(buffer, ios::app);
	out << currentSizePlanets << endl;
	for (int i = 0; i < currentSizePlanets; i++)
	{
		arr[i].writePlanetInFile(buffer);
	}
}
void InformationSystem::saveOnePlanetInFile()
{
	cout << "enter name of planet:  " << endl;
	char planeta[100];
	cin.ignore();
	cin.getline(planeta, 100);
	cout << "enter name of file:  " << endl;
	char buffer[100];
	cin.getline(buffer, 100);
	for (int i = 0; i < currentSizePlanets; i++)
	{
		if (!strcmp(arr[i].getName(), planeta))
			arr[i].writePlanetInFile(buffer);
	}
}
void InformationSystem::searchPlanet()
{
	char planeta[100];
	cout << "enter name of planet:  " << endl;
	cin.ignore();
	cin.getline(planeta, 100);
	for (int i = 0; i < currentSizePlanets; i++)
	{
		if (!strcmp(arr[i].getName(), planeta))
			arr[i].coutPlanet();
	}
}
void InformationSystem::filterByDistance()
{
	double maxdis, mindis;
	cout << "Entex max and min distances between the planet and the sun:  " << endl;
	cin >> mindis >> maxdis;
	for (int i = 0; i < currentSizePlanets; i++)
	{
		if (arr[i].getDistance() >= mindis&&arr[i].getDistance() <= maxdis)
		{
			arr[i].coutPlanet();
		}
	}
}
