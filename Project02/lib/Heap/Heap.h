/*
* RedBlackTree.h
*
*  Created on: May 3, 2015
*      Author: Kellison
*/

#ifndef HEAP_H_
#define HEAP_H_

#define MAX_HEAP 1
#define MIN_HEAP 0
#define PARENT(pos) ((pos-1)/2);
#define LEFT(pos) ((2*pos)+1);
#define RIGHT(pos) ((2*pos)+2);

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <math.h> 
#include <limits> 

using namespace std;

template <class object>
class Heap
{
	public:
		Heap();
		Heap(vector<object>, int, int, int);
		Heap(int, int);
		void heapfy(int);
		void build();
		object extract();
		object getRoot();
		void insert(object);
		void changeKey(int, object, string);
		bool remove(object);
		int search(object);
		string typeToString();
		bool isHeapMax();
		bool isEmpty();
		void printArray(int);
		void printTree(int);
		vector<object> getData();
		object getData(int);
		static void sort(vector<object>&, int);
		vector<object> sort();
		void clear();
		int getSize();
		int getMaxSize();
		int getHeight();

		void updateCost(int,double); // Usado para os algoritmos de grafos

		virtual ~Heap();

	private:
		bool compare(object, object);
		void exchange(int, int);
		void inline printSpaces(int);

		vector<object> data;
		int maxSize; // Número máximo de elementos permitidos
		int size; // Número total de elementos preenchidos
		int type; // Tipo do Heap: MAX ou MIN
};

#endif /* HEAP_H_ */