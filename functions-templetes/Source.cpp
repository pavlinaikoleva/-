#include<iostream>
#include<cmath>
using namespace std;
struct S
{
	int a;
	int b;
	int c;
};
void sort(S arr[], int n, bool(*compare)(S, S))
{
	int minIndex;
	for (int i = 0;i < n - 1;i++)
	{
		minIndex = i;
		for (int j = i + 1;j < n;j++)
		{
			if (compare(arr[j], arr[minIndex]))
				minIndex = j;
		}
		S tmp;
		tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}
S cin_S()
{
	S a;
	cin >> a.a;
	cin >> a.b;
	cin >> a.c;
	return a;
}
void cout_s(S a)
{
	cout << "struct: " << a.a << "  " << a.b << "  " << a.c << endl;
}
void cin_arrayOfStructures(S arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		arr[i] = cin_S();
	}
}
void cout_arrayOfStructures(S arr[], size_t n)
{
	for (int i = 0;i < n;i++)
	{
		cout_s(arr[i]);
	}
}
bool compareByA(S a, S b)
{
	return a.a < b.a;
}
bool compareByB(S a, S b)
{
	return a.b < b.b;
}
bool compareByAllFields(S a, S b)
{
	if (a.a != b.a) return a.a < b.a;
	else if (a.b != b.b) return a.b < b.b;
	else if (a.c != b.c) return a.c < b.c;
	else return 0;
}
template<typename T>
bool ordered(T *arr, int n)
{
	bool flag = true;
	for (int i = 0;i < n;i++)
	{
		for (int j = i+1;j < n&&flag;j++)
		{
			if (arr[i] >= arr[j]) flag = false;
		}
	}
	return flag;
}
template<typename T>
bool findElementInArray(T *arr, int n,T x,bool(*compare)(T,T))
{
	for (int i = 0;i < n;i++)
	{
			if (compare(arr[i],x)) return true;
	}
	return false;
}
template<typename T>
bool equal(T a, T b)
{
	return a == b;
}
template<typename T>
void cin_mas(T arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
}
template<typename T>
void cout_mas(T arr[], int n)
{
	for (int i = 0;i < n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
double korenkvadraten(double x)
{
	return sqrt(x);
}
double kvadrat(double x)
{
	return x*x;
}
double kub(double x)
{
	return x*x*x;
}
double opposite(double x)
{
	return -x;
}
double multiply(double x)
{
	return 2 * x;
}
double inc(double x)
{
	return x + 1;
}
double fmax(double(*f)(double), double(*g)(double), double x)
{
	if (f(x) > g(x)) return f(x);
	else return g(x);
}
double maxarray(double(*array[])(double), int n, double x)
{
	int max=0;
	for (int i = 1;i < n;i++)
	{
		if (array[i](x) > array[max](i))
			max = i;
	}
	return array[max](x);
}
double maxarray2(double(*array[])(double), int n, double x)
{
	double max = array[0](x);
	for (int i = 0;i < n;i++)
	{
		for (int j = i + 1;j < n;j++)
			if (fmax(array[i], array[j],x) > max) 
				max = fmax(array[i], array[j],x);
	}
	return max;
}
void map(double arr[], int n, double(*f)(double))
{
	for (int i = 0;i < n;i++)
	{
		arr[i] = f(arr[i]);
	}
}
int main()
{
	/*int arr[20];
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	int x;
	cin >> x;
	cout << findElementInArray(arr, n, x,equal) << endl;
	cout << ordered<int>(arr, n)<<endl;*/
	double(*functions[6])(double);
	functions[0] = kvadrat;
	functions[1] = korenkvadraten;
	functions[4] = kub;
	functions[3] = opposite;
	functions[2] = multiply;
	functions[5] = inc;
	int n;
	cin >> n;
	/*double x;
	cin >> x;
	double res;
	int index=0;
	for (int i = 0;i < n;i++)
	{
		cout << functions[i](x) << endl;
	}
	cout << "indeksa:";
	for (int i = 1;i < n;i++)
	{
		if (functions[i](x) > functions[index](x))
			index = i;
	}*/
	//cout << index << endl;
	//cout << fmax(kvadrat, kub, x) << endl;
	//cout << maxarray2(functions, n, x)<<endl;
	/*double *arr = new double[n];
	cin_mas<double>(arr, n);
	map(arr, n, kvadrat);
	cout_mas<double>(arr, n);
	delete[] arr;*/
	S * mas = new S[n];
	cin_arrayOfStructures(mas, n);
	sort(mas, n, compareByAllFields);
	cout_arrayOfStructures(mas, n);
	delete[] mas;
	system("pause");
	return 0;
}