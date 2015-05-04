/*
* Heap.cpp
*
*  Created on: May 3, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação da estrutura de dados Heap + seu algoritmo de ordenação Heapsort.
*
*/


#include <iostream>
#include <string>
#include "Heap.h"

template class Heap<int>;
using namespace std;


// Inicializadores da classe
template <class object>
Heap<object>::Heap(){
	this->size = 0;
}

template <class object>
Heap<object>::Heap(object data[], int type, int max, int size){
	this->data = data;
	this->type = type;
	this->maxSize = max;
	this->size = size;

	this->build();
}

// Inicializa o heap recebendo seu tipo (min ou max) e seu tamanho mбximo
template <class object>
Heap<object>::Heap(int type, int max) : type(type), maxSize(max){
	this->data = new object[max];
	this->size = 0;
}

// Realiza a "heapficaзгo" do vetor
template <class object>
void Heap<object>::heapfy(int pos){
	int type = this->type;
	int left = LEFT(pos);
	int right = RIGHT(pos);
	int bigger;

	if ((left < this->size) && (this->compare(this->data[left], this->data[pos])))
		bigger = left;
	else
		bigger = pos;

	if ((right < this->size) && (this->compare(this->data[right], this->data[bigger])))
		bigger = right;

	if (bigger != pos){
		// Troca o valor do objeto da posiзгo "pos" pelo da posiзгo "bigger"
		this->exchange(pos, bigger);
		this->heapfy(bigger);
	}

}

// Constrуi o heap a partir de um array jб preenchido
template <class object>
void Heap<object>::build(){
	for (int i = (this->maxSize / 2); i >= 0; i--){
		this->heapfy(i);
	}
}

// Extrai o elemento de maior ou menor valor do heap (dependendo do seu tipo)4
template <class object>
object Heap<object>::extract(){
	object aux;

	aux = this->data[0];
	this->data[0] = this->data[--this->size];
	this->heapfy(0);

	return aux;
}

// Insere um novo elemento na estrutura
template <class object>
void Heap<object>::insert(object newData){
	int pos, parent;

	this->size++;
	pos = (this->size)-1;
	parent = PARENT(pos);

	while ((pos > 0) && (!this->compare(this->data[parent],newData))){
		this->data[pos] = this->data[parent];
		pos = parent;

		parent = PARENT(pos);
	}

	this->data[pos] = newData;

}


// Troca os valores do objeto na posiзгo a pelo da posiзгo b
template <class object>
void Heap<object>::exchange(int a, int b){
	object aux;
	
	aux = this->data[a];
	this->data[a] = this->data[b];
	this->data[b] = aux;

}

// Realiza a comparaзгo entre os dois objetos recebidos,
// sendo que dependendo do tipo do Heap, usarб um operador diferente
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

// Verifica se й um Heap Max
template <class object>
bool Heap<object>::isHeapMax(){
	if (this->type == MAX_HEAP) return true;
	return false;
}

// Verifica se o heap está vazio
template <class object>
bool Heap<object>::isEmpty(){
	cout << "SIZE " << this->size << endl;
	if (this->size == 0) return true;
	return false; 
}

// Imprime o heap em forma de array na tela
template <class object>
void Heap<object>::print(){
	for (int i = 0; i < size; i++){
		cout << " " << this->data[i];
		if (i != (size - 1)) cout << " -";
	}
	cout << endl;
}

// Ordena o heap atravйs do algoritmo heapsort
template <class object>
void Heap<object>::sort(){
	this->build();
	for (int i = this->size - 1; i >= 1; i--){
		this->exchange(0, i);
		this->size--;
		this->heapfy(0);
	}
}

// Erro na linha "delete [] data"
template <class object>
void Heap<object>::clear(){
	this->size = 0;
	delete[] data;
}

template <class object>
int Heap<object>::getSize(){ return this->size; }

template <class object>
int Heap<object>::getMaxSize(){ return this->maxSize; }

template <class object>
object Heap<object>::getMaximum(){
	if (this->isHeapMax())
		return this->data[0];
	else
		return this->data[this->size - 1];
}

template <class object>
object Heap<object>::getMinimum(){
	if (this->isHeapMax())
		return this->data[this->size - 1];
	else
		return this->data[0];

}

template <class object>
Heap<object>::~Heap(){
}