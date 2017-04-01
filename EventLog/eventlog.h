#pragma once
#include "event.h"
#include "date.h"
#ifndef __EVENTLOG_H__
#define __EVENTLOG_H__
class EventLog
{
private:
	int size;
	int capacity;
	Event* events;
public:
	EventLog();
	EventLog(int n);
	EventLog(const EventLog & other);
	void addEvent(const Event& event);
	EventLog& operator=(const EventLog& other);
	void addEvent();
	void resize();
	void print() const;
	~EventLog();
};
#endif
