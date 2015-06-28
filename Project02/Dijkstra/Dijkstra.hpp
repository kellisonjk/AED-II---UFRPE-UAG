/*
* Prim.hpp
*
*  Created on: Jun 27, 2015
*      Author: Kellison
*/

#ifndef DIJKSTRA_HPP_
#define DIJKSTRA_HPP_

#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <stdexcept>
#include <list>
#include <fstream>
#include "../Graph/Graph.hpp"
#include "./Heap/Heap.h"

#define FILEOUTPUT_EDGES "../view/Dijkstra.csv"

using namespace std;

template <class TVertex>
class Dijkstra
{
public:
	Dijkstra();
	void getDistances(TVertex);

	// Atributo (public por causa de um erro q impede a compilação (descrito no .cpp)
	Graph<TVertex> graph;

	int findIndex(TVertex);

	void print();

	virtual ~Dijkstra();
private:
	vector<list<TVertex> > antecessor;
	vector<VertexCost> distance;
	TVertex source;
};

#endif /* DIJKSTRA_HPP_ */

