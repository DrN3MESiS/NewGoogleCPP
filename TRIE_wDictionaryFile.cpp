#include <iostream>
#include <cstring>
#include <fstream>

#define NO_RESULT "no recommendations"

using namespace std;

string currPref, data;
int isThereMore = 0, cicleNo = 0;
std::fstream dictionary;

struct TRIE
{
	int isFilled;
	struct TRIE *Alphabet[26];
};

struct TRIE *createTrieNodes()
{
	struct TRIE *tmp = (struct TRIE *)malloc(sizeof(struct TRIE));
	tmp->isFilled = 0;
	for (int i = 0; i < 26; i++)
	{
		tmp->Alphabet[i] = NULL;
	}
	return tmp;
}

void addWordToTrie(struct TRIE *BaseRoot, string str);
void SearchForWordInTrie_util(struct TRIE *BaseRoot, string tmp);
void SearchForWordInTrie(struct TRIE *BaseRoot, string str);

int main(int argc, char **argv)
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	struct TRIE *TrieRoot = createTrieNodes();

	dictionary.open("test_dictionary.txt", std::fstream::in);
	if (dictionary.is_open())
	{
		while (dictionary)
		{
			dictionary >> data;
			addWordToTrie(TrieRoot, data);
		}
	}
	else
	{
		std::cout << "error:  file not open." << std::endl;
		return -1;
	}
	dictionary.close();

	cicleNo = 0;
	SearchForWordInTrie(TrieRoot, argv[1]);
	if (isThereMore >= 1 && cicleNo < 1)
	{
		cout << NO_RESULT << "\n";
	}
	cout << "\n";
	return 0;
}

void addWordToTrie(struct TRIE *BaseRoot, string str)
{
	int abcPos;
	for (int i = 0; i < str.length(); i++)
	{
		abcPos = str[i] - 'a';
		if (BaseRoot->Alphabet[abcPos] == NULL)
		{
			BaseRoot->Alphabet[abcPos] = createTrieNodes();
		}
		BaseRoot = BaseRoot->Alphabet[abcPos];
	}
	BaseRoot->isFilled = 1;
}
void SearchForWordInTrie_util(struct TRIE *BaseRoot, string tmp)
{
	int maxSize = currPref.size() + 6;

	if (BaseRoot->isFilled == 1)
	{
		if (tmp.size() > currPref.size() && tmp.size() < maxSize)
		{
			cicleNo++;
			cout << tmp << "\n";
		}
		else
		{
			isThereMore++;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (BaseRoot->Alphabet[i] != NULL)
		{
			SearchForWordInTrie_util(BaseRoot->Alphabet[i], tmp + (char)(i + 'a'));
		}
	}
}
void SearchForWordInTrie(struct TRIE *BaseRoot, string str)
{
	isThereMore = 0;
	currPref = str;
	string tmp = "";
	int abcPos;
	for (int i = 0; i < str.length(); i++)
	{
		abcPos = str[i] - 'a';
		tmp += (str[i]);
		if (BaseRoot->Alphabet[abcPos] == NULL)
		{
			cout << NO_RESULT << "\n";
			return;
		}
		BaseRoot = BaseRoot->Alphabet[abcPos];
	}
	SearchForWordInTrie_util(BaseRoot, tmp);
}
