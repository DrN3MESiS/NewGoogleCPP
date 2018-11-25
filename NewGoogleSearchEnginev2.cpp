/* ==== Estructura de Datos ===== */
/*          App made by:          */
/* Alan Enrique Maldonado Navarro */
/*        Andree Marco Ruiz       */
/*    Universidad Panamericana    */
/* ============================== */

#include <iostream>
#include <cstring>

using namespace std;

//Estructura para Trie

struct TRIE{ //Struct Base para el Trie
	int isFilled; //Variable que determina si el Trie tiene elementos o no
	struct TRIE * child[26]; //Array que tiene el tamaño del Abecedario
};

struct TRIE* createTrieNodes(){ //Funcion para inicializar el Trie
	struct TRIE * tmp = (struct TRIE*)malloc(sizeof(struct TRIE)); //Copia del Trie Original
	tmp->isFilled=0; //Declaramos que el trie es vacio
	for (int i = 0; i < 26; i++){ //Rellenamos el ABC con NULL
		tmp->child[i] = NULL;
	}
	return tmp;
}

//Relaciones a Funciones
void addWordToTrie(struct TRIE *BaseRoot, string str);
void SearchForWordInTrie_util(struct TRIE *BaseRoot, string tmp);
void SearchForWordInTrie(struct TRIE *BaseRoot, string str);

// Funcionalidad del Programa

int main(){
	int I_COUNT, Q_COUNT; //Variables que seran las veces que se ingresaran palabras y los prefijos a buscar
	struct TRIE *TrieRoot = createTrieNodes(); //Creamos un trie e inicializamos sus nodos
	cin >> I_COUNT >> Q_COUNT; //Recibimos los valores de inserts y prefixes
	string PrefixToSearchArray[Q_COUNT]; //Creamos un arreglo que tendra nuestros prefijos
	
	for (int i = 0; i < I_COUNT; i++){ //Añadimos las palabras al diccionario
		string wordToInsert;
		cin >> wordToInsert;
		addWordToTrie(TrieRoot, wordToInsert); //Metemos cada palabra al Trie
	}
	for (int i = 0; i < Q_COUNT; i++){ //Añadimos los prefijos al arreglo
		cin >> PrefixToSearchArray[i];
	}
	for(int i = 0; i < Q_COUNT; i++){ //Buscamos los prefijos del arreglo en el Trie
		cout << endl;
		SearchForWordInTrie(TrieRoot, PrefixToSearchArray[i]); //Buscamos el prefijo en la posicion i del arreglo con cada iteracion.
	}
	return 0; //Terminamos
}

void addWordToTrie(struct TRIE *BaseRoot, string str){
	int abcPos; //Variable que determinara la posicion de las letras de la palabra en el abecedario
	for (int i = 0; i < str.length(); i++){
		abcPos = str[i]-'a'; //Calculamos la posicion de cada letra.
		if(BaseRoot->child[abcPos] == NULL){ //Si la posicion en nuestro arreglo de abecedario esta vacia, creamos un nuevo trie a partir de esa letra
			BaseRoot->child[abcPos] = createTrieNodes();
		}
		BaseRoot = BaseRoot->child[abcPos]; //Si la condicion de arriba no se cumple, significa que hay un nodo en esa letra, por lo tanto se agrega como hijo
	}
	BaseRoot->isFilled = 1; //Marcamos el Trie que tenemos como lleno
}
void SearchForWordInTrie_util(struct TRIE *BaseRoot, string tmp){
	if(BaseRoot->isFilled == 1){ //Si el trie tiene elementos dentro, imprimimos el prefijo
		cout << tmp << endl;
	}
	for (int i = 0; i < 26; i++){
		if(BaseRoot->child[i] != NULL){ //Se buscaran todos los tries que le sigan al trie de la ultima letra del prefijo
			SearchForWordInTrie_util(BaseRoot->child[i], tmp + (char)(i+'a'));
		}
	}
}
void SearchForWordInTrie(struct TRIE *BaseRoot, string str){
	string tmp=""; //Nuestro prefijo
	int abcPos; //Posicion en el abecedario
	for(int i = 0; i < str.length(); i++){
		abcPos = str[i]-'a'; //Calculamos la posicion
		tmp += (str[i]); //Re-declaramos nuestro prefij
		if(BaseRoot->child[abcPos] == NULL){//Se verifica si ya no hay elementos dentro del ultimo trie, si es asi, terminamos la busqueda
			return; 
		}
		BaseRoot = BaseRoot->child[abcPos]; // Si la condicion no se completa, seguimos verificando ese ultimo trie
	}
	SearchForWordInTrie_util(BaseRoot, tmp); //Llamamos a la funcion que determina las palabras que coinciden/inician con el prefijo
}
