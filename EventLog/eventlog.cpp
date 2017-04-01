#include "eventlog.h"
#include<iostream>
using std::endl;
using std::cout;
using std::cin;

EventLog::EventLog()
{
	size = 0;
	capacity = 2;
	events = new Event[capacity];
}
EventLog::EventLog(const EventLog & other)
{
	events = new Event[other.capacity];
	for (int i = 0;i < other.size;i++)
	{
		events[i] = other.events[i];
	}
	size = other.size;
	capacity = other.capacity;
}
EventLog& EventLog::operator=(const EventLog& other)
{
	Event * newarray = new Event[other.capacity];
	for (int i = 0;i < other.size;i++)
	{
		newarray[i] = other.events[i];
	}
	delete events;
	events = newarray;
	size = other.size;
	capacity = other.capacity;
	return *this;
}
EventLog::EventLog(int n)
{
	size = 0;
	capacity = 2 * n;
	events = new Event[capacity];
}
void EventLog::addEvent(const Event& event) //& za da ne mu pravim izlishno kopie const za da ne go promenim
{
	if (size>= capacity)
	{
		resize();
	}
	events[size++] = event;
}
void EventLog::addEvent()
{
	cout << "enter new event:  " << endl;
	char buffer[150];
	char buffer2[100];
	int vis;
	int d;
	int m;
	int y;
	cout << "enter name:  " << endl;
	cin.getline(buffer, 150);
	cout << "enter place:  " << endl;
	cin.getline(buffer2, 100);
	cout << "enter max count guests:  " << endl;
	cin >> vis;
	cout << "enter day:  " << endl;
	cin >> d;
	cout << "enter month:  " << endl;
	cin >> m;
	cout << "enter year:  " << endl;
	cin >> y;
	cin.ignore();
	Event a(buffer, buffer2, vis, d, m, y);
	if (size>= capacity)
	{
		resize();
	}
	events[size++] = a;
}
void EventLog::resize()
{
	cout << "resize is called  " << endl;
	capacity = 2 * size;
	Event * tmp = new Event[capacity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = events[i];
	}
	delete[] events;
	events = tmp;
}
EventLog::~EventLog()
{
	delete[] events;
}
void EventLog::print() const
{
	for (int i = 0; i < size; i++)
	{
		events[i].print();
	}
}
