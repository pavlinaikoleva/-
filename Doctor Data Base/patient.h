#pragma once
#include "date.h"
#ifndef __PATIENT_H__
#define __PATIENT_H__
class Patient
{
private:
	char name[32];
	Date dateOfBirth;
	unsigned countVisits;
public:
	Patient();
	Patient(const char * _name, Date _date, unsigned _countVisits);
	void init(const char * _name, Date _date, unsigned _countVisits);
	const char * getName() const;
	Date getDateOfBirth() const;
	unsigned getCountVisits() const;
	void print() const;
	void setName(const char * _newName);
	void setDate(Date _date);
	void setCountVisits(unsigned newCount);

};
#endif