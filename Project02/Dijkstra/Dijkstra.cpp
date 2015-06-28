/*
* Dijkstra.cpp
*
*  Created on: Jun 06, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação do algoritmo de Dijkstra aplicado junto com a classe Graph.
*
*/

#include "Dijkstra.hpp"

template class Dijkstra<int>;
using namespace std;

template <class TVertex>
Dijkstra<TVertex>::Dijkstra(){}

template <class TVertex>
void Dijkstra<TVertex>::getDistances(TVertex root){
	int number_vertex = this->graph.getVertex().size();
	VertexCost vertex_cost, min_u;
	vector<Edge<TVertex> > adjac;

	this->antecessor.resize(number_vertex); // Inicializa o vector com n_vertex posições

	// Atribui custos infinitos aos vertices
	for (int i = 0; i < number_vertex; i++){
		vertex_cost.add(i, (double) INF, -1);
		this->distance.push_back(vertex_cost);

		
	}

	// Raiz do caminho (posição zero [inicial] do vetor de vertices)
	// Atualiza o custo da raiz
	this->source = root;
	this->distance[this->graph.getIndex(root)].cost = 0;

	// Cria fila de prioridades
	Heap<VertexCost> priority_queue(this->distance, MIN_HEAP, this->distance.size(), this->distance.size());
	
	while (priority_queue.isEmpty() != true){
		//priority_queue.printTree(1);
		min_u = priority_queue.extract();

		adjac = this->graph.getAdjacents(min_u.vertexc);
		
		for (int i = 0; i < adjac.size(); i++){
			int first_vertex = this->graph.getIndex(adjac.at(i).vertexSource());
			int second_vertex = this->graph.getIndex(adjac.at(i).vertexTarget());
			double dist = this->distance[second_vertex].cost + adjac.at(i).cost();

			if ( this->distance[first_vertex].cost > dist ){				
				this->distance[first_vertex].cost = dist;
				this->distance[first_vertex].vertex_prev = min_u.vertexc; // Antecessores (no caminho) do vértice

				priority_queue.updateCost(first_vertex,dist); // Atualiza custo/distancia na lista de prioridade
				priority_queue.changeKey(second_vertex, this->distance[second_vertex], ""); // Diminui prioridade
			}
		}

		
	}
}

template <class TVertex>
int Dijkstra<TVertex>::findIndex(TVertex vertex){
	for (int i = 0; i < this->distance.size(); i++){
		
	}
}

template <class TVertex>
void Dijkstra<TVertex>::print(){
	cout << "  - Origem: " << this->source << endl;
	cout << "    (destino: distancia)" << endl;
	for (int i = 0; i < this->distance.size(); i++)
	{
		if (i != this->graph.getIndex(this->source)){
			cout << "    (" << this->distance[i].vertexc << ": ";

			if (this->distance[i].cost != INF)
				cout << this->distance[i].cost << ") " << endl;
			else
				cout << "<sem caminho> )" << endl;
		}
	}
	cout << endl;

	cout << "  - Antecessores: " << this->source << endl;
	cout << "    (destino: caminho)" << endl;
	for (int i = 0; i < this->distance.size(); i++)
	{
		if (i != this->source){
			cout << "    (" << i << " : <- ";
			int flag = this->distance.at(i).vertex_prev;
			while (flag != -1){
				cout << flag;
				flag = this->distance.at(flag).vertex_prev;

				if (flag != -1)
					cout << " <- ";

			}
			cout << ")" << endl;
		}
	}
	cout << endl;
}

template <class TVertex>
Dijkstra<TVertex>::~Dijkstra(){}
