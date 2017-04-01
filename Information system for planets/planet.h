using namespace std;
#include<fstream>
#ifndef __PLANET_H__
#define __PLANET_H__
class Planet
{
private:
	char name[32];
	double distance;
	double diameter;
	double mass;
public:
	double seconds();
	const char * getName() const;
	double getDistance() const;
	double getDiameter() const;
	double getMass() const;
	void coutPlanet() const;
	void setName(char * newName);
	void setDiameter(double newDiameter);
	void setDistance(double newDistance);
	void setMass(double newMass);
	bool compareByDistanceAndDiameter(Planet b);
	bool compareByDistance(Planet b);
	bool compareByDiameter(Planet b);
	bool compareByMass(Planet b);
	bool compareByName(Planet b);
	bool compareByAll(Planet b);
	void writePlanetInFile(const char * nameOfFile);
	Planet readFromFilePlanet0(const char * nameOfFile);
	Planet readFromFilePlanet(const char *nameOfFile, ifstream & in);
};
#endif