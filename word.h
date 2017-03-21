#pragma once
#ifndef __WORD_H__
#define __WORD_H__
class Word
{
private:
	char duma[21];
	size_t size;
public:
	Word(char a);
	Word(char * str);
	Word();
	const char * getDuma()const;
	char& operator [] (size_t pos);
	Word operator+ (char a);
	Word& operator+=(char a);
	bool operator<(Word other);
	bool operator==(Word other);
	void print() const;
};
#endif
