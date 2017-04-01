#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include "planet.h"
#include "infsystem.h"
int main()
{
	InformationSystem System;
	System.init();
	/*Planet b;
	b.setName("neptun");
	b.setDistance(156456);
	b.setDiameter(1241);
	b.setMass(122421);
	b.writePlanetInFile("planet.txt");
	System.init();
	System.addNewPlanet();
	System.addNewPlanet();
	System.addNewPlanet();
	System.addNewPlanetFromFile();
	System.printArray();*/
	int key;
	cout << "Enter command: ";
	cin >> key;
	while (key != 13)
	{

		switch (key)
		{
		case 1: {cin.ignore();
			System.addNewPlanet();break;
		}
		case 2: {System.addNewPlanetFromFile();
			break;
		}
		case 3: {System.addSomeNewPlanetsFromFile();
			break;
		}
		case 4: {System.printArray();
			break;
		}
		case 5: {System.savePlanetsInFile();
			break;
		}
		case 6: {System.saveOnePlanetInFile();
			break;
		}
		case 7: {System.searchPlanet();
			break;
		}
		case 8: {System.filterByDistance();
			break;
		}
		/*case 9:
		{	char sym;
		cout << "Sort By  " << endl;
		cin >> sym;
		switch (sym)
		{
		case 'n': {sortBySomething(System, currentCountPlanets, compareByName);break;}
		case 'd': {sortBySomething(System, currentCountPlanets, compareByDistance);break;}
		case 'r': {sortBySomething(System, currentCountPlanets, compareByDiameter);break;}
		case'm': {sortBySomething(System, currentCountPlanets, compareByMass);break;}
		case 'a': {sortBySomething(System, currentCountPlanets, compareByAll);break;}
		}
		break;
		}
		case 10: {double maxMass, minMass;
			cout << "Entex min and max masses of the planets to show:  " << endl;
			cin >> minMass >> maxMass;
			for (int i = 0;i < currentCountPlanets;i++)
			{
				if (System[i].mass >= minMass&&System[i].mass <= maxMass)
				{
					coutPlanet(System[i]);
				}
			}
			break;}
		case 11: {double maxDiam, minDiam;
			cout << "Entex min and max diametres of planets to show:  " << endl;
			cin >> minDiam >> maxDiam;
			for (int i = 0;i < currentCountPlanets;i++)
			{
				if (System[i].diameter >= minDiam&&System[i].diameter <= maxDiam)
				{
					coutPlanet(System[i]);
				}
			}
			break;
		}*/
		default: {
			key = 13;
			system("pause");
			return 0;
		}
		}
		cout << "Enter command: ";
		cin >> key;
	}
	//delete[] System.getArr();
	system("pause");
	return 0;
}