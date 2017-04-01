#include "date.h"

#include <iostream>

using std::cout;
using std::endl;

bool is_leap(unsigned int year)
{
	bool is_candidate_leap = (year % 4 == 0);
	bool is_exception = ((year % 4 == 0) && (year % 100 == 0) && (year % 400 != 0));
	return is_candidate_leap && !is_exception;
}

unsigned int days_in_month(unsigned int month, unsigned int year)
{
	int days = 31;
	if (month == 4 || month == 6 || month == 9 || month == 11)
		days = 30;
	else if (month == 2)
		days = 28 + is_leap(year);
	return days;
}

bool is_invalid(unsigned int day, unsigned int month, unsigned int year)
{
	int max_allowed_day = days_in_month(month, year);
	bool invalid_day = (day < 1 || day > max_allowed_day);
	bool invalid_month = (month < 1 || month > 12);
	return invalid_day || invalid_month;
}

bool is_valid(unsigned int day, unsigned int month, unsigned int year)
{
	return !is_invalid(day, month, year);
}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	init(day, month, year);
}

Date::Date()
{

}
void Date::init(unsigned int day, unsigned int month, unsigned int year)
{

	if (is_invalid(day, month, year))
	{
		day = 1;
		month = 1;
		year = 1900;
	}

	_day = day;
	_month = month;
	_year = year;
}
unsigned int Date::get_day()
{
	return _day;
}

unsigned int Date::get_month()
{
	return _month;
}

unsigned int Date::get_year()
{
	return _year;
}

void Date::set_day(unsigned int day)
{
	if (is_valid(day, _month, _year))
	{
		_day = day;
	}
}

void Date::set_month(unsigned int month)
{
	if (is_valid(_day, month,_year))
	{
		_month = month;
	}
}

void Date::set_year(unsigned int year)
{
	if (is_valid(_day, _month, year))
	{
		_year = year;
	}
}

bool Date::operator<(Date second)
{
	if (_year < second._year)
		return true;
	if (_year > second._year)
		return false;
	if (_month < second._month)
		return true;
	if (_month > second._month)
		return false;
	if (_day < second._day)
		return true;
	return false;
}

bool Date::operator==(Date second)
{
	return _day == second._day &&
		_month == second._month &&
		_year == second._year;
}

bool Date::operator>(Date second)
{
	return !(*this<second) && !(*this==second);
}

void Date::add_years(unsigned int years)
{
	if (_month == 2 && _day == 29)
	{
		_month = 3;
		_day = 1;
	}
	_year += years;
}

void Date::add_months(unsigned int months)
{
	/*TODO Calculate better?*/
	while (months > 0)
	{
		--months;
		if (_month == 12)
		{
			_month = 1;
			add_years(1);
		}
		else
		{
			_month += 1;
		}
	}
}

void Date::add_days(unsigned int days)
{
	while (days > 0)
	{
		--days;
		if (_day == days_in_month(_month,_year))
		{
			add_months(1);
			_day = 1;
		}
		else
		{
			_day += 1;
		}
	}
}

void Date::print_date() const
{
	cout << _day << "." << _month << "." << _year << "   ";
}
