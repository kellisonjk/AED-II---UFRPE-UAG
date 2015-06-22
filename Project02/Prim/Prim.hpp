/*
* Prim.hpp
*
*  Created on: Jun 06, 2015
*      Author: Kellison
*/

#ifndef PRIM_HPP_
#define PRIM_HPP_

#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <stdexcept>
#include <fstream>
#include "../Graph/Graph.hpp"
#include "../lib/Heap/Heap.h"

#define FILEOUTPUT_EDGES "../view/prim.csv"

using namespace std;

template <class TVertex>
class Prim
{
public:
	Prim();
	void createMST();

	vector<Edge<TVertex> > getMST();
	//vector<Edge<TVertex> > getMST(Graph<TVertex>); // Não funciona quando passo um objeto Graph<TVertex>
	
	// Atributo (public por causa de um erro q impede a compilação (descrito no .cpp)
	Graph<TVertex> graph;

	void printMST();
	void saveEdgesFile();

	virtual ~Prim();
private:
	vector<Edge<TVertex> > mst;

};

#endif /* PRIM_HPP_ */

