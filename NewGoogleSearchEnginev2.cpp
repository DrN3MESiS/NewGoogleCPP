#include <iostream>
#include <cstring>

using namespace std;

struct TRIE{
	int flag;
	struct TRIE * child[26];
};
struct TRIE* createTrieNodes(){
	struct TRIE * tmp = (struct TRIE*)malloc(sizeof(struct TRIE));
	tmp->flag=0;
	for (int i = 0; i < 26; i++){
		tmp->child[i] = NULL;
	}
	return tmp;
}
void addWordToTrie (struct TRIE *curr,string str){
	int c;
	for (int i = 0; i < str.length(); i++){
		c = str[i]-'a';
		if(curr->child[c] == NULL){
			curr->child[c] = createTrieNodes();
		}
		curr = curr->child[c];
	}
	curr->flag = 1;
}
void SearchForWordInTrie_util(struct TRIE *curr,string tmp){
	int c;
	if(curr->flag == 1){
		cout << tmp << endl;
	}
	for (int i = 0; i < 26; i++){
		if(curr->child[i] != NULL){
			SearchForWordInTrie_util(curr->child[i], tmp + (char)(i+'a'));
		}
	}
}
void SearchForWordInTrie(struct TRIE *curr,string str){
	string tmp="";
	int c;
	for(int i = 0; i < str.length(); i++){
		c = str[i]-'a';
		tmp += (str[i]);
		if(curr->child[c] == NULL){
			return;
		}
		curr = curr->child[c];
	}
	SearchForWordInTrie_util(curr, tmp);
}
int main(){
	int I_COUNT, Q_COUNT;
	struct TRIE *TrieRoot = createTrieNodes();
	cin >> I_COUNT >> Q_COUNT;
	string PrefixToSearchArray[Q_COUNT];
	
	for (int i = 0; i < I_COUNT; i++){
		string wordToInsert;
		cin>>wordToInsert;
		addWordToTrie(TrieRoot, wordToInsert);
	}
	for (int i = 0; i < Q_COUNT; i++){
		cin>>PrefixToSearchArray[i];
	}
	for(int i = 0; i < Q_COUNT; i++){
		cout << endl;
		SearchForWordInTrie(TrieRoot, PrefixToSearchArray[i]);
	}
	return 0;
}
