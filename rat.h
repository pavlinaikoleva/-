#pragma once
#ifndef __RAT_H__
#define __RAT_H__
class Rat
{private:
	double nom;
	double denom;
public:
	void init(double x = 0, double y = 1);
	Rat(double x = 0, double y = 1);
	Rat operator + (Rat other);
	Rat operator -(Rat other);
	Rat operator *(Rat other);
	Rat operator /(Rat other);
	Rat operator ^(int deg);
	void print() const;
};
#endif