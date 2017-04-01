#pragma once
#ifndef __INFORMATION_SYSTEM__
#include<iostream>
#include<fstream>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
#include "planet.h"
#define __INFORMATION_SYSTEM__
class InformationSystem
{
private:
	Planet * arr;
	int currentSizePlanets;
	int capacity;
public:
	void init();
	int getCurrentSizePlanets() const;
	int getCapacity() const;
	Planet const * getArr();//const trqbva da e kogato napravish distruktor
	void addNewPlanet();
	void addNewPlanetFromFile();
	void addSomeNewPlanetsFromFile();
	void printArray();
	void savePlanetsInFile();
	void saveOnePlanetInFile();
	void searchPlanet();
	void filterByDistance();
};
#endif 

