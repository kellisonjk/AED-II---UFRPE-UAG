/*
* FloydWarshall.hpp
*
*  Created on: Jun 06, 2015
*      Author: Kellison
*/

#ifndef FLOYDWARSHALL_HPP_
#define FLOYDWARSHALL_HPP_

#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <stdexcept>
#include <fstream>
#include "../Graph/Graph.hpp"
#include "../lib/Heap/Heap.h"

#define FILEOUTPUT_EDGES "../view/FloydWarshall.csv"

using namespace std;

template <class TVertex>
class FloydWarshall
{
public:
	FloydWarshall();

	void getDistances();
	
	// Atributo (public por causa de um erro q impede a compilação (descrito no .cpp)
	Graph<TVertex> graph;

	void print();

	virtual ~FloydWarshall();
private:
	vector< vector<TVertex> > distanceMatriz;
	vector< vector<TVertex> > antecessorMatriz;

};

#endif /* FLOYDWARSHALL_HPP_ */

