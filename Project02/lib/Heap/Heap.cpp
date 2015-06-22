/*
* Heap.cpp 
*
*  Created on: May 3, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação da estrutura de dados Heap + seu algoritmo de ordenação Heapsort.
*
*	Heapsort: Além da implementação tratando os dados da classe, há também uma implemntação feita através de um 
*			  método static, recebendo um vetor e construindo o heap a partir do vetor. Assim, o não é necesário a 
*			  implementação de um Heap pela aplicação que utilizará o método.
*
*/

#include "Heap.h"
#include "../../Graph/Edge.hpp"

template class Heap<Edge<int> >; 
using namespace std;


// Inicializadores da classe
template <class object>
Heap<object>::Heap(){
	this->size = 0;
}

template <class object>
Heap<object>::Heap(vector<object> data, int type, int max, int size){
	this->data = data;
	this->type = type;
	this->maxSize = max;
	this->size = size;
	this->build();
}

// Inicializa o heap recebendo seu tipo (min ou max) e seu tamanho máximo
template <class object>
Heap<object>::Heap(int type, int max) : type(type), maxSize(max){
	this->maxSize = max;
	this->size = 0;
}

// Realiza a "heapficação" do vetor
template <class object>
void Heap<object>::heapfy(int pos){
	int type = this->type;
	int left = LEFT(pos);
	int right = RIGHT(pos);
	int bigger;

	if ((left < this->size) && (this->compare(this->data.at(left), this->data.at(pos))))
		bigger = left;
	else
		bigger = pos;

	if ((right < this->size) && (this->compare(this->data.at(right), this->data.at(bigger))))
		bigger = right;

	if (bigger != pos){
		// Troca o valor do objeto da posiзгo "pos" pelo da posiзгo "bigger"
		this->exchange(pos, bigger);
		this->heapfy(bigger);
	}

}

// Constrói o heap a partir de um array já preenchido
template <class object>
void Heap<object>::build(){
	for (int i = (this->maxSize / 2); i >= 0; i--){
		this->heapfy(i);
	}
}

// Extrai o elemento de maior ou menor valor do heap (dependendo do seu tipo)4
template <class object>
object Heap<object>::extract(){

	try{
		if (this->isEmpty())
			throw underflow_error("Impossivel extrair elementos. Status heap: vazia.");

		object aux;

		aux = this->data.at(0);
		this->data[0] = this->data.at(--this->size);
		this->heapfy(0);
		return aux;
	}
	catch (const underflow_error& oor)
	{
		cerr << endl << "  Underflow error: " << oor.what() << '\n';
	}
}


// Altera a prioridade do elemento (aumenta ou diminui de acordo com o tipo da heap)
template <class object>
void Heap<object>::changeKey(int i, object data, string source){
	if (this->data.at(i) > data){
		cout << endl << "    Nova chave é menor que a atual." << endl;
		return;
	}

	try {
		int parent = PARENT(i);
		this->data[i] = data;
		
		while (i > 0){
			if (source == "remove"){
				// Realiza o oposto do que seria feito em caso de "não remoção"
				if (!this->compare(this->data.at(parent), this->data.at(i)))
					break;
			}
			// Caso não seja a partir do método de remoção
			/*else{
				// "parent > i" = MAX HEAP, ou "parent < i" = MIN HEAP
				if ((this->compare(this->data.at(parent), this->data.at(i))))
					cout << "CHANGE" << endl;
			}*/

			this->exchange(i, parent);
			i = parent;
			parent = PARENT(i);
		}
	}
	catch (const out_of_range& oor) {
		cerr << endl << endl << "    Fora da capacidade do array: " << oor.what() << endl << endl;
	}
}

// Remove um objeto X do heap
template <class object>
bool Heap<object>::remove(object data){
	int a = this->search((object)data);
	if (a >= 0){
		this->changeKey(a, this->data[a], "remove");
		this->extract();
		return true;
	}
	return false;
}

// Procura um objeto X do heap
template <class object>
int Heap<object>::search(object data){
	if (!(this->isEmpty())){

		// Verifica se o valor a ser pesquisado é maior (max heap) ou 
		// menor (min heap) que a raiz, caso seja retorna -1;
		if (((this->type == MAX_HEAP) && (data > this->getRoot()))
			|| ((this->type == MIN_HEAP) && (data < this->getRoot())))
			return -1;

		for (int i = 0; i < this->size; i++)
		{
			if (this->data.at(i) == data) return i;
		}
	}
	else{
		//cout << endl << "   Heap vazia. " << endl << endl;
	}

	return -1;
}

