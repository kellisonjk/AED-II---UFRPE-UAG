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
	this->vert_u = u;
	this->vert_v = v;
	this->cost = cost;
}

template <class TVertex>
TVertex Edge<TVertex>::getVertexU(){
	return this->vert_u;
}

template <class TVertex>
TVertex Edge<TVertex>::getVertexV(){
	return this->vert_v;
}

template <class TVertex>
double Edge<TVertex>::getCost(){
	return this->cost;
}

// Overload da do operador == 
template <class TVertex>
bool Edge<TVertex>::operator== (Edge<TVertex> data){
	if (((this->vert_u == data.getVertexU()) && (this->vert_v == data.getVertexV())) ||
		((this->vert_v == data.getVertexU()) && (this->vert_u == data.getVertexV())))

		return true;

	return false;
}

// Overload da do operador >
template <class TVertex>
bool Edge<TVertex>::operator> (Edge<TVertex> data){
	return (this->cost > data.getCost());
}

// Overload da do operador <
template <class TVertex>
bool Edge<TVertex>::operator< (Edge<TVertex> data){
	return (this->cost < data.getCost());
}

//template <class TVertex>
//ostream& operator<< (ostream &output, Edge<TVertex>& data){
//	output << "(" << data.getVertexU() << "," << data.getVertexV() << " )";
//	return output;
//}
