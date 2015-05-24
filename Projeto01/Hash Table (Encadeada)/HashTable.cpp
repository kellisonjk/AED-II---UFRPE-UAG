/*
* HashTable.cpp
*
*  Created on: May 11, 2015
*      - Author: Kellison
*		- Descriзгo:
*			Implementação de uma HashTable encadeada.
*
*/

#include "HashTable.h"
#include "Data.h"

template class HashTable<Data, string>;
using namespace std;

// Constrói a HashTable de acordo com o tamanho desejado
template <class TData, class TKey>
HashTable<TData, TKey>::HashTable(int size){
	this->table.resize(size);
}

// Realiza a adição de um novo dado na Hash
template <class TData, class TKey>
void HashTable<TData, TKey>::insert(TData newData){
	int index = newData.getHash(this->table.size());
	this->table[index].push_front(newData);
}

// Procura na Hash Table por um registro que possua a chave passada
template <class TData, class TKey>
TData HashTable<TData, TKey>::search(TKey key){
	TData aux;
	aux.setKey(key);

	return this->search(aux);
}

template <class TData, class TKey>
TData HashTable<TData, TKey>::search(TData data){

	// Calcula a posição na tabela hash
	int index = data.getHash(this->table.size());

	typename list<TData>::iterator it;

	it = find(this->table[index].begin(), this->table[index].end(), data);

	if (it == this->table[index].end())
		throw out_of_range("  Elemento nao existente na HashTable.");

	TData& aux = *it;

	return aux;
}

// Remove um elemento da lista contida em uma posiзгo X da Hash Table
template <class TData, class TKey>
void HashTable<TData, TKey>::remove(TData data){
	int index = data.getHash(this->table.size());
	this->table[index].remove(data);
}


// Imprime a hash table
template <class TData, class TKey>
void HashTable<TData, TKey>::printHash(){
	for (int index = 0; index < this->table.size(); index++){
		cout << endl << "#" << index << " Hash" << endl;

		if (!(this->table[index].empty())){
			int i = 0;
			for (typename list<TData>::iterator it = this->table[index].begin(); it != this->table[index].end(); it++){
				cout << "   " << (++i) << ") " << *it << endl;
			}
		}
		else{
			cout << "   <VAZIA> " << endl;
		}

	}

	cout << endl;
}

template <class TData, class TKey>
HashTable<TData, TKey>::~HashTable(){}