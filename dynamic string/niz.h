#pragma once
#ifndef __NIZ_H__
#define __NIZ_H__
#include<fstream>
class Niz
{private:
	char * mystring;
	size_t sizeBytes;
public:
	Niz(const char *str = "");
	Niz(const Niz &other);
	Niz& operator = (const Niz &other);
	Niz& operator = (const char *str);
	~Niz();

	size_t length() const;

	char& operator [] (unsigned int index);
	char operator [] (unsigned int index) const;

	Niz operator + (const Niz &other) const;
	Niz& operator += (const Niz &other);

	bool operator < (const Niz &other) const;
	bool operator > (const Niz &other) const;
	bool operator <= (const Niz &other) const;
	bool operator >= (const Niz &other) const;
	bool operator == (const Niz &other) const;
	bool operator != (const Niz &other) const;

};
std::ostream& operator << (std::ostream& out, const Niz& string);
#endif // !__NIZOVE_H__
