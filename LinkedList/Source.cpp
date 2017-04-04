#include <iostream>
using namespace std;
template<typename T>
class LinkedList
{
private:
	// box е вложен клас и тъй като е private, извън класа НЕ МОЖЕМ да създаваме и работим с кутийки
	// => това е капсулация + абстракция. Само списъкът знае как е организиран, ние получаваме
	// различни непрозрачни методи за работи с него - push, pop, insert, front и т.н.
	struct box
	{
		T data;
		box* next;

		box(T _d, box* _p = nullptr) : data(_d), next(_p) {}
	};

	// достатъчен е само указател към първата кутийка - другото е за улеснение и скорост
	box* first;
	// box* last; // добавете и указател към последната кутийка и променете които методи трябва
	int _size;

	void copyFrom(const LinkedList& other)
	{
		// ВНИМАНИЕ: много бавна операция (т.к. push_back) всеки път търси края на списъка!!!
		// никога не е било казано, че във for можем да ползваме само int-ове...
		for (box* ptr = other.first; ptr != nullptr; ptr = ptr->next)
			push_back(ptr->data);
	}
	void clearEverything()
	{
		while (!empty())
			pop();
		// след това first == nullptr, и няма нужда да се грижим за това
	}
public:
	// стандартни
	LinkedList() : first(nullptr), _size(0) {}
	// Делегиране на конструктори: първо ще се изпълни дефолтния, т.е. списъкът
	// ще се инициализира по валиден начин, след което ще се изпълни тялото.
	LinkedList(T x, T y) :LinkedList() 
	{
		first = new box(x, nullptr);
		box * tmp = first;
		for (T i = x;i < y;i++)
		{
			tmp->next = new box(i + 1, nullptr);
			tmp = tmp->next;
		}
		_size = y - x + 1;
	}
	LinkedList(const LinkedList& other) : LinkedList() { copyFrom(other); }
	LinkedList& operator=(const LinkedList& other)
	{
		if (this != &other)
		{
			clearEverything();
			copyFrom(other);
		}
		return *this;
	}
	~LinkedList()
	{
		clearEverything();
	}

	// Стандартни за списъците, вмъкване и премахване от началото.
	void push(T x)
	{
		box* newbox = new box(x, first);
		first = newbox;
		++_size;
	}
	// Не работи за празен списък (undefined behaviour) - или трябва
	// изрично да го споменем, или да се справим по друг начин (exception, return...)
	void pop()
	{
		box* tmp = first;
		first = first->next;
		delete tmp;
		--_size;
	}

	// Ако списъкът е празен, pos може да е произволна и ще работи
	// Ако списъкът е непразен, трябва pos <= size() - иначе undefined behaviour :(
	void insertAt(int x, int pos)
	{

		if (empty() || pos == 0)
		{
			push(x);
			return;
		}
		box* tmp = first;
		while (pos > 1)
		{
			--pos;
			tmp = tmp->next;
		}
		tmp->next = new box(x, tmp->next);
		++_size;
	}
	// Трябва pos да е валиден индекс, т.е. pos < size()
	void removeAt(int pos)
	{
		if (pos == 0)
		{
			pop();
			return;
		}
		box* tmp = first;
		while (pos > 1)
		{
			--pos;
			tmp = tmp->next;
		}
		box* toRemove = tmp->next;
		tmp->next = toRemove->next; // tmp->next->next
		delete toRemove;
		--_size;
	}
	// Важно - т.к. имаме само указател къ,м първата кутийка, това е супер бавно!
	// Ще става много по-бързо и лесно, ако пазихме и указател към последната кутийка.
	void push_back(int x)
	{
		insertAt(x, size());
	}

	// по-добре да се казва get или at, а не operator[], понеже е бавна операция!
	// Позициите се броят от нула.
	T& operator[](int idx)
	{
		box* tmp = first;
		while (idx)
		{
			--idx;
			tmp = tmp->next;
		}
		return tmp->data;
	}

