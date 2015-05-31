/*
* Graph.cpp 
*
*  Created on: May 27, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação de um Grafo.
*		- Detalhes:
*		  - Serão consideradas, na matriz de adjacências, arestas não existentes aquelas que possuem custo 0.
*		  - Arestas duplas não são possíveis, por hora. Exemplo: (a,b) == (b,a)
*
*/

#include "Graph.hpp"

template class Graph<int>;
using namespace std;


// Inicializadores da classe
template <class TVertex>
Graph<TVertex>::Graph(){
	// Para o arquivo "base de dados" das arestas
	this->openFile("");
	this->edgeNumber = 0;
}

template <class TVertex>
Graph<TVertex>::Graph(string f_op){
	// Para o arquivo "base de dados" das arestas
	this->openFile(f_op);
	this->edgeNumber = 0;
}

template <class TVertex>
Graph<TVertex>::Graph(string f_op, vector<TVertex> vertex){
	// Para o arquivo "base de dados" das arestas
	this->openFile(f_op); 

	this->edgeNumber = 0;

	this->vertex = vertex;
	this->adjacencyMatriz.resize(vertex.size());
	for (int i = 0; i < (int) vertex.size(); i++){
		this->adjacencyMatriz[i].resize(vertex.size());
	}
}

template <class TVertex>
TVertex Graph<TVertex>::getVertex(int ind){
	return this->vertex[ind];
}

// Verifica qual a posição do vértice dentro do vetor de vértices
template <class TVertex>
int Graph<TVertex>::getIndex(TVertex vertex){
	for (int i = 0; i < (int) this->vertex.size(); i++){
		if (this->vertex.at(i) == vertex)
			return i;
	}

	throw out_of_range(" Vertice nao existente.");
}


// Retorna a aresta que está entre u e v
template <class TVertex>
Edge<TVertex> Graph<TVertex>::getEdge(TVertex u, TVertex v)
{
	try{

		int ind_u = this->getIndex(u);
		int ind_v = this->getIndex(v);

		Edge<TVertex> result(this->vertex[ind_u], this->vertex[ind_v], this->adjacencyMatriz[ind_u][ind_v]);

		return result;
	}
	catch (const out_of_range& oor){
		cerr << endl << " Vertices: " << u << " e " << v << endl;
		cerr << " Aresta nao existente." << endl << endl;
	}
}

// Adiciona uma nova aresta, com seu custo, ao grafo
template <class TVertex>
void Graph<TVertex>::setEdge(TVertex u, TVertex v, double cost){

	try{

		int ind_u = this->getIndex(u);
		int ind_v = this->getIndex(v);

		this->adjacencyMatriz[ind_u][ind_v] = (double) cost;
		this->adjacencyMatriz[ind_v][ind_u] = (double) cost;

		this->saveFile(ind_u, ind_v, cost);
		this->edgeNumber++;

	}
	catch (const out_of_range& oor){
		cerr << endl << " Vertices: " << u << " e " << v << endl;
		cerr << " Out of range error: " << oor.what() << endl << endl;
	}
}

// Retorna o número de vetores
template <class TVertex>
int Graph<TVertex>::getNumberVertex(){
	return this->vertex.size();
}

// Retorna o número de arestas salvas
template <class TVertex>
int Graph<TVertex>::getNumberEdge(){
	return this->edgeNumber;
}

// Salva uma aresta no arquivo
template <class TVertex>
void Graph<TVertex>::saveFile(TVertex u, TVertex v, double cost){
	this->outfile << u << "," << v << "," << cost << endl;
}


// Abre o arquivo que armazenará as aresta/custos do grafo em modo de edição ou escrita
// O caminho para este arquivo está setado na constate FILEOUTPUT
template <class TVertex>
void Graph<TVertex>::openFile(string f_op){
	// Caso a implementação seja definida como new, abre o arquivo como escrita
	if (f_op == "new"){
		this->outfile.open(FILEOUTPUT, ios::out | ios::trunc);
		this->outfile << "Node1,Node2,Cost" << endl;
	}
	// Abre como edição
	else{
		this->outfile.open(FILEOUTPUT, ios::app);
	}
}

