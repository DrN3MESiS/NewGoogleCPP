#include<iostream>
#include<cstring>
#include<cmath>
#include<bits/stdc++.h> 

using namespace std; 
  
const int ALPHABET_SIZE = 25; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) //La funcion requiere la variable del Trie y la palabra a analizar
{ 
    struct TrieNode *pCrawl = root;  //Cada letra se convierte en su propio alphabet
  
    for (int i = 0; i < key.length(); i++) //Toma la palabra, y la examina, letra por letra.
    { 
        int index = key[i] - 'a'; //Calcula la posicion de la primera letra del string en el arreglo del alphabet
        if (!pCrawl->children[index])  //Si la letra esta dentro del abecedario, no hace nada, pero si no esta, llama a crear 
            pCrawl->children[index] = getNode(); //agregamos el hijo que no tiene
  
        pCrawl = pCrawl->children[index]; //el nuevo inicio sera la letra en la que se quedo
    } 
  
    pCrawl->isEndOfWord = true; //El ultimo nodo se convierte en un nuevo hijo.
} 
  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; //Cada letra se convierte en su propio alphabet
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index])
        {
            return false; 
        }
        
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 

bool searchAdyacent(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; //Cada letra se convierte en su propio alphabet
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index])
        {
            return false; 
        }
        
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Driver 
int main() 
{ 
    int I_COUNT, Q_COUNT;
	cin >> I_COUNT >> Q_COUNT;
    
    string wordsToInsert[I_COUNT]; //arreglo que tendra todas las palabras del usuario 
    string prefix[Q_COUNT]; //arreglo que guardara todos los prefijos que se preguntaran
    
    for(int i = 0; i < I_COUNT; i++)
    {
		cin >> wordsToInsert[i]; //ingresar cada una de las palabras al diccionario
	}
	
	for(int i = 0; i < Q_COUNT; i++)
    {
		cin >> prefix[i];//ingresar cada uno de los prefijos a preguntar
	}
  
    struct TrieNode *root = getNode(); //Creacion del Trie como Struct
  
    // Funcion para construir el Diccionario
    for (int i = 0; i < I_COUNT; i++)
    {
        insert(root, wordsToInsert[i]); 
    }
    
    // Buscar prefijo dentro del Trie
    for(int i = 0; i < Q_COUNT; i++)
    {
        if(search(root, prefix[i]))
        {
            cout << "La palabra si esta en el Trie (Esto no es un prefijo) == " << prefix[i] << "\n";
        }
            else 
        {
            cout << "La palabra no esta en el Trie (Esto no es un prefijo) == " << prefix[i] << "\n";
        }
        
        searchAdyacent(root, prefix[i];
    }
    return 0; 
} 