	// Стандартни
	bool empty() const
	{
		return (first == nullptr);
		// return !first;
	}
	int size() const { return _size; }
	// Достъп до първия елемент (главата) на списъка
	T front() const { return first->data; }
	// Обхождане на целия списък
	void print() const
	{
		box* curr = first;
		while (curr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
		cout << "\n";
	}
	int count(T x);
	void removeAll(T x)
	{
		while (first!=nullptr&&first->data == x)
		{
			box *tmp = first;
			first = first->next;
			delete tmp;
		}
		if (first == nullptr) return;
		box *tmp = first;
		while (tmp!=nullptr)
		{
			while (tmp->next != nullptr&&tmp->next->data == x)//
			{
				box * ToRemove = tmp->next;
				tmp->next = ToRemove->next;
				delete ToRemove;
				cout << "vtoriq while sprq" << endl;
			}
			tmp = tmp->next;
		}
	}
	LinkedList& append(const LinkedList& other)
	{
		box * tmp = first;
		if (tmp)
		{
			while (tmp->next)
			{
				tmp = tmp->next;
			}
			box * p2 = other.first;
			while (p2)
			{
				tmp->next = new box(p2->data, nullptr);
				tmp = tmp->next;
				p2 = p2->next;
			}
		}
		else {
			box * p2 = other.first;
			first = new box(p2->data, nullptr);
			box * tmp =first;
			p2 = p2->next;
			while (p2)
			{
				tmp->next = new box(p2->data, nullptr);
				tmp = tmp->next;
				p2 = p2->next;
			}
		}
		return *this;
	}
	LinkedList& operator+=(const LinkedList& other)
	{
		return (*this).append(other);
	}
	LinkedList concat(const LinkedList& other)
	{
		LinkedList res;
		box * tmp = first;
		if (tmp != nullptr)
		{
			res.first = new box(tmp->data, nullptr);
			box * pointerRes = res.first;
			tmp = tmp->next;
			while (tmp)
			{
				pointerRes->next = new box(tmp->data, nullptr);
				pointerRes = pointerRes->next;
				tmp = tmp->next;
			}
			box * p2 = other.first;
			while (p2)
			{
				pointerRes->next = new box(p2->data, nullptr);
				pointerRes = pointerRes->next;
				p2 = p2->next;
			}
		}
		else {
			box * p2 = other.first;
			res.first = new box(p2->data, nullptr);
			box * pointerRes = res.first;
			p2 = p2->next;
			while (p2)
			{
				pointerRes->next = new box(p2->data, nullptr);
				pointerRes = pointerRes->next;
				p2 = p2->next;
			}
		}
		return res;
	}
	LinkedList operator+(const LinkedList& other)
	{
		return (*this).concat(other);
	}
	void map()
	{
		box * tmp = first;
		while (tmp)
		{
			tmp->data *= 2;
			tmp = tmp->next;
		}
	}
	void reverse()
	{
		T* datamas=new T[_size];
		box * tmp = first;
		int i = 0;
		while (tmp)
		{
			datamas[i++] = tmp->data;
			tmp = tmp->next;
		}
		box * tmp2 = first;
		while (tmp2)
		{
			tmp2->data = datamas[--i];
			tmp2 = tmp2->next;
		}
	}
};
template<typename T>
int LinkedList<T>::count(T x)
{
	box * tmp = first;
	unsigned int cnt = 0;
	while (tmp!= nullptr)
	{
		if (tmp->data == x)
		{
			cnt++;
		}
		tmp = tmp->next;
	}
	return cnt;
}
int main()
{
	LinkedList<int> lst;
	lst.push_back(3);     // {3}
	lst.push(2);  
	lst.push(2);// {2,3}
	lst.push_back(4);    // {2,3,10}
	lst.insertAt(2, 3);// {20,2,3,10}, аналогично на push(20)
	lst.push_back(2);
	lst.push_back(8);
	lst.push_back(2);
	lst.insertAt(2, 4);
	lst.print();
	lst.reverse();
	lst.print();
	cout << lst.count(2) << endl;
	//lst.pop();
	lst.removeAll(2);
	lst.print();
	LinkedList<int> lst2;
	lst2.push(12);
	lst2.push(10);
	lst2.push(5);
	lst2.push(1);
	lst2.print();
	//lst.concat(lst2).print();
	LinkedList<int> lst3 = lst + lst2;
	lst3.print();
	lst.print();
	//lst.append(lst2);
	lst += lst2;
	lst.print();
	lst2.push(7);
	lst2.print();
	lst.print();
	lst.map();
	lst.print();
	
	system("pause");
	return 0;
}