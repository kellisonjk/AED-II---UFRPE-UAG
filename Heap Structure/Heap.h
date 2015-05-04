/*
* RedBlackTree.h
*
*  Created on: Apr 7, 2015
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

using namespace std;

template <class object>
class Heap
{
	public:
		Heap();
		Heap(object[], int, int, int);
		Heap(int, int);
		void heapfy(int);
		void build();
		string typeToString();
		bool isHeapMax();
		bool compare(object, object);
		void exchange(int, int);
		void print();
		void sort();
		void clear();
		virtual ~Heap();

	private:
		object* data;
		int maxSize; // Número máximo de elementos permitidos
		int size; // Número total de elementos preenchidos
		int type; // Tipo do Heap: MAX ou MIN
};

#endif /* HEAP_H_ */