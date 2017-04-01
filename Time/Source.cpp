#include<iostream>
using std::cin;
using std::cout;
using std::endl;
class Time
{
	unsigned short hour;
	unsigned short minutes;
public:
	unsigned short getHour()const
	{
		return hour;
	}
	unsigned short getMinutes() const
	{
		return minutes;
	}
	void printTime()
	{
		if (hour >= 0 && hour <= 9) {
			if (minutes >= 0 && minutes <= 9)
				cout << "The time is:  " << 0 << hour << ":" <<0<< minutes << endl;
			else cout << "The time is:  " << 0 << hour << ":" << minutes << endl;
		}
		else
		{
			if (minutes >= 0 && minutes <= 9)
				cout << "The time is:  " << hour << ":" << 0 << minutes << endl;
			else cout << "The time is:  " << hour << ":" << minutes << endl;
		}
	}
	void setHour()
	{
		unsigned short newhour;
		do
		{
			cout << "Enter new hour:";
			cin >> newhour;
		} while (newhour < 0 || newhour > 23);
		hour = newhour;
	}
	void setHour(unsigned short newHour)
	{
		hour = newHour;
	}
	void setMinutes()
	{
		unsigned short newMinutes;
			do {
				cout << "Enter new minutes: ";
				cin >> newMinutes;
			} while (newMinutes < 0 || newMinutes>60);
			minutes = newMinutes;
	}
	void setMinutes(unsigned short newMinutes)
	{
		minutes = newMinutes;
	}
	void setTime()
	{
		int newMinutes, newHour;
		do {
			cout << "Enter time at the moment: ";
			cin >> newHour;
			cin >> newMinutes;
		} while (newHour < 0 || newHour > 23 || newMinutes < 0 || newMinutes>60);
		hour = newHour;
		minutes = newMinutes;
	}
	void addMinutes(unsigned short addMinutes)
	{
		minutes += addMinutes;
		unsigned short q;
		q = minutes / 60;
		minutes = minutes - (60 * q);
		//minutes%=60;
		hour += q;
		if (hour > 23) hour %= 23;
	}
	int countMinutesFromNewDay()
	{
		return hour * 60 + minutes;
	}
	bool operator <(Time other)
	{
		if (hour < other.hour) return true;
		else {
			if (hour > other.hour) return false;
			else return minutes < other.minutes;
		}
	}
	Time operator +(Time other)
		{
			Time c;
			c.hour = hour + other.hour;
			c.minutes = minutes + other.minutes;
			unsigned short q;
			q = c.minutes / 60;
			c.minutes%=60;
			c.hour += q;
			if (c.hour > 23) c.hour %= 23;
			return c;
		}
	Time operator -(Time other)
	{
		Time c;
		if (*this < other)//ot other vadim this togava
		{
			if (other.minutes - minutes >= 0)
			{
				c.minutes = other.minutes - minutes;
				c.hour = other.hour - hour;
			}
			else {
				c.hour = other.hour - 1 - hour;
				c.minutes = other.minutes + 60 - minutes;
			}
		}
		else {
			if (minutes - other.minutes >= 0)
			{
				c.minutes = minutes - other.minutes;
				c.hour = hour - other.hour;
			}
			else {
				c.hour = hour - 1 - other.hour;
				c.minutes = minutes + 60 - other.minutes;
			}
		}
		return c;
	}
		Time operator*(int vreme)
		{
			Time c;
			c.minutes = minutes*vreme;
			c.hour = hour*vreme;
			unsigned short q;
			q = c.minutes / 60;
			c.minutes %= 60;
			c.hour += q;
			if (c.hour > 23) c.hour %= 23;
			return c;
		}
};
Time operator *(unsigned short vreme, Time a)
{
	Time c;
	c.setMinutes(a.getMinutes()*vreme);
	c.setHour(a.getHour()*vreme);
	unsigned short q;
	q = c.getMinutes() / 60;
	c.setMinutes (c.getMinutes()%60);
	c.setHour(c.getHour()+q);
	if (c.getHour() > 23) c.setHour(c.getHour()%23);
	return c;
}
int main()
{
	Time a,b;
	a.setTime();
	b.setTime();
	a.printTime();
	b.printTime();
	(a*3).printTime();
	(3*a).printTime();
	system("pause");
	return 0;
}