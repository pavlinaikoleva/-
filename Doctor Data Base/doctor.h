#pragma once

#include "date.h"
#include "patient.h"
#ifndef __DOCTOR_H__
#define __DOCTOR_H__
class Doctor
{
private:
	Patient * patients;
	size_t countPatients;
public:
	Doctor();
	Doctor(size_t n);
	Doctor(const Doctor & other);
	Doctor&  operator=(const Doctor & other);
	double averageVisits(unsigned visits);
	~Doctor();
	Patient& operator[](size_t index);
	void addPatient();
	void print()const;
	void searchPatient(const char * name);

};
#endif