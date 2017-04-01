#include<iostream>
#include "HistoryEntry.h"
#include "BrowserHistory.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	BrowserHistory a(5);
	BrowserHistory b(2);
	a.addSite();
	a.addSite();
	HistoryEntry p;
	p = enterSite();
	a.print();
	a += p;
	a.print();
	cout << a.mostActiveMonth() << endl;
	a.search(3);
	b.addSite();
	b.addSite();
	BrowserHistory c(6);
	c=a + b;
	c.print();
	a += b;
	cout << "this is history A:  " << endl;
	a.print();
	system("pause");
	return 0;
}