#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
class BankAcount
{
	char client[51];
	char numberBA[21];
	double money;
public:
	void initialize()
	{
		cout << "enter name of client: ";
		cin.getline(client, 51);
		cin.getline(numberBA, 21);
		cin >> money;
		cin.ignore();
	}
	void print()
	{
		cout << "Information for Bank Acount: "
			<< client << "   " << numberBA << "   " << money << endl;
	}
	double payInMoney(double pay)
	{
		money += pay;
		return money;
	}
	double drawMoney(double draw)
	{
		money -= draw;
		return money;
	}
	int operator < (BankAcount other)
	{
		if (money < other.money)
			return 1;
		else {
			if (money == other.money) return 0;
			else return-1;
		}
	}
	BankAcount operator >(BankAcount other)
	{
		if (money > other.money)
			return *this;
		else return other;
	}
};
using namespace std;
int main()
{
	BankAcount a;
	BankAcount b;
	a.initialize();
	b.initialize();
	a.print();
	b.print();
	a.payInMoney(50.30);
	a.print();
	b.drawMoney(40.80);
	b.print();
	cout << (a < b) << endl;
	(a > b).print();
	system("pause");
	return 0;
}