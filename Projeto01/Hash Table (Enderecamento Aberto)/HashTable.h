/*
* HashTable.h
*
*  Created on: May 11, 2015
*      Author: Kellison
*/

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "Data.h" 

using namespace std;

template <class TData, class TKey>
class HashTable
{
	public:
		HashTable(int);
		void insert(TData);
		TData* search(TKey);
		int search(TData);
		void printHash();
		virtual ~HashTable();
	private:
		vector<TData> table;
};

#endif /* HASHTABLE_H_*/

