#include<iostream>
using std::cin;
using std::cout;
using std::endl;
class NumberSummator
{private:
	int summator;
	int startsummator;
	int n;
public:
	NumberSummator(int null_val = 0)
	{
		summator = null_val;
		startsummator = null_val;
		n = 0;
	}
	int sum()
	{
		n++;
		return summator;
	}
	void add(int num)
	{
		n++;
		summator += num;
	}
	void sub(int num)
	{
		n++;
		summator -= num;
	}
	int num()
	{
		return n;
	}
	double average()
	{
		return (summator-startsummator) / n;
	}
};
int main()
{
	NumberSummator seq1(10);
	seq1.add(10);
	seq1.add(5);
	seq1.sub(15);
	cout << seq1.sum()<<endl;
	cout << seq1.average()<<endl;
	system("pause");
	return 0;
}