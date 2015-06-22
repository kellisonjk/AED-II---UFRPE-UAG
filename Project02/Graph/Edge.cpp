/*
* Heap.cpp
*
*  Created on: May 27, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação da classe Edge, referente a aresta de um grafo.
*
*
*/
#include "Edge.hpp"

template class Edge<int>;
using namespace std;

template <class TVertex>
Edge<TVertex>::Edge(){
}

template <class TVertex>
Edge<TVertex>::Edge(TVertex u, TVertex v, double cost){
	this->v_source = u;
	this->v_target = v;
	this->e_cost = cost;
}

template <class TVertex>
TVertex Edge<TVertex>::vertexSource(){
	return this->v_source;
}

template <class TVertex>
void Edge<TVertex>::vertexSource(TVertex vertex){
	this->v_source = vertex;
}

template <class TVertex>
TVertex Edge<TVertex>::vertexTarget(){
	return this->v_target;
}

template <class TVertex>
void Edge<TVertex>::vertexTarget(TVertex vertex){
	this->v_target = vertex;
}

template <class TVertex>
double Edge<TVertex>::cost(){
	return this->e_cost;
}

template <class TVertex>
void Edge<TVertex>::cost(double cost){
	this->e_cost = cost;
}

// Overload da do operador == 
template <class TVertex>
bool Edge<TVertex>::operator== (Edge<TVertex> data){
	if (((this->v_source == data.vertexSource()) && (this->v_target == data.vertexTarget())) ||
		((this->v_target == data.vertexSource()) && (this->v_source == data.vertexTarget())))

		return true;

	return false;
}

// Overload da do operador >
template <class TVertex>
bool Edge<TVertex>::operator> (Edge<TVertex> data){
	return (this->e_cost > data.cost());
}

// Overload da do operador <
template <class TVertex>
bool Edge<TVertex>::operator< (Edge<TVertex> data){
	return (this->e_cost < data.cost());
}

//template <class TVertex>
//ostream& operator<< (ostream &output, Edge<TVertex>& data){
//	output << "(" << data.vertexSource() << "," << data.vertexTarget() << " )";
//	return output;
//}
