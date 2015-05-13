/*
* HashTable.cpp
*
*  Created on: May 11, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação de uma HashTable
*
*/

#include "HashTable.h"
#include "Data.h"

template class HashTable<Data,string>;
using namespace std;

// Constrói a HashTable de acordo com o tamanho desejado
template <class TData, class TKey>
HashTable<TData, TKey>::HashTable(int size){
	this->table.resize(size);
	for (int i = 0; i < size; i++)
	{
		this->table[i];
	}
}

// Realiza a adição de um novo dado na Hash
template <class TData, class TKey>
void HashTable<TData, TKey>::insert(TData newData){
	int index = newData.getHash(this->table.size());
	this->table[index].push_front(newData);
}


template <class TData, class TKey>
TData HashTable<TData, TKey>::search(TKey key){
	TData aux;
	aux.setKey(key);

	return this->search(aux);
}

template <class TData, class TKey>
TData HashTable<TData, TKey>::search(TData data){
	
	int index = data.getHash(this->table.size());
	
	typename list<TData>::iterator itr1;
	itr1 = find(this->table[index].begin(), this->table[index].end(), data);

	TData& aux= *itr1;
	
	return aux;
}



// Imprime a hash table
template <class TData, class TKey>
void HashTable<TData, TKey>::printHash(){
	for (int index = 0; index < this->table.size(); index++){
		cout << endl << "#" << index << " Hash" << endl;
			
		if ( !(this->table[index].empty())){
			int i = 0;
			for (typename list<TData>::iterator it = this->table[index].begin(); it != this->table[index].end(); it++){
				cout << "   " << (++i) << ") " << *it << endl;
			}
		}
		else{
			cout << "   <VAZIA> " << endl;
		}

	}
}



template <class TData, class TKey>
HashTable<TData, TKey>::~HashTable()
{

}
