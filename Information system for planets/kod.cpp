/*#include<iostream>
//#include<fstream> v planets
//#include<cstring> ima q v planets.cpp
#include<cmath>
//using namespace std;
using std::cin;
using std::cout;
using std::endl;
/*struct Planet v header planet
{
	char name[32];
	double distance;
	double diameter;
	double mass;
};
/*struct ArrayOfPlanets v header infsystem
{
	Planet * arr;
	int size;
};*/
/*double seconds(Planet a) metod na klas Planet
{
	return a.distance / 299792458.0;
}
Planet cinPlanet(Planet * arr, int n)//may cause a problem after adding control against two planets whit same name
{
	Planet a;
	bool thereIsAlreadyPlanetWhitThisName = false;
	do {
		thereIsAlreadyPlanetWhitThisName = false;
		cout << "Enter planet:  " << endl;
		cin.getline(a.name, 32);
		//cin >> a.distance;
		//in >> a.diameter;
		//cin >> a.mass;
		//cin.ignore();
		for (int i = 0;i < n;i++)
		{
			cout << strcmp(a.name, arr[i].name) << endl;
			if (strcmp(a.name, arr[i].name) == 0)
			{
				thereIsAlreadyPlanetWhitThisName = true;
			}
		}
	} while (thereIsAlreadyPlanetWhitThisName);
	bool tooClose = false;
	do {
		tooClose = false;
		cout << "Enter distance,diameter,mass:  " << endl;
		cin >> a.distance;
		cin >> a.diameter;
		cin >> a.mass;
		cin.ignore();
		for (int i = 0;i < n;i++)
		{
			if (abs(a.distance - arr[i].distance) <= a.diameter + arr[i].diameter)
			{
				tooClose = true;
			}
		}
	} while (tooClose);
	//cin >> a.diameter;
	//cin >> a.mass;
	//cin.ignore();
	return a;
}
/*void coutPlanet(Planet a)
{
	cout << "Info for planet  " << a.name << "  " << a.distance << "  " << a.diameter << "  " << a.mass << endl;
}
void cinArray(Planet arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		arr[i] = cinPlanet(arr, n);
	}
}
void coutArray(Planet arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		coutPlanet(arr[i]);
	}
}
void bubbleSort(Planet arr[], int n, bool(*compare)(Planet, Planet))
{
	bool swapped = true;

	int j = 0;

	Planet tmp;

	while (swapped) {

		swapped = false;

		j++;

		for (int i = 0; i < n - j; i++) {

			if (compare(arr[i], arr[i + 1]))
			{

				tmp = arr[i];

				arr[i] = arr[i + 1];

				arr[i + 1] = tmp;

				swapped = true;

			}

		}

	}
}
/*bool compareByDistanceAndDiameter(Planet a, Planet b) metod na klas Planet
{
	if (a.distance != b.distance) return a.distance < b.distance;
	else return a.diameter < b.diameter;
}*/
/*void writePlanetInFile(const char * nameOfFile, Planet a) metod na planet
{
	ofstream out;
	out.open(nameOfFile, ios::app);
	out << a.name << endl;
	out << a.distance << endl;
	out << a.diameter << endl;
	out << a.mass << endl;
}
void writeArrayOfPlanetsInFile(const char *nameOfFile, Planet * arr, int n)
{
	ofstream out;
	out.open(nameOfFile, ios::app);
	out << n << endl;
	for (int i = 0;i < n;i++)
	{
		writePlanetInFile(nameOfFile, arr[i]);
	}
}
/*Planet readFromFilePlanet0(const char * nameOfFile)
{
	ifstream in;
	in.open(nameOfFile);
	Planet a;
	in.getline(a.name, 32);
	in >> a.distance;
	in >> a.diameter;
	in >> a.mass;
	return a;
}*/
/*Planet readFromFilePlanet(const char *nameOfFile, ifstream & in)
{
	Planet a;
	in.getline(a.name, 32);
	in >> a.distance;
	in >> a.diameter;
	in >> a.mass;
	in.ignore();
	return a;
}
ArrayOfPlanets readArrayOfPlanetsFromFile(const char * nameOfFile)
{
	ArrayOfPlanets mas;
	ifstream in;
	in.open(nameOfFile);
	in >> mas.size;
	in.ignore();
	mas.arr = new Planet[100];
	//mas.arr=new Planet[mas.size]; nai korektno ako e samostoqtelnata funkciq no zaradi sistemata
	for (int i = 0;i < mas.size;i++)
	{
		mas.arr[i] = readFromFilePlanet(nameOfFile, in);
		/*in.getline(mas.arr[i].name, 32);
		in >> mas.arr[i].distance;
		in >> mas.arr[i].diameter;
		in >> mas.arr[i].mass;
		in.ignore();//
	}
	return mas;
}
void sortByName(Planet *arr, int n)
{
	bool flag = true;
	int j = 0;
	Planet tmp;
	while (flag)
	{
		flag = false;
		j++;
		for (int i = 0;i < n - j;i++)
		{
			if (strcmp(arr[i].name, arr[i + 1].name) == 1)
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = true;
			}
		}
	}
}
void sortBySomething(Planet *arr, int n, bool(*compare)(Planet, Planet))
{
	bool flag = true;
	int j = 0;
	Planet tmp;
	while (flag)
	{
		flag = false;
		j++;
		for (int i = 0;i < n - j;i++)
		{
			if (compare(arr[i], arr[i + 1]))
			{
				tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				flag = true;
			}
		}
	}
}
/*bool compareByDistance(Planet a, Planet b)
{
	return a.distance < b.distance;
}*/
/*bool compareByDiameter(Planet a, Planet b)
{
	return a.diameter< b.diameter;
}*/
/*bool compareByMass(Planet a, Planet b)
{
	return a.mass< b.mass;
}*/
/*bool compareByName(Planet a, Planet b)
{
	return strcmp(a.name, b.name) == 1;
}*/
/*bool compareByAll(Planet a, Planet b)
{
	if (strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name) == 1;
	else {
		if (a.distance != b.distance) return a.distance < b.distance;
		else {
			if (a.diameter != b.diameter)  return a.diameter< b.diameter;
			else return a.mass< b.mass;
		}
	}
}
int main()
{
	Planet *System = NULL;
	int currentCountPlanets = 0;
	cout << "enter way to create a system of planets for new system pres 'n' for reading a system from file press 'f': " << endl;
	char rejim;
	cin >> rejim;
	switch (rejim)
	{
	case 'f': {
		cin.ignore();
		Planet* SystemHelp;
		ArrayOfPlanets arr2;
		cout << "enter name of file:  " << endl;
		char buffer[100];
		cin.getline(buffer, 100);
		arr2 = readArrayOfPlanetsFromFile(buffer);
		SystemHelp = arr2.arr;
		currentCountPlanets = arr2.size;
		System = SystemHelp;break;}
	case 'n': {Planet System1[100];
		System = System1;
		break;}
	}
	/*Planet* System;
	int currentCountPlanets = 0;
	ArrayOfPlanets arr2;
	cout << "enter name of file:  " << endl;
	char buffer[100];
	cin.getline(buffer, 100);
	arr2 = readArrayOfPlanetsFromFile(buffer);
	System = arr2.arr;
	currentCountPlanets = arr2.size;// krai na komentara
	int key;
	cout << "Enter command: ";
	cin >> key;
	while (key != 13)
	{

		switch (key)
		{
		case 1: {cin.ignore();
			System[currentCountPlanets++] = cinPlanet(System, currentCountPlanets);break;
		}
		case 2: {cout << "enter name of file:  " << endl;
			char buffer[100];
			cin.ignore();
			cin.getline(buffer, 100);
			System[currentCountPlanets++] = readFromFilePlanet0(buffer);
			break;
		}
		case 3: {cout << "enter name of file:  " << endl;
			char buffer[100];
			cin.ignore();
			cin.getline(buffer, 100);
			ArrayOfPlanets arr;
			arr = readArrayOfPlanetsFromFile(buffer);
			for (int j = 0;j<arr.size;j++)
			{
				System[currentCountPlanets++] = arr.arr[j];
			}
			delete[] arr.arr;
			break;
		}
		case 4: {coutArray(System, currentCountPlanets);
			break;
		}
		case 5: {cout << "enter name of file:  " << endl;
			char buffer[100];
			cin.ignore();
			cin.getline(buffer, 100);
			writeArrayOfPlanetsInFile(buffer, System, currentCountPlanets);
			break;
		}
		case 6: {cout << "enter name of planet:  " << endl;
			char planeta[100];
			cin.ignore();
			cin.getline(planeta, 100);
			cout << "enter name of file:  " << endl;
			char buffer[100];
			cin.getline(buffer, 100);
			for (int i = 0;i < currentCountPlanets;i++)
			{
				if (!strcmp(System[i].name, planeta))
					writePlanetInFile(buffer, System[i]);
			}
			break;
		}
		case 7: {char planeta[100];
			cout << "enter name of planet:  " << endl;
			cin.ignore();
			cin.getline(planeta, 100);
			for (int i = 0;i < currentCountPlanets;i++)
			{
				if (!strcmp(System[i].name, planeta))
					coutPlanet(System[i]);
			}
			break;
		}
		case 8: {double maxdis, mindis;
			cout << "Entex max and min distances between the planet and the sun:  " << endl;
			cin >> mindis >> maxdis;
			for (int i = 0;i < currentCountPlanets;i++)
			{
				if (System[i].distance >= mindis&&System[i].distance <= maxdis)
				{
					coutPlanet(System[i]);
				}
			}
			break;
		}
		case 9:
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
		}
		default: {
			key = 13;
			system("pause");
			return 0;
		}
		}
		cout << "Enter command: ";
		cin >> key;
	}
	/*int n;
	//cin >> n;
	//cin.ignore();
	char buffer[100];
	cin.getline(buffer, 100);
	//Planet * arr = new Planet[n];
	//cinArray(arr, n);
	//bubbleSort(arr, n, compareByDistanceAndDiameter);
	//writePlanetInFile(buffer, arr[0]);
	//coutPlanet(readFromFilePlanet(buffer));
	//cout << "otdeli " << endl;
	//writeArrayOfPlanetsInFile(buffer, arr, n);
	//coutArray(arr, n);
	//delete[] arr;
	ArrayOfPlanets arr;
	arr = readArrayOfPlanetsFromFile(buffer);
	cout << arr.size << endl;
	coutArray(arr.arr, arr.size);//krai na komentara
	delete[] System;
	system("pause");
	return 0;
}*/
