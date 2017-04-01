#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
struct word_Description
{
	char word[100];
	char description[500];
};
class Dictionary
{
private:
	word_Description* rechnik;
	size_t currentSizeWords;
	size_t capacity;
public:
	Dictionary()
	{
		initializeDictionary();
	}
	void initializeDictionary()
	{
		rechnik = new word_Description[1];
		currentSizeWords =0;
		capacity =1;
	}
	Dictionary(size_t n)
	{
		rechnik = new word_Description[n];
		currentSizeWords = 0;
		capacity = n;
	}
	Dictionary(const Dictionary& other)
	{
		rechnik = new word_Description[other.capacity];
		for (size_t i = 0;i < other.currentSizeWords;i++)
		{
			rechnik[i] = other.rechnik[i];
		}
		capacity = other.capacity;
		currentSizeWords = other.currentSizeWords;
	}
	Dictionary& operator=(const Dictionary& other)
	{
		if (this != &other)
		{
			delete rechnik;
			rechnik = new word_Description[other.capacity];
			for (size_t i = 0;i < other.currentSizeWords;i++)
			{
				rechnik[i] = other.rechnik[i];
			}
			capacity = other.capacity;
			currentSizeWords = other.currentSizeWords;
		}
		return *this;
	}
	int getSize() const
	{
		return currentSizeWords;
	}
	const word_Description * getRechnik() const
	{
		return rechnik;
	}
	void showDictionary()
	{
		for (size_t i = 0;i < currentSizeWords;i++)
		{
			cout << "Word " << i + 1 << "  " << rechnik[i].word << "     meaning    " << rechnik[i].description << endl;
		}
	}
	void resize()
	{
		cout << "create bigger buffer" << endl;
		word_Description * newBuffer = new word_Description[2 * capacity];
		for (size_t i = 0;i < currentSizeWords;i++)
		{
			newBuffer[i] = rechnik[i];
		}
		capacity *= 2;
		delete[] rechnik;
		rechnik = newBuffer;
	}
	void addNewWord()
	{
		if (currentSizeWords >= capacity)
		{
			resize();
		}
			word_Description newWord;
			cout << "enter new word  ";
			cin.getline(newWord.word, 100);
			cout << "enter the desctiption of the new word  ";
			cin.getline(newWord.description, 500);
			rechnik[currentSizeWords++] = newWord;
	}
	void deleteWord()
	{
		char nameOfWordToRemove[100];
		cin.getline(nameOfWordToRemove, 100);
		for (size_t i = 0;i < currentSizeWords;i++)
		{
			if (!strcmp(nameOfWordToRemove, rechnik[i].word))
			{
				for (size_t j = i + 1;j < currentSizeWords;j++)
				{
					rechnik[j - 1] = rechnik[j];
				}
				currentSizeWords--;
			}
		}
	}
	void searchMeaningOfWord()
	{
		char nameOfWordToSearch[100];
		cin.getline(nameOfWordToSearch, 100);
		for (size_t i = 0;i < currentSizeWords;i++)
		{
			if (!strcmp(nameOfWordToSearch, rechnik[i].word))
				cout << rechnik[i].description << endl;
		}
	}
	void sortDictionary()
	{
		bool swapped = true;
		size_t j = 0;
		word_Description temp;
		while (swapped)
		{
			swapped = false;
			j++;
			for (size_t i = 0;i < currentSizeWords - j;i++)
			{
				if (strcmp(rechnik[i].word, rechnik[i + 1].word) == 1)
				{
					temp = rechnik[i];
					rechnik[i] = rechnik[i + 1];
					rechnik[i + 1] = temp;
					swapped = true;
				}
			}
		}
	}
	Dictionary operator + (const Dictionary& other)
	{
		Dictionary c(currentSizeWords + other.currentSizeWords);//poneje se namiram v klasa moga direktno da dostapvam elementite i na c ne s get funkcii
		c.capacity = currentSizeWords + other.currentSizeWords;
		size_t i;
		for (i = 0;i <currentSizeWords;i++)
		{
			c.rechnik[i] = rechnik[i];
		}
		c.currentSizeWords = i;
		for (size_t j = 0;j < other.currentSizeWords;j++)
		{
			bool flag = true;
			for (size_t p = 0;(p < c.currentSizeWords) && flag;p++)
			{
				if (strcmp(c.rechnik[p].word, other.rechnik[j].word) == 0)
				{
					flag = false;
				}
			}
			if (flag)
			{
				c.rechnik[i++] = other.rechnik[j];
				c.currentSizeWords = i;
			}
		}
		return c;
	}
	Dictionary& operator+=(const Dictionary& other)
	{
		word_Description * newArray = new word_Description[currentSizeWords + other.currentSizeWords];
		capacity= currentSizeWords + other.currentSizeWords;
		size_t i;
		for (i = 0;i <currentSizeWords;i++)
		{
			newArray[i] = rechnik[i];
		}
		for (size_t j = 0;j < other.currentSizeWords;j++)
		{
			bool flag = true;
			for (size_t p = 0;(p < currentSizeWords) && flag;p++)
			{
				if (strcmp(newArray[p].word, other.rechnik[j].word) == 0)
				{
					flag = false;
				}
			}
			if (flag)
			{
				newArray[i++] = other.rechnik[j];
				currentSizeWords = i;
			}
		}
		delete rechnik;
		rechnik = newArray;
		return *this;
	}
	~Dictionary()
	{
		delete rechnik;
	}
};
int main()
{
	int n, m;
	cout << "how many words is going to have dictionary one at the beginning  ";
	cin >> n;
	cout << "how many words is going to have dictionary one at the beginning  ";
	cin >> m;
	Dictionary a, b;
	cin.ignore();
	for (int i = 0;i < n;i++)
	{
		a.addNewWord();
	}
	cout << "enter rechnik b:  " << endl;
	for (int i = 0;i < m;i++)
	{
		b.addNewWord();
	}
	cout << a.getSize() << endl;
	cout << b.getSize() << endl;
	cout << "dictionary 1  " << endl;
	a.showDictionary();
	cout << "dictionaty 2" << endl;
	b.showDictionary();
	/*a.addNewWord();
	cout << "dictionary 1  " << endl;
	a.showDictionary();
	a.deleteWord();
	cout << "dictionary 1  " << endl;
	a.showDictionary();
	a.searchMeaningOfWord();*/
	cout << "sboren rechnik" << endl;
	//word_Description * temp; ne moga da go podam kato parametar na + zashtoto e binarna operaciq
	Dictionary p(b);
	p.deleteWord();
	b.showDictionary();
	system("pause");
	return 0;
}