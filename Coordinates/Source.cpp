#include<iostream>
#include<cmath>
using namespace std;
struct polar
{
	double r=0;
	double angle=0;
};
struct rect
{
	double x=0;
	double y=0;
};
polar polarFromRect(rect a)
{
	polar b;
	b.r = sqrt(a.x*a.x + a.y*a.y);
	b.angle = acos(a.x / b.r);
	return b;
}
rect rectFromPolar(polar a)
{
	rect b;
	b.x = a.r*cos(a.angle);
	b.y = a.r*sin(a.angle);
	return b;
}
void cin_Rect(rect &a)
{
	cin >> a.x;
	cin >> a.y;
}
void cin_Polar(polar &a)
{
	cin >> a.r;
	cin >> a.angle;
}
void cout_Rect(rect a)
{
	cout << "x  " << a.x << "  y  " << a.y << endl;
}
void cout_Polar(polar a)
{
	cout << "r  " << a.r << "  angle  " << a.angle << endl;
}
int main()
{
	rect a;
	polar b;
	int cnt;
	cin >> cnt;
	char * mas = new char[cnt];
	for(int j=0;j<cnt;j++)
	{
		cin >> mas[j];
	int n, m;
	if (mas[j] == 'r')
	{
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			cin_Rect(a);
			b = polarFromRect(a);
			cout_Polar(b);
		}
	}
	else
	{
		cin >> m;
		for (int p = 0;p < m;p++)
		{
			cin_Polar(b);
			a = rectFromPolar(b);
			cout_Rect(a);
		}
	}
	}
	system("pause");
	return 0;
}
/*int main()
{
	rect a;
	//a.x = 7;
	//a.y = 16;
	//cout_Rect(a);
	polar b;
	cin_Rect(a);
	cout_Rect(a);
	b = polarFromRect(a);
	cout_Polar(b);
	a = rectFromPolar(b);
	cout_Rect(a);
	system("pause");
	return 0;
}*/