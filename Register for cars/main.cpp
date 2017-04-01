#include <iostream>
#include <fstream>
#include "car.h"
#include "holder.h"
#include "register.h"
using std::ofstream;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
void saveDataBaseInTextFile()
{
	Register dateB(2);
	dateB.addOwner();
	ofstream file;
	file.open("car-report.txt", ios::app);
	dateB.mostCommonCar(file);
	file << dateB.averagePowerOfAllCars() << endl;
	file << dateB.getSize() << endl;
	dateB.print(file);
}
int main()
{
	Register dateB(3);
	ofstream file("db-save4.dat", ios::binary | ios::app);
	size_t cntCars = dateB.getSize();
	cout << cntCars;
	file.write((char*)&cntCars, sizeof(size_t));
	file.write((char*)dateB.getReg(), sizeof(Holder)*cntCars);
	system("pause");
	return 0;
}