// Obtém todos as arestas adjacentes ao vertice u, e as salva em um vetor (vector)
template <class TVertex>
vector< Edge<TVertex> > Graph<TVertex>::getAdjacents(TVertex u){
	try{
		vector< Edge<TVertex> > adj;
		int index = this->getIndex(u);

		for (int i = 0; i < (int) this->vertex.size(); i++){
			// == 0 implica em não existência da aresta
			if (this->adjacencyMatriz[i][index] != 0)
				adj.push_back(Edge<TVertex>(index, i, this->adjacencyMatriz[i][index]));
		}

		return adj;
	}
	catch (const out_of_range& oor){
		cerr << endl << " Vertex: " << u << endl;
		cerr << " Out of range error: " << oor.what() << endl << endl;
	}
}

// Retorna todas as arestas do grafos, de modo que desconsidera as duplicadas, considerando
// apenas os elementos da matriz abaixo da diagonal principal (ja que é simetrica)
template <class TVertex>
vector< Edge<TVertex> > Graph<TVertex>::getAllEdges(){
	try{
		if (this->edgeNumber == 0)
			throw out_of_range(" O grafo nao possui nenhuma aresta.");

		vector< Edge<TVertex> > adj;

		for (int i = 0; i < (int) this->vertex.size(); i++){
			//vector< Edge<TVertex> > aux = this->getAdjacents(this->vertex.at(i));
			for (int j = 0; j <= i; j++){
				if (this->adjacencyMatriz[i][j] != 0){
					adj.push_back(Edge<TVertex>(this->vertex.at(i), this->vertex.at(j), this->adjacencyMatriz[i][j]));
				}
			}
		}

		return adj;
	}
	catch (const out_of_range& oor){
		cerr << " Out of range error: " << oor.what() << endl << endl;
	}
}


template <class TVertex>
void Graph<TVertex>::showMatriz(){
	cout << "  IND ";
	printf("%c", 186);
	for (int i = 0; i < (int) this->vertex.size(); i++)
	{
		if (i < 10)
			cout << "   " << i;
		else
			cout << "  " << i;
	}


	printf("\n %c%c%c%c%c%c", 205, 205, 205, 205, 205, 206);
	for (int i = 0; i < (int) this->vertex.size(); i++)
		printf("%c%c%c%c", 205, 205, 205, 205);

	cout << endl;

	for (int i = 0; i < (int) this->vertex.size(); i++)
	{
		if (i < 10)
			cout << "   " << i;
		else
			cout << "  " << i;

		printf("  %c", 186);
		for (int j = 0; j < (int) this->vertex.size(); j++)
		{
			if (this->adjacencyMatriz[i][j] < 10)
				cout << "   ";
			else
				cout << "  ";

			if (this->adjacencyMatriz[i][j] != 0)
				cout << this->adjacencyMatriz[i][j];
			else
				cout << "-";
		}
		cout << endl;
	}
}


template <class TVertex>
void Graph<TVertex>::showAllVertex(){
	cout << endl << "  IND ";
	printf("%c", 186);
	cout << "  VERTICE ";

	printf("\n %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	cout << endl;
	for (int i = 0; i < (int) this->vertex.size(); i++)
	{
		if (i < 10)
			cout << "   " << i;
		else
			cout << "  " << i;
		printf("  %c  ", 186);

		cout << this->vertex.at(i);
		cout << endl;
	}
}

// Método responsável por abrir o arquivo html de visualização do grafo
template <class TVertex>
void Graph<TVertex>::showGraphView(){
	ShellExecute(NULL, "open", GRAPHVIEW, NULL, NULL, SW_SHOWNORMAL);
}

// Overload da do operador =
template <class TVertex>
void Graph<TVertex>::operator= (Graph<TVertex> &data){
	(*this).adjacencyMatriz = data.adjacencyMatriz;
	(*this).edgeNumber = data.edgeNumber;
	(*this).vertex = data.vertex;

	return;
}

template <class TVertex>
Graph<TVertex>::~Graph(){
	this->outfile.close();
}