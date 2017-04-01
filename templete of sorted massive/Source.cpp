#include<iostream>
#include <assert.h>
using std::cin;
using std::cout;
using std::endl;
template <typename T>
class Sorted
{
private:
	T* arr;
	size_t size;
	public:
		Sorted()
		{
			arr = new T[1];
			size = 1;
		}
		void add(const T& elem)
		{
			if (elem <= arr[0])// trqbva da stane prav
			{
				T* newarray = new T[size + 1];
				newarray[0] = elem;
				for (size_t i = 1;i <= size;i++)
				{
					newarray[i] = arr[i - 1];
				}
				delete[] arr;
				arr = newarray;
				size++;
				return;
			}
			if (elem >= arr[size - 1])//moje da e v else problem pri masiv ot edni i sashti chisla sigurno 
			{
				T* newarray = new T[size + 1];
				for (size_t i = 0;i < size;i++)
				{
					newarray[i] = arr[i];
				}
				newarray[size] = elem;
				delete[] arr;
				arr = newarray;
				size++;
				return;
			}
			for (size_t i = 0;i < size - 1;i++)
			{
				if (arr[i] <= elem&&elem <= arr[i + 1])
				{
					cout << "vlizam v proverkata" << endl;
					T* newarray = new T[size + 1];
					for (size_t j = 0;j <= i;j++)
					{
						newarray[j] = arr[j];
					}
					newarray[i + 1] = elem;
					for (size_t j = i+2;j <= size;j++)
					{
						newarray[j] = arr[j-1];
					}
					size++;
					delete[] arr;
					arr = newarray;
					return;
				}
			}
		}
		T& operator[](size_t index)
		{
			assert(index >= 0 && index < size);
			return arr[index];
		}
		void remove(const T& elem)
		{
			for (size_t i = 0;i < size;i++)
			{
				if (arr[i] == elem)
				{
					T* newarray = new T[size - 1];
					for (size_t j = 0;j < i;j++)
					{
						newarray[j] = arr[j];
					}
					for (size_t j = i + 1;j < size;j++)
					{
						newarray[j - 1] = arr[j];
					}
					size--;
					i--;
					//cout<<size<< endl;
					delete[] arr;
					arr = newarray;
				}
			}
		}
		void print()
		{
			for (size_t i = 0;i < size;i++)
			{
				cout << arr[i] << endl;
			}
		}
};
int main()
{
	Sorted<int> a;
	a[0] = 2;
	a.add(1);
	a.add(4);
	a.print();
	a.add(3);
	a.print();
	a.add(2);
	a.add(2);
	a.print();
	a.remove(3);
	cout << "sled iztrivane" << endl;
	a.print();
	a.remove(2);
	cout << "sled iztrivane" << endl;
	a.print();
	system("pause");
	return 0;
}