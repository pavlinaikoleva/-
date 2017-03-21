#include<iostream>
#include "word.h"
using namespace std;
int main()
{
	Word a("poli");
	//a.print();
	//(a + 'b').print();
	//(a += 'b').print();
	Word b("lolib");
	//a.print();
	cout << a[2]<<endl;
	a[12] = '7';
	a.print();
	b.print();
	cout << (a == b)<<endl;
	cout << (a < b) << endl;
	system("pause");
	return 0;
}