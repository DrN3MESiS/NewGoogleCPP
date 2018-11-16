#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

class Node{
	public:
		
	char val;
	Node *X[25];
	bool isWord;
	
	Node(char c = '#', bool isWord = false){
		this->val = c;
		this->isWord = isWord;
		
		for(int i = 0; i < 25; i++){
			this->X[i] = NULL;
		}
	}
};

class Trie{
	private:
		Node *H[25];
		
	public:
		
	Trie(){
		for(int i = 0; i < 25; i++){
			this->H[i] = NULL;
		}
	}
	
	void insertWord(string word){
		int k = word[0] - 'a';
		
		if(H[k] == NULL){
			H[k] = new Node(word[0], false);
		}
		
		Node *curNode = H[k];
		
		for(int i = 1; i < word.length(); i++){
			k = word[i] - 'a';
			if(curNode->X[k] == NULL){
				curNode->X[k] = new Node(word[i], false);
			} else {
				curNode = curNode->X[k];
			}
		}
		
		curNode->isWord = true;
	}
	
	bool findWord(string word){
		int k = word[0] - 'a';
		
		if(H[k] == NULL){
			return false;
		}
		//sada
		Node *curNode = H[k];
		for(int i = 1; i < word.length(); i++){
			k = word[i] - 'a';
			if(curNode->X[k] == NULL){
				return false;
			} else {
				curNode = curNode->X[k];
			}
		}		
		return curNode->isWord;
	}
};

int main(){
	Trie Google;
	
	int I_COUNT, Q_COUNT;
	cin >> I_COUNT >> Q_COUNT;
	
	for(int i = 0; i < I_COUNT; i++){
		string wordToInsert;
		cin >> wordToInsert;
		
		Google.insertWord(wordToInsert);
	}
	
	for(int i = 0; i < Q_COUNT; i++){
		string prefix;
		cin >> prefix;
		
		Google.findWord(prefix);
	}
	
	return 0;
}
