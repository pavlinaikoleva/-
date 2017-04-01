#include<iostream>
#include<cstring>
#include<assert.h>
#include "word.h"
using std::cout;
using std::endl;
Word::Word(char a)
{
	duma[0] = a;
	duma[1] = '\0';
	size = 1;
}
Word::Word(char * str)
{
	strcpy(duma, str);
	size = strlen(str);
}
Word::Word()
{
	strcpy(duma, "");
	size = 0;
}
char& Word::operator [] (size_t pos)
{
	//assert(pos >= 21);
	if (pos > size - 1)
	{
		for (int i = size;i < pos;i++)
		{
			duma[i] = ' ';
		}
		duma[pos + 1] = '\0';
		size = pos + 1;
		return duma[pos];
	}
	return duma[pos];
}
const char * Word::getDuma()const
{
	return duma;
}
Word Word::operator+ (char a)
{
	Word newWord;
	strcpy(newWord.duma, duma);
	newWord.size = size;
	if (newWord.size == 20) { return newWord; }
	newWord.duma[(newWord.size)++] = a;
	newWord.duma[newWord.size] = '\0';
	return newWord;
}
Word& Word::operator+=(char a)
{
	if (size == 20) { return *this; }
	duma[size++] = a;
	duma[size] = '\0';
	return *this;
}
bool Word::operator<(Word other)
{
	return strcmp(duma, other.duma)<0;
}
bool Word::operator==(Word other)
{
	return strcmp(duma, other.duma)==0;
}
void Word::print() const
{
	cout << duma << endl;
	cout <<"Count letters:  "<< size << endl;
}