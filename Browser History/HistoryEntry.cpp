#include<iostream>
#include "HistoryEntry.h"
using std::cout;
using std::cin;
using std::endl;
void printHistoryEntry(HistoryEntry a)
{
	cout << "Entry site: " << a.month << "  " << a.URL << endl;
}
HistoryEntry enterSite()
{
	HistoryEntry p;
	cout << "Enter URL of site  " << endl;
	cin.getline(p.URL, 200);
	cout << "Enter the month of visiting " << endl;
	cin >> p.month;
	cin.ignore();
	return p;
}
