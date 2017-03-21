#include<iostream>
#include "rat.h"
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
void init_coef(Rat coef[], int n)
{
	for (int i = 0;i < n;i++)
	{
		double x;
		double y;
		cout << "Enter real number: ";
		cin >> x;
		cin >> y;
		coef[i].init(x, y);
	}
}
Rat poly(Rat coef[], int n, Rat x)
{
	Rat res(0, 1);
	for (int i = 0;i <= n;i++)
	{
		res=res+coef[n - i] * (x^i);
	}
	return res;

}

int main()
{
	int n;
	cout << "Enter degree of the polynom: ";
	cin >> n;
	Rat x;
	cout << "Enter x ";
	double a;
	double b;
	cin >> a;
	cin >> b;
	x.init(a,b);
	Rat* coef=new Rat[n+1];
	init_coef(coef, n + 1);
	poly(coef, n, x).print();
	delete[] coef;
	system("pause");
	return 0;
}