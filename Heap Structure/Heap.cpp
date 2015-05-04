/*
* Heap.cpp
*
*  Created on: May 3, 2015
*      - Author: Kellison
*		- Descri��o:
*
*/

#include <iostream>
#include <string>
#include "Heap.h"

using namespace std;


// Inicializadores da classe
template <class object>
Heap<object>::Heap(){}

template <class object>
Heap<object>::Heap(object data[], int type, int max, int size){
	this->data = data;
	this->type = type;
	this->maxSize = max;
	this->size = size;

	this->build();
}

// Inicializa o heap recebendo seu tipo (min ou max) e seu tamanho m�ximo
template <class object>
Heap<object>::Heap(int type, int max) : type(type), maxSize(max){
	this->data = new object[max];
	this->size = 0;
}

// Realiza a "heapfica��o" do vetor
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
		// Troca o valor do objeto da posi��o "pos" pelo da posi��o "bigger"
		this->exchange(pos, bigger);
		this->heapfy(bigger);
	}

}

// Constr�i o heap a partir de um array j� preenchido
template <class object>
void Heap<object>::build(){
	for (int i = (this->maxSize / 2); i >= 0 ; i--){
		this->heapfy(i);
	}
}

// Troca os valores do objeto na posi��o a pelo da posi��o b
template <class object>
void Heap<object>::exchange(int a, int b){
	object aux;
	
	aux = this->data[a];
	this->data[a] = this->data[b];
	this->data[b] = aux;

}

// Realiza a compara��o entre os dois objetos recebidos,
// sendo que dependendo do tipo do Heap, usar� um operador diferente
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

// Verifica se � um Heap Max
template <class object>
bool Heap<object>::isHeapMax(){
	if (this->type == MAX_HEAP) return true;
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

// Ordena o heap atrav�s do algoritmo heapsort
template <class object>
void Heap<object>::sort(){
	this->build();
	for (int i = this->size-1; i >= 1; i--){
		this->exchange(0, i);
		this->size--;
		this->heapfy(0);
	}

}


// Erro na linha "delete [] data"
template <class object>
void Heap<object>::clear(){
	this->size = 0;
	delete [] data;
}


template <class object>
Heap<object>::~Heap(){
}