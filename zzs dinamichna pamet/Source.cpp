#include<iostream>
#include<cstring>
using namespace std;
char * strdublicate(const char * str) //zad1
{
	int len = strlen(str);
	char * s = new char[len + 1];
	int i;
	for (i = 0;i < len;i++)
	{
		s[i] = str[i];
	}
	s[i] = '\0';
	return s;
}
/*char * stringOfNumber(int n)//зад2
{
	int i = 0;
	int res = n;
	while (n)
	{
		i++;
		n /= 10;
	}
	char *str = new char[i+1];
	int j = i-1;
	while (res)
	{
		str[j] =(res % 10)+48;
		res /= 10;
		j--;
	}
	str[i] = '\0';
	return str;
}*/
/*char * unionstrings(const char * str1, const char * str2) //zad3
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char *p = new char[len1 + len2 + 1];
	p[0] = str1[0];
		int i = 1;
	for (int j = 0;j < len1;j++)
	{
		bool add = true;
		for (int q = 0;q < i&&add;q++)
		{
			if (str1[j] == p[q]) add = false;
		}
				if (add) 
				{
						p[i] = str1[j];
						i++;
				}
	}
	for (int j = 0;j < len2;j++)
	{
		bool add = true;
		for (int q = 0;q < i&&add;q++)
		{
			if (str2[j] == p[q]) add = false;
		}
		if (add)
		{
			p[i] = str2[j];
			i++;
		}
	}
	p[i] = '\0';
	return p;
}*/
char car(const char* x)
{
	return x[0];
}
char* cdr(char *x)
{
	return (x + 1);
}
char * consStrtoX(char x, const char * str)
{
	int len = strlen(str);
	char *p = new char[len + 2];
	p[0] = x;
	int i;
	for (i = 0;i < len;i++)
	{
		p[i+1] = str[i];
	}
	p[i + 1] = '\0';
	return p;
}
char * consXtoStr(char x,const char * str)
{
	int len = strlen(str);
	char *p = new char[len + 2];
	int i;
	for (i = 0;i < len;i++)
	{
		p[i] = str[i];
	}
	p[i++] = x;
	p[i] = '\0';
	return p;
}
bool eq(const char *str1, const char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if (len1 != len2) return false;
	bool flag = true;
	for (int i = 0;i < len1&&flag;i++)
	{
		if (str1[i] != str2[i]) flag = false;
	}
	return flag;

}
char * reverse(char *x) //raboti moje da prichinqva memory leak
{
	int len = strlen(x);
	char y;
	char *p=&y;
	*p=car(x);
	x = cdr(x);
	for (int i = 0;i < len-1 ;i++)
	{
		p = consStrtoX(car(x), p);
		x = cdr(x);
	}
	p[len] = '\0';
	return p;
}
char * car_n(char *x, int n)
{
	char temp;
	char * p=&temp;
	*p = car(x);
	x = cdr(x);
	for(int i=0;i<n-1;i++)
	{
		p = consXtoStr(car(x), p);
		x = cdr(x);
	}
	p[n] = '\0';
	return p;
}
char * car_n3(char *x, int n)
{

	char * p = "";
	for (int i = 0;i<n;i++)
	{
		p = consXtoStr(car(x), p);
		x = cdr(x);
	}
	p[n] = '\0';
	return p;
}
char * car_n2(char *x, int n)
{
	char * stringFirstn = new char[n + 1];
	int i;
	for (i = 0;i < n;i++)
	{
		stringFirstn[i] = x[i];
	}
	stringFirstn[i] = '\0';
	return stringFirstn;

}
char *cdr_n(char * x, int n)
{
	if (n == 0) return x;
	char * p=cdr(x);
	if (n == 1) return p;
	for (int i = 0;i < n-1;i++)
	{
		p = cdr(p);
	}
	return p;
}
int number_of_char(char *str, char x)
{
	int cnt = 0;
	char p;
	while(*str)
	{ p = car(str);
		if (p == x) { cnt++; }
		str = cdr(str);
	}
	return cnt;
}
int number_of_substr(char *x, char *y)
{
	int cnt = 0;
	int leny = strlen(y);
	char * help=car_n2(x, leny);
	while (*x)
	{
		help = car_n2(x, leny);
		if (eq(y,help)) { cnt++; }
		x = cdr(x);
	}
	delete help;
	return cnt;
}
char * delete_substr(char *x, char *y)//substr da ne e v nachaloto na x
{
	int leny = strlen(y);
	char * help = car_n2(x, leny);
	cout << "debug help parvi pat" << help << endl;
	char w;
	char *p = new char;
	*p = x[0];
	*(p + 1) = '\0';
		cout << p << endl;
		x = cdr(x);
		while (*x)
		{
			help = car_n2(x, leny);
			if (eq(y, help))
			{
				for (int i = 0;i < leny;i++)
				{
					x = cdr(x);
				}
			}
			else 
			{
				char q = *x;
				cout << "kakvo e *x   " << q << endl;
				p = consXtoStr(q, p);
				cout << "kakvo ima v p   " << p << endl;
				x = cdr(x);
			}
		}
	delete help;
	return p;
}
char * delete_substr2(char *x, char *y)
{
	int leny = strlen(y);
	char * help = car_n2(x, leny);
	cout << "debug help parvi pat" << help << endl;
	char w;
	//char *p = new char[strlen(x)];
	//*p = '*';
	//*(p + 1) = '\0';
	char* p = "";
	cout << p << endl;
	while (*x)
	{
		help = car_n2(x, leny);
		if (eq(y, help))
		{
			for (int i = 0;i < leny;i++)
			{
				x = cdr(x);
			}
		}
		else
		{
			char q = *x;
			cout << "kakvo e *x   " << q << endl;
			p = consXtoStr(q, p);
			cout << "kakvo ima v p   " << p << endl;
			x = cdr(x);
		}
	}
	delete help;
	//p=cdr(p); ne stava-->error
	return p;
}
int main()
{
	char str1[100], str2[100];
	cin.getline(str1, 99);
	int n;
	cin >> n;
	//cin.getline(str2, 99);
	char *p = car_n3(str1,n);
	cout << p << endl;
	delete p;
	//char *q = reverse(str1);
	//cout << q << endl;
	//delete q;
	//char * pointer = delete_substr2(str1, str2);
	//cout <<"otg  "<<pointer<< endl;
	//delete pointer;
	system("pause");
	return 0;
}