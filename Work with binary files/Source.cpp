#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;
struct Product
{
	char description[32];
	//описание на изделие
	int partNum;
	//номер на изделие
	double cost;
	//цена на изделие
}a,b;
void cin_Products(Product *arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cin.getline(arr[i].description, 31);
		cin >> arr[i].partNum;
		cin >> arr[i].cost;
		cin.ignore();
	}
}
void readProductsFromFile(Product *arr, int n,ifstream& in)
{
	for (int i = 0;i < n;i++)
	{
		in.getline(arr[i].description, 31);
		in >> arr[i].partNum;
		in >> arr[i].cost;
		in.ignore();
	}
}
void setelements(Product *arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		strcpy(arr[i].description, "");
		arr[i].partNum = 0;
		arr[i].cost = 0;
	}
}
void cout_Products(Product *arr, int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i].description <<endl
			<< arr[i].partNum <<endl
			<<fixed<<setprecision(2)<<arr[i].cost << endl;
	}
}
void write_ProductsInFile(Product *arr, int n, ostream& out)
{
	for (int i = 0;i < n;i++)
	{
		out<< arr[i].description << endl
			<< arr[i].partNum << endl
			<< fixed << setprecision(2) << arr[i].cost << endl;
	}
}
int main()
{
	/*cin.getline(a.description, 31);
	cin >> a.partNum;
	cin >> a.cost;
	cin.ignore();
	cin.getline(b.description, 31);
	cin >> b.partNum;
	cin >> b.cost;
	cout << "parvi product" << a.description << "  " << a.partNum << "   " << a.cost << endl;
	cout << "vtori product" << b.description << "  " << b.partNum << "   " << b.cost << endl;*/
	Product arr[5];
	Product arr2[5];
	setelements(arr2, 5);
	//cin_Products(arr, 5);
	//ofstream out;
	ifstream in;
	//in.open("myfile.txt");
	//readProductsFromFile(arr2, 5, in);
	//write_ProductsInFile(arr, 5, out);
	//out << "plase continious..." << endl;
	//out.open("mytext.bin", ios::binary | ios::app);
	//out.write((char*)& arr, 5 * sizeof(Product));
	cout_Products(arr2, 5);
	in.open("mytext.bin", ios::binary);
	in.read((char*)& arr2, 5 * sizeof(Product));
	//cout_Products(arr, 5);
	cout_Products(arr2, 5);
	system("pause");
	return 0;
}