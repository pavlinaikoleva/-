#pragma once
#include "HistoryEntry.h"
#ifndef __BROWSER_HISTORY_H__
#define __BROWSER_HISTORY_H__
class BrowserHistory
{private:
	HistoryEntry* web;
	size_t maxcapacity;
	size_t size;
public:
	BrowserHistory(size_t n);
	BrowserHistory(const BrowserHistory & other);
	void addSite();
	BrowserHistory& operator=(const BrowserHistory & other);
	void operator+=(const BrowserHistory & other);
	BrowserHistory& operator+=(HistoryEntry a);
	void print();
	void search(int _month);
	int mostActiveMonth();
	void removeLatestSite();
	BrowserHistory operator+(const BrowserHistory& other); //ako ima kopi konstruktor moje bi shte raboti i bez & pri razultata
	~BrowserHistory();
};
#endif // !__BROWSER_HISTORY_H__
