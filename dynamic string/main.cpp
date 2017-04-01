#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "niz.h"
int main()
{
	Niz s="aba";
	Niz p = "aba";
	cout << (s >= p) << endl;
	cout << s + p<<endl;
	cout << (s += p) << endl;
	cout << s<<endl;
	//s[7] = 'p';
	//cout << s[7] << endl;
	cout << s;
	system("pause");
	return 0;
}