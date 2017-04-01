/*#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
const int MAX_COUNT_WORD=4;
struct word_Description
{
	char word[100];
	char description[500];
};
class Dictionary
{
private:
	word_Description rechnik[MAX_COUNT_WORD];
	int currentSizeWords;
public:
	void initializeDictionary()
	{
		currentSizeWords = 0;
		for (int i = 0;i < MAX_COUNT_WORD;i++)
		{
			strcpy(rechnik[i].word, "");
			strcpy(rechnik[i].description, "");
		}
	}
	int getSize()
	{
		return currentSizeWords;
	}
	void showDictionary()
	{
		for (int i = 0;i < currentSizeWords;i++)
		{
			cout << "Word " << i + 1 <<"  "<< rechnik[i].word << "     meaning    " << rechnik[i].description << endl;
		}
	}
	void addNewWord()
	{
		if (currentSizeWords >= 501) cout << "We can not add new word there are too many words in this dictionary";
		else {
			word_Description newWord;
			cout << "enter new word  ";
			cin.getline(newWord.word, 100);
			cout << "enter the desctiption of the new word  ";
			cin.getline(newWord.description, 500);
			rechnik[currentSizeWords++] = newWord;
		}
	}
	void deleteWord()
	{
		char nameOfWordToRemove[100];
		cin.getline(nameOfWordToRemove, 100);
		for (int i = 0;i < currentSizeWords;i++)
		{
			if (strcmp(nameOfWordToRemove, rechnik[i].word) == 0)
			{
				for (int j = i + 1;j < currentSizeWords;j++)
				{
					rechnik[j - 1] = rechnik[j];
			}//moje bi rechnik[currentSizeWords-1] trqbva da se anulira;
				currentSizeWords--;
			}
		}
	}
	void searchMeaningOfWord()
	{
		char nameOfWordToSearch[100];
		cin.getline(nameOfWordToSearch, 100);
		for (int i = 0;i < currentSizeWords;i++)
		{
			if (strcmp(nameOfWordToSearch, rechnik[i].word) == 0)
				cout << rechnik[i].description << endl;
		}
	}
	void sortDictionary()
	{
		bool swapped = true;
		int j = 0;
		word_Description temp;
		while (swapped)
		{
			swapped = false;
			j++;
			for (int i = 0;i < currentSizeWords - j;i++)
			{
				//ili predi for-a
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
	Dictionary operator + (Dictionary other)
	{
		Dictionary c;//poneje se namiram v klasa moga direktno da dostapvam elementite i na c ne s get funkcii
		//c.initializeDictionary();
		int i;
		for (i = 0;i <currentSizeWords;i++)
		{
			c.rechnik[i] = rechnik[i];
		}
		c.currentSizeWords = i;
		for (int j = 0;j < other.currentSizeWords&&i<MAX_COUNT_WORD;j++)
		{
			bool flag = true;
			for (int p = 0;(p < c.currentSizeWords)&&flag;p++)
			{
				if (strcmp(c.rechnik[p].word, other.rechnik[j].word) == 0)
				{
					strcat(c.rechnik[p].description, "  ");
					strcat(c.rechnik[p].description, other.rechnik[j].description);
					flag = false;
				}
			}
			if(flag)
			c.rechnik[i++] = other.rechnik[j];
			c.currentSizeWords = i;
			
		}
		return c;
	}
};
int main2()
{
	Dictionary a,b;
	int n,m;
	cin >> n;
	cin >> m;
	cin.ignore();
	a.initializeDictionary();
	b.initializeDictionary();
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
	cout << "sboren rechnik" << endl;
	(a + b).showDictionary();
	system("pause");
	return 0;

}*/