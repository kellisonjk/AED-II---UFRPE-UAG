/*
* Gaph.hpp
*
*  Created on: May 26, 2015
*      Author: Kellison
*
*	Observacoes:
*		- Para que a visalização do grafo funcione a partir do console, é necessário
*		  que o valor <CAMINHO> da constante GRAPHVIEW seja alterada para o caminho
*		  da pasta "Project02" na máquina em que a aplicação está sendo executada.
*
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <fstream>
//#include <Windows.h>
#include "Edge.hpp"

// Caminho para o arquivo que será usado para exibir o grafo
//#define GRAPHVIEW "<CAMINHO>/aedii/Project02/view/index.html"

#define GRAPHVIEW "C:/wamp/bin/apache/apache2.4.9/cgi-bin/projetos/aedii/Project02/view/index.html"

// Arquivo onde serão armazenados os dados das arestas
#define FILEOUTPUT "../view/edges.csv"

#define INF (double) 99999

using namespace std;

template <class TVertex>
class Graph{
public:
	Graph();
	Graph(string);
	Graph(string, vector<TVertex>);
	Edge<TVertex> getEdge(TVertex, TVertex);
	void setEdge(TVertex, TVertex, double);
	TVertex getVertex(int);
	vector<TVertex> getVertex();
	vector< Edge<TVertex> > getAdjacents(TVertex);
	vector< Edge<TVertex> > getAllEdges();
	int getIndex(TVertex);
	void showMatriz();
	void showGraphView();
	void showAllVertex();
	int getNumberVertex();
	int getNumberEdge();
	
	vector< vector<TVertex> > getAdjacencyMatriz();

	void saveFile(TVertex, TVertex, double);
	void openFile(string);

	void setDirecionado(bool);

	void operator= (Graph<TVertex>&);

	virtual ~Graph();
private:
	bool direcionado;
	vector<TVertex> vertex;
	vector< vector<TVertex> > adjacencyMatriz;
	int edgeNumber;
	ofstream outfile;
};


// Struct usado para o algoritmo de Dijkstra
struct VertexCost{
	int vertexc;
	int vertex_prev;
	double cost;
	
	void add(int v, double c, int p){
		vertexc = v;
		vertex_prev = p;
		cost = c;
	}

	bool operator< (VertexCost data){
		return (cost < data.cost);
	}

	bool operator>(VertexCost data){
		return (cost > data.cost);
	}

	bool operator>= (VertexCost data){
		return (cost >= data.cost);
	}

	bool operator<= (VertexCost data){
		return (cost <= data.cost);
	}
	
	bool operator== (VertexCost data){
		return (cost == data.cost);
	}
};


#endif /* GRAPH_HPP_ */