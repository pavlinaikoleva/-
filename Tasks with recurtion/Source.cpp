#include <iostream>
using namespace std;

void insertSorted(long x, long arr[], int n)
{
	arr[n] = x;
	if (arr[n - 1] <= arr[n]) return;
	else {
		swap(arr[n - 1], arr[n]);
		insertSorted(x, arr, n - 1);
	}
}
void reversed(long arr[], int n)
{
	if (n < 1) return;
	cout << arr[n - 1]<<" ";
	reversed(arr, n - 1);
}
int main(){
	int n;
	cin >> n;
	//int x;
	//cin >> x;
	long arr[25];
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	/*insertSorted(x, arr, n);
	for (int i = 0;i < n + 1;i++)
	{
		cout << arr[i] << "  ";
	}*/
	reversed(arr, n);
	system("pause");
	return 0;
}