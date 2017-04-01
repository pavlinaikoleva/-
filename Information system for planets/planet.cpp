#include<iostream>
#include <fstream>
#include "planet.h"
#include<cstring>
using std::cout;
using std::endl;
using std::cin;
using namespace std;
double Planet::seconds()
{
	return distance / 299792458.0;
}
const char * Planet::getName() const
{
	return name;
}
double Planet::getDistance() const
{
	return distance;
}
double Planet::getDiameter() const
{
	return diameter;
}
double Planet::getMass() const
{
	return mass;
}
void Planet::setName(char * newName)
{
	strcpy(name, newName);
}
void Planet::setDiameter(double newDiameter)
{
	diameter = newDiameter;
}
void Planet::setDistance(double newDistance)
{
	distance = newDistance;
}
void Planet::setMass(double newMass)
{
	mass = newMass;
}
void Planet::coutPlanet() const
{
	cout << "Info for planet  " << name << "  " << distance << "  " << diameter << "  " << mass << endl;
}
bool Planet::compareByDistanceAndDiameter(Planet b)
{
	if (distance != b.distance) return distance < b.distance;
	else return diameter < b.diameter;
}
void Planet::writePlanetInFile(const char * nameOfFile)
{
	ofstream out;
	out.open(nameOfFile, ios::app);
	out << name << endl;
	out << distance << endl;
	out << diameter << endl;
	out << mass << endl;
}
Planet Planet::readFromFilePlanet0(const char * nameOfFile)
{
	ifstream in;
	in.open(nameOfFile);
	in.getline(name, 32);
	in >> distance;
	in >> diameter;
	in >> mass;
	return *this;
}
Planet Planet::readFromFilePlanet(const char *nameOfFile, ifstream & in)
{
	Planet a;
	in.getline(a.name, 32);
	in >> a.distance;
	in >> a.diameter;
	in >> a.mass;
	in.ignore();
	return a;
}
bool Planet::compareByDistance(Planet b)
{
	return distance < b.distance;
}
bool Planet::compareByDiameter(Planet b)
{
	return diameter< b.diameter;
}
bool Planet::compareByMass(Planet b)
{
	return mass< b.mass;
}
bool Planet::compareByName(Planet b)
{
	return strcmp(name, b.name) == 1;
}
bool Planet::compareByAll(Planet b)
{
	if (strcmp(name, b.name) != 0) return strcmp(name, b.name) == 1;
	else {
		if (distance != b.distance) return distance < b.distance;
		else {
			if (diameter != b.diameter)  return diameter< b.diameter;
			else return mass< b.mass;
		}
	}
}
