#include "niz.h"
#include <assert.h>
using std::endl;
Niz::Niz(const char *str)
{
	sizeBytes = strlen(str);
	mystring = new char[sizeBytes];
	for (size_t i = 0;i < sizeBytes;i++)
	{
		mystring[i] = str[i];
	}
	/*zero ended
	sizeBytes=strlen(str);
	mystring=new char[sizeBytes+1];
	strcpy_s(mystring,sizeBytes+1,str);
	*/
}

Niz::Niz(const Niz &other)
{
	mystring = new char[other.sizeBytes];
	for (size_t i = 0;i < other.sizeBytes;i++)
	{
		mystring[i] = other.mystring[i];
	}
	sizeBytes = other.sizeBytes;
	/*
	mystring = new char[other.sizeBytes+1];
	strcpy_s(mystring,stelen(other.sizeBytes)+1,other.mystring);
	sizeBytes=other.sizeBytes;
	*/
}
Niz& Niz::operator = (const Niz &other)
{
	if (this != &other)
	{
		delete[] mystring;
		mystring = new char[other.sizeBytes];
		for (size_t i = 0;i < other.sizeBytes;i++)
		{
			mystring[i] = other.mystring[i];
		}
		sizeBytes = other.sizeBytes;
	}
	return *this;
	/*if (this != &other)
	{
		delete[] mystring;
		mystring = new char[other.sizeBytes+1];
		strcpy_s(mysting,sizeBytes+1,other.mystring);
		sizeBytes = other.sizeBytes;
	}
	return *this;
	*/
}
Niz& Niz::operator = (const char *str)
{
	delete[] mystring;
	sizeBytes = strlen(str);
	mystring = new char[sizeBytes];
	for (size_t i = 0;i < sizeBytes;i++)
	{
		mystring[i] = str[i];
	}
	return *this;
	/*delete[] mystring;
	mystring = new char[other.sizeBytes+1];
	strcpy_s(mystring,stelen(other.sizeBytes)+1,other.mystring);
	sizeBytes=other.sizeBytes;
	return *this;
	*/
}
Niz::~Niz()
{
	delete[] mystring;
}

size_t Niz::length() const
{
	return sizeBytes;
}

char& Niz::operator [] (unsigned int index)
{
	assert(index >= 0 && index < sizeBytes);
	return mystring[index];
}
char Niz::operator [] (unsigned int index) const
{
	assert(index >= 0 && index < sizeBytes);
	return mystring[index];
}

Niz Niz::operator + (const Niz &other) const
{
	Niz res;
	res.mystring = new char[sizeBytes + other.sizeBytes];
	size_t i;
	for (i = 0;i < sizeBytes;i++)
	{
		res.mystring[i] = mystring[i];
	}
	for (size_t j = 0;j < other.sizeBytes;j++)
	{
		res.mystring[i++] = other.mystring[j];
	}
	res.sizeBytes = sizeBytes + other.sizeBytes;
	return res;
}
Niz& Niz::operator += (const Niz &other) 
{
	char *temp = new char[sizeBytes+other.sizeBytes];
	size_t i;
	for (i = 0;i < sizeBytes;i++)
	{
		temp[i] = mystring[i];
	}
	delete[] mystring;
	mystring = temp;
	for (size_t j = 0;j < other.sizeBytes;j++)
	{
		mystring[i++] = other.mystring[j];
	}
	sizeBytes += other.sizeBytes;
	return *this;
}

bool Niz::operator < (const Niz &other) const
{
	
	for (size_t i = 0;i < sizeBytes&&i < other.sizeBytes;i++)
	{
		if (mystring[i] > other.mystring[i])  return false;
		else if(mystring[i] < other.mystring[i]) return true;
	}
	return sizeBytes < other.sizeBytes;
}
bool Niz::operator > (const Niz &other) const
{
	for (size_t i = 0;i < sizeBytes&&i < other.sizeBytes;i++)
	{
		if (mystring[i] < other.mystring[i])  return false;
		else if (mystring[i] > other.mystring[i]) return true;
	}
	return sizeBytes > other.sizeBytes;
}
bool Niz::operator <= (const Niz &other) const
{
	for (size_t i = 0;i < sizeBytes&&i < other.sizeBytes;i++)
	{
		if (mystring[i] > other.mystring[i])  return false;
		else if (mystring[i] < other.mystring[i]) return true;
	}
	return sizeBytes <= other.sizeBytes;
}
bool Niz::operator >= (const Niz &other) const
{
	for (size_t i = 0;i < sizeBytes&&i < other.sizeBytes;i++)
	{
		if (mystring[i] < other.mystring[i])  return false;
		else if (mystring[i] > other.mystring[i]) return true;
	}
	return sizeBytes >= other.sizeBytes;
}
bool Niz::operator == (const Niz &other) const
{
	if (sizeBytes != other.sizeBytes) return false;
	bool flag = true;
	for (size_t i = 0;i < sizeBytes&&flag;i++)
	{
		if (mystring[i] != other.mystring[i]) flag = false;
	}
	return flag;
}
bool Niz::operator != (const Niz &other) const
{
	return !(*this == other);
}

std::ostream& operator << (std::ostream& out, const Niz& str)
{
	for (size_t i = 0;i < str.length();i++)
	{
		out << str[i];
	}
	return out;
}