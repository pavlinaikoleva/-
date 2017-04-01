#ifndef __DATE_H__
#define __DATE_H__
class Date
{private:
	unsigned int _month;
	unsigned int _day;
	unsigned int _year;
public:
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date();
	void init(unsigned int day, unsigned int month, unsigned int year);
	unsigned int get_day();
	unsigned int get_month();
	unsigned int get_year();

	void set_day(unsigned int day);
	void set_month(unsigned int month);
	void set_year(unsigned int year);

	bool operator<(Date second);
	bool operator>(Date second);
	bool operator==(Date second);

	void add_days(unsigned int days);
	void add_months(unsigned int months);
	void add_years(unsigned int years);

	void print_date()const;
};

#endif
