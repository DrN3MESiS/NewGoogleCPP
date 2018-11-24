		#include<cstring>
		#include<iostream>
		#include<bits/stdc++.h> 
		
		using namespace std; 
		
		#define ALPHABET_SIZE (26) 
		
		#define CHAR_TO_INDEX(c) ((int)c - (int)'a') 
		
		#define NO_RESULT "no recommendations"
		  
		struct TrieNode 
		{ 
		    struct TrieNode *children[ALPHABET_SIZE]; 
		    bool isWordEnd; 
		}; 
		  
		struct TrieNode *getNode(void) 
		{ 
		    struct TrieNode *pNode = new TrieNode; 
		    pNode->isWordEnd = false; 
		  
		    for (int i = 0; i < ALPHABET_SIZE; i++) 
		        pNode->children[i] = NULL; 
		  
		    return pNode; 
		} 
		  
		void insert(struct TrieNode *root,  const string key) 
		{ 
		    struct TrieNode *pCrawl = root; 
		  
		    for (int level = 0; level < key.length(); level++) 
		    { 
		        int index = CHAR_TO_INDEX(key[level]); 
		        if (!pCrawl->children[index]) 
		            pCrawl->children[index] = getNode(); 
		  
		        pCrawl = pCrawl->children[index]; 
		    } 
		    pCrawl->isWordEnd = true; 
		} 
		  
		bool search(struct TrieNode *root, const string key) 
		{ 
		    int length = key.length(); 
		    struct TrieNode *pCrawl = root; 
		    for (int level = 0; level < length; level++) 
		    { 
		        int index = CHAR_TO_INDEX(key[level]); 
		  
		        if (!pCrawl->children[index]) 
		            return false; 
		  
		        pCrawl = pCrawl->children[index]; 
		    } 
		  
		    return (pCrawl != NULL && pCrawl->isWordEnd); 
		} 
		  
		bool isLastNode(struct TrieNode* root) 
		{ 
		    for (int i = 0; i < ALPHABET_SIZE; i++) 
		        if (root->children[i]) 
		            return 0; 
		    return 1; 
		} 
		
		void suggestionsRec(struct TrieNode* root, string currPrefix) 
		{ 
		    if (root->isWordEnd) 
		    { 
		        cout << currPrefix; 
		        cout << endl; 
		    } 
		
		    if (isLastNode(root)) 
		        return; 
		  
		    for (int i = 0; i < ALPHABET_SIZE; i++) 
		    { 
		        if (root->children[i]) 
		        { 
		            currPrefix.push_back(97 + i); 
		            suggestionsRec(root->children[i], currPrefix); 
		        } 
		    } 
		} 
		  
		int printAutoSuggestions(TrieNode* root, const string query) 
		{ 
		    struct TrieNode* pCrawl = root; 
		
		    int level; 
		    int n = query.length(); 
		    for (level = 0; level < n; level++) 
		    { 
		        int index = CHAR_TO_INDEX(query[level]); 
		
		        if (!pCrawl->children[index]) 
		            return 0; 
		  
		        pCrawl = pCrawl->children[index]; 
		    } 
		
		    bool isWord = (pCrawl->isWordEnd == true); 
		  
		    bool isLast = isLastNode(pCrawl); 
		
		    if (isWord && isLast) 
		    { 
		        cout << query << endl; 
		        return -1; 
		    } 
		
		    if (!isLast) 
		    { 
		        string prefix = query; 
		        suggestionsRec(pCrawl, prefix); 
		        return 1; 
		    } 
		} 
		int main() 
		{ 
			struct TrieNode *root = getNode(); //Creacion del Trie como Struct
			int I_COUNT, Q_COUNT;
			cin >> I_COUNT >> Q_COUNT;
		    
		    string prefix[Q_COUNT]; //arreglo que guardara todos los prefijos que se preguntaran
		
		    for(int i = 0; i < I_COUNT; i++)
		    {
		    	string key;
				cin >> key;
				insert(root, key); //ingresar cada una de las palabras al diccionario
			}
			
			for(int i = 0; i < Q_COUNT; i++)
		    {
				cin >> prefix[i];//ingresar cada uno de los prefijos a preguntar
			}
			
			cout << "\n";
		    
		    // Buscar prefijo dentro del Trie
		    for(int i = 0; i < Q_COUNT; i++)
		    {
		    	int comp = printAutoSuggestions(root, prefix[i]); 
		    	cout << "\n";
		    	if (comp == 0)
		    	{
		    		cout << NO_RESULT;	
				} else {
					break;
				}
		    }
		    return 0;
		
		} 
