#include<iostream>
#include "HistoryEntry.h"
#include "BrowserHistory.h"
using std::cout;
using std::cin;
using std::endl;
BrowserHistory::BrowserHistory(size_t n)
{
	web = new HistoryEntry[n];
	maxcapacity = n;
	size = 0;
}
BrowserHistory::BrowserHistory(const BrowserHistory & other)
{
	web = new HistoryEntry[other.maxcapacity];
	maxcapacity = other.maxcapacity;
	size = other.size;
	for (int i = 0;i < size;i++)
	{
		web[i] = other.web[i];
	}
}
BrowserHistory& BrowserHistory::operator=(const BrowserHistory & other)
{
	HistoryEntry * newarray = new HistoryEntry[other.maxcapacity];
	for (int i = 0;i < other.size;i++)
	{
		newarray[i] = other.web[i];
	}
	maxcapacity = other.maxcapacity;
	size = other.size;
	delete web;
	web = newarray;
	return *this;
}
void BrowserHistory::addSite()
{
	if (size == maxcapacity) {
		cout << "The capacity of history is full.Can not add new site" << endl;return;
	}
	web[size++]=enterSite();
}
BrowserHistory& BrowserHistory::operator+=(HistoryEntry a)
{
	if (size == maxcapacity) {
		cout << "The capacity of history is full.Can not add new site" << endl;return *this;
	}
	web[size++] = a;
	return *this;
}
void BrowserHistory::print()
{
	for (size_t i = 0;i < size;i++)
	{
		printHistoryEntry(web[i]);
	}
}
void BrowserHistory::search(int _month)
{
	for (size_t i = 0;i < size;i++)
	{
		if (web[i].month == _month)
			printHistoryEntry(web[i]);
	}
}
int BrowserHistory::mostActiveMonth()
{
	int mostActiveCount = 1;
	int mostActiveMonth = web[0].month;
	for (size_t i = 0;i < size;i++)
	{
		int countcurrent = 1;
		for (size_t j = i + 1;j < size;j++)
		{
			if (web[i].month == web[j].month)
				countcurrent++;
		}
		if (countcurrent > mostActiveCount)
		{
			mostActiveCount = countcurrent;
			mostActiveMonth = web[i].month;
		}
	}
	return mostActiveMonth;
}
void BrowserHistory::removeLatestSite()
{
	web[size - 1].month = 0;
	web[size - 1].URL[0] = '\0';
	size--;
}
void BrowserHistory::operator+=(const BrowserHistory & other)
{
	HistoryEntry* newarray = new HistoryEntry[size + other.size];
	size_t i;
	for (i = 0;i < size;i++)
	{
		newarray[i] = web[i];
	}
	for (size_t j = 0;j < other.size;j++)
	{
		newarray[i++] = other.web[j];
	}
	delete web;
	size = size + other.size;
	maxcapacity = maxcapacity + other.maxcapacity;
	web = newarray;
}
BrowserHistory BrowserHistory::operator+(const BrowserHistory& other)//ako ne e & se sazdava kopie na vrashtaniq rezultat i masiva stava prazen
{
	BrowserHistory res(maxcapacity + other.maxcapacity);
	size_t i;
	for (i = 0;i < size;i++)
	{
		res.web[i] = web[i];
	}
	for (size_t j = 0;j < other.size;j++)
	{
		res.web[i++] = other.web[j];
	}
	res.size = size + other.size;
	res.maxcapacity = maxcapacity + other.maxcapacity;
	return res;
}
BrowserHistory::~BrowserHistory()
{
	delete[] web;
}