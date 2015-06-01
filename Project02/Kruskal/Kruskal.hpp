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
#include <stdexcept>
#include <fstream>
#include "../Graph/Graph.hpp"

// Arquivo onde serão armazenados os dados das arestas
#define FILEOUTPUT_KRUSKAL "./view/kruskal.csv"

using namespace std;

template <class TVertex>
class Kruskal
{
public:
	Kruskal();
	Kruskal(Graph<TVertex>);
	void createMST();
	vector< Edge<TVertex> > getMST();
	int findComponent(TVertex);
	void mergeComponent(TVertex, TVertex);
	void printEdges();
	void saveEdgesFile();

	// Atributo (public por causa de um erro q impede a compilação (descrito no .cpp)
	Graph<TVertex> graph;

	~Kruskal();
private:
	vector< Edge<TVertex> > mst; // Minimum Spanning Tree (Arvore Geradora Mínima)
	int components[]; // Componentes complexos

};

#endif /*KRUSKAL_HPP_*/
