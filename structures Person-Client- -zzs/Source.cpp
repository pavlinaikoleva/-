#include<iostream>
using std::cout;
using std::cin;
using std::endl;
struct Person
{
	char firstName[50];
	char familyName[50];
};
struct Client
{
	Person ID;
	int numberCard;
	double balance;
};
Person cin_person()
{
	Person a;
	cin.getline(a.firstName, 50);
	cin.getline(a.familyName, 50);
	return a;
}
Client cin_client()
{
	Client a;
	a.ID = cin_person();
	cin >> a.numberCard;
	cin >> a.balance;
	cin.ignore();
	return a;
}
void cout_person(Person a)
{
	cout << "Person: " << a.firstName << "   " << a.familyName << endl;
}
void cout_client(Client a)
{
	cout_person(a.ID);
	cout << "info:  "<<a.numberCard << "   " << a.balance << endl;
}
void cin_arr(Client * arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		arr[i] = cin_client();
	}
}
void cout_arr(Client * arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout_client(arr[i]);
	}
}
double debt(Client *arr, int n)
{
	double sum=0;
	for (int i = 0;i < n;i++)
	{
		sum += arr[i].balance;
	}
	return sum;
}
int main()
{
	int n;
	cin >> n;
	Client * arr = new Client[n];
	cin.ignore();
	cin_arr(arr, n);
	cout_arr(arr, n);
	cout << debt(arr, n);
	delete[] arr;
	system("pause");
	return 0;
}