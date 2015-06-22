/*
* Kruskal.hpp
*
*  Created on: May 29, 2015
*      Author: Kellison
*/

#ifndef KRUSKAL_HPP_
#define KRUSKAL_HPP_

#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <stdexcept>
#include <fstream>
#include "../Graph/Graph.hpp"

// Arquivo onde serão armazenados os dados das arestas
#define FILEOUTPUT_EDGES "../view/kruskal.csv"

using namespace std;

template <class TVertex>
class Kruskal
{
public:
	Kruskal();
	Kruskal(Graph<TVertex>);
	vector< Edge<TVertex> > getMST();
	void printEdges();
	void saveEdgesFile();

	// Atributo (public por causa de um erro q impede a compilação (descrito no .cpp)
	Graph<TVertex> graph;

	~Kruskal();
private:
	void createMST();
	int findComponent(TVertex);
	void mergeComponent(TVertex, TVertex);
	vector< Edge<TVertex> > mst; // Minimum Spanning Tree (Arvore Geradora Mínima)
	int components[]; // Componentes complexos

};

#endif /*KRUSKAL_HPP_*/