// Troca os valores do objeto na posição a pelo da posição b
template <class object>
void Heap<object>::exchange(int a, int b){
	object aux;

	aux = this->data[a];
	this->data[a] = this->data[b];
	this->data[b] = aux;
	//cout << this->data[a] << "  " << this->data[b] << endl;
}

// Realiza a comparaзгo entre os dois objetos recebidos,
// sendo que dependendo do tipo do Heap, usará um operador diferente
template <class object>
bool Heap<object>::compare(object obj_one, object obj_two){
	if (this->isHeapMax())
		return (obj_one > obj_two) ? true : false;
	else
		return (obj_one < obj_two) ? true : false;
}

// Converte para string o tipo do Heap
template <class object>
string Heap<object>::typeToString(){
	string type = (this->type == 1) ? "MAX HEAP" : "MIN HEAP";
	return type;
}

// Verifica se é um Heap Max
template <class object>
bool Heap<object>::isHeapMax(){
	if (this->type == MAX_HEAP) return true;
	return false;
}

// Verifica se o heap está vazio
template <class object>
bool Heap<object>::isEmpty(){
	if (this->size == 0) return true;
	return false;
}

// Imprime o heap em forma de array na tela
/*template <class object>
void Heap<object>::printArray(int extraSpace){

	this->printSpaces(extraSpace);
	cout << "- Heap impressa (array): " << endl;

	this->printSpaces(extraSpace + 2);

	for (int i = 0; i < this->size; i++){
		cout << this->data.at(i);
		if (i != (this->size - 1)) cout << " - ";
	}
	cout << endl;
}
*/
//Imprime o heap em forma de tree na tela
template <class object>
void Heap<object>::printTree(int extraSpace){
	int aux = 0;
	int space = pow(2, this->getHeight());

	this->printSpaces(extraSpace);

	cout << "- Heap impressa (por nivel)" << endl;

	for (int i = 0; i <= this->getHeight(); i++){
		this->printSpaces(extraSpace + 2);

		for (int a = 1; a <= pow(2, i); a++, aux++){
			if ((aux >= this->size))
				break;

			cout << this->data.at(aux).vertexSource() << " ";

			cout << " ";
		}
		cout << endl;
		space /= 2;
	}
	cout << endl;
}

// Calcula a altura da arvore
template <class object>
int Heap<object>::getHeight(){
	if (this->isEmpty())
		return -1;
	else{
		int h = -1, i = 0, left = 0;

		// Caminha até a folha mais a esquerda do heap, e contabiliza o número de 
		// elementos até lá.
		while (left < this->size){
			left = LEFT(left);
			h++;
		}

		return h;
	}
}

// Ordena um vetor através do método (static) de ordenação Heapsort
template <class object>
void Heap<object>::sort(vector<object>& vector, int type){
	Heap<object> heap(vector, type, vector.size(), vector.size());
	cout << vector.size() << endl;
	vector = heap.sort();
}

// Ordena a estrutura heap
template <class object>
vector<object> Heap<object>::sort(){
	vector<object> aux;
	this->build();
	for (int i = this->size - 1; i >= 0; i--){
		this->exchange(0, i);
		aux.push_back(this->data.at(i));
		this->size--;
		this->heapfy(0);
	}

	
	return aux;
}

// Imprime espaços no console
template <class object>
void inline Heap<object>::printSpaces(int n){
	for (int a = 0; a < n; a++)
		cout << " ";
}


template <class object>
void Heap<object>::clear(){
	this->size = 0;
	//this->data.clear();
}

template <class object>
int Heap<object>::getSize(){ return this->size; }

template <class object>
int Heap<object>::getMaxSize(){ return this->maxSize; }

template <class object>
vector<object> Heap<object>::getData(){
	return this->data;
}

template <class object>
object Heap<object>::getData(int pos){
	return this->data.at(pos);
}

// Retorna o primeiro elemento do heap
template <class object>
object Heap<object>::getRoot(){
	return this->data.at(0);
}


// Usado exclusivamente para a atualização dos custos de um vertice (PRIM)
template <class object>
void Heap<object>::updateCost(int ind, double cost){
	this->data[ind].cost(cost);
}


template <class object>
Heap<object>::~Heap(){
}