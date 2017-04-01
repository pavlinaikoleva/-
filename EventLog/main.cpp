#include<iostream>
#include "date.h"
#include "event.h"
#include "eventlog.h"
using std::cin;
using std::cout;
using std::endl;
int main()
{
	EventLog log;
	Event a("party", "NDK", 100, 16, 3, 2016);
	Event b("leanUp", "SU", 200, 27, 3, 2017);
	log.addEvent(a);
	log.addEvent(b);
	log.addEvent();
	log.addEvent();
	log.print();
	EventLog log2(log);
	log2.addEvent();
	log.print();
	cout << "log2  " << endl;
	log2.print();
	system("pause");
	return 0;
}