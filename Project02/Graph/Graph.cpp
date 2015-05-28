/*
* Graph.cpp 
*
*  Created on: May 27, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação de um Grafo.
*
*/

#include "Graph.hpp"

template class Graph<int>;
using namespace std;


// Inicializadores da classe
template <class Tpl>
Graph<Tpl>::Graph(){
	this->outfile.open("./view/arris.csv", ios::out | ios::trunc);
	this->outfile << "Node1,Node2,Cost"<<endl;
}

template <class Tpl>
Graph<Tpl>::Graph(vector<Tpl> vertices){
	this->outfile.open("./view/arris.csv", ios::out | ios::trunc);
	this->outfile << "Node1,Node2,Cost" <<endl;

	this->vertices = vertices;
	this->adjacencyMatriz.resize(vertices.size());

	for (int i = 0; i < (int) vertices.size(); i++){
		this->adjacencyMatriz[i].resize(vertices.size());
	}
}

template <class Tpl>
Tpl Graph<Tpl>::getVertice(int ind){
	return this->vertices[ind];
}


template <class Tpl>
Arris<Tpl> Graph<Tpl>::getArris(Tpl u, Tpl v)
{
	Arris<Tpl> result;

	return result;
}

template <class Tpl>
void Graph<Tpl>::setArris(Tpl u, Tpl v, double cost){
	this->adjacencyMatriz[u][v] = cost;
	this->adjacencyMatriz[v][u] = cost;

	this->saveFile(u, v, cost);
}

template <class Tpl>
void Graph<Tpl>::saveFile(Tpl u, Tpl v, double cost){
	this->outfile << u << "," << v << "," << cost << endl;
}


template <class Tpl>
vector< Arris<Tpl> > Graph<Tpl>::getAdjacents(Tpl u){
	vector< Arris<Tpl> > adj;
	int index = u;

	for (int i = 0; i < (int) this->vertices.size(); i++){
		if (this->adjacencyMatriz[i][index] != 0)
			adj.push_back(Arris<Tpl>(index, i, this->adjacencyMatriz[i][index]));
	}


	return adj;
}

template <class Tpl>
void Graph<Tpl>::showMatriz(){
	for (int i = 0; i < (int) this->vertices.size(); i++)
	{
		cout << " " << i << ": ";
		for (int j = 0; j < (int) this->vertices.size(); j++)
		{
			cout << this->adjacencyMatriz[i][j] << " ";
		}
		cout << endl;
	}
}

template <class Tpl>
void Graph<Tpl>::showGraphView(){
	ShellExecute(NULL, "open", GRAPHVIEW,NULL, NULL, SW_SHOWNORMAL);
}


template <class Tpl>
Graph<Tpl>::~Graph(){
	this->outfile.close();
}
