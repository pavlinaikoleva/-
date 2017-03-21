#include "rat.h"
#include<assert.h>
#include <iostream>
using std::endl;
using std::cout;
Rat::Rat(double x, double y)
{
	init(x, y);
}
void Rat::init(double x, double y)
{
	nom = x;
	if (y == 0) { cout << "denom=0 will cause errors automatic change to 1: " << endl;y = 1; }
	//assert(y == 0);
	denom = y;
}
Rat Rat::operator + (Rat other)//zashto ne moga da podam const Rat & other i samata funkciq da e const
{
	Rat c;
	c.nom = nom*other.denom + other.nom*denom;
	c.denom = denom*other.denom;
	return c;
}
Rat Rat::operator-(Rat other)
{
	Rat c;
	c.nom = nom*other.denom - other.nom*denom;
	c.denom = denom*other.denom;
	return c;
}
Rat Rat::operator *(Rat other)
{
	Rat c;
	c.nom = nom*other.nom;
	c.denom = denom*other.denom;
	return c;
}
Rat Rat::operator /(Rat other)
{
	Rat c;
	c.nom = nom*other.denom;
	c.denom = denom*other.nom;
	return c;
}
Rat Rat::operator ^(int deg)
{
	Rat res(1, 1);
	for (int i = 1;i <= deg;i++)
	{
		res =res*(*this);
	}
	return res;
}
void Rat::print() const
{
	cout << nom << '/' << denom<<endl;
}