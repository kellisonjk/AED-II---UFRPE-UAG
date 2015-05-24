/*
* HashTable.cpp
*
*  Created on: May 16, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação de uma HashTable com endereçamento aberto.
*
*/

#include "HashTable.h"
#include "Data.h"

template class HashTable<Data, string>;
using namespace std;

// Constrói a HashTable de acordo com o tamanho desejado
template <class TData, class TKey>
HashTable<TData, TKey>::HashTable(int size){
	this->table.resize(size, Data());
}


// Procura na HashTable a chave fornecida
template <class TData, class TKey>
TData* HashTable<TData, TKey>::search(TKey key){
	TData aux;
	int pos;
	aux.setKey(key);

	pos = this->search(aux);

	if (pos < 0)
		throw out_of_range("  Nenhuma posicao da Hash Table possui essa chave. ");

	return &(this->table[pos]);
}

// Procura pelo elemeno na hash table e retorna a sua posição caso seja encontrada, caso não, retorna -1
template <class TData, class TKey>
int HashTable<TData, TKey>::search(TData data){
	TData empty;
	int pos = 0, size = this->table.size();

	while (pos <size){
		if (this->table[data.getHash(size, pos)] == data){
			return data.getHash(size, pos);
		}
		else{
			if (this->table[data.getHash(size, pos)] == empty)
				return -1;
		}
		pos++;
	}

	return -1;
}


// Realiza a adição de um novo dado na Hash
template <class TData, class TKey>
void HashTable<TData, TKey>::insert(TData newData){
	TData empty;
	int pos = 0, size = this->table.size();

	while (pos < size){
		if (this->table[newData.getHash(size, pos)] == empty){
			this->table[newData.getHash(size, pos)] = newData;
			return;
		}
		pos++;
	}

	throw overflow_error(" A Hash Table nao possui nenhum espaco disponivel. ");

}


// Imprime a hash table
template <class TData, class TKey>
void HashTable<TData, TKey>::printHash(){
	for (int index = 0; index < this->table.size(); index++){
		cout << endl << "#" << index << " Hash" << endl;
		cout << "   " << this->table.at(index) << endl;
	}

	cout << endl;
}

template <class TData, class TKey>
HashTable<TData, TKey>::~HashTable(){}