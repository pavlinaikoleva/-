#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
struct Point
{
	double x;
	double y;
};
class Line
{
	Point A;
	Point B;
	public:
	void initialize()
	{
		cout << "enter point A:  ";
		cin >> A.x >> A.y;
		cout << "enter point B: ";
		cin >> B.x >> B.y;
	}
	bool aretheseLinesParalel(Line other)
	{
		double slope1,slope2;
		slope1 = B.y - A.y / B.x - A.x;
		slope2 = other.B.y - other.A.y / other.B.x - other.A.x;
		return slope1 == slope2;
	}
	bool isPointOnLine(Point p)
	{
		double slope;
		slope= B.y - A.y / B.x - A.x;
		double free;
		free = (B.x*A.y - A.x*B.y) / B.x - A.x;
		double u;
		return (p.y == free*p.x + free);
	}
	Point CrossPoint(Line other)
	{
		Point result;
		double slope1, slope2;
		slope1 = B.y - A.y / B.x - A.x;
		slope2 = other.B.y - other.A.y / other.B.x - other.A.x;
		double free1,free2;
		free1 = (B.x*A.y - A.x*B.y) / B.x - A.x;
		free2= (other.B.x*other.A.y - other.A.x*other.B.y) / other.B.x - other.A.x;
		result.x = (free2 - free1) / slope1 - slope2;
		result.y = slope1*result.x + free1;
		return result;
	}
	Line findBisector(Line other)
	{
		double slope1, slope2;
		slope1 = B.y - A.y / B.x - A.x;
		slope2 = other.B.y - other.A.y / other.B.x - other.A.x;
		double tg;
		tg = (slope2 - slope1) / (1 + slope1*slope2);
		if (tg > 0) tg = -tg;
		double angle;
		angle = atan(tg);
		
	}
};
int main()
{

}