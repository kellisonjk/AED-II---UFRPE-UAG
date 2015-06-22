/*
* Prim.cpp
*
*  Created on: Jun 06, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação do algoritmo de Prim aplicado junto com a classe Graph.
*		- Observações:
*			Diferente do Kruskal, essa implementação é funciona apenas para grafos não direcionais
*
*/

#include "Prim.hpp"

template class Prim<int>;
using namespace std;

template <class TVertex>
Prim<TVertex>::Prim(){}

template <class TVertex>
void Prim<TVertex>::createMST(){
	int number_vertex = this->graph.getVertex().size();
	vector<Edge<TVertex> > vertex_cost;
	Edge<TVertex> edge;

	// Atribui custos infinitos aos vertices
	for (int i = 0; i < number_vertex; i++){
		vertex_cost.push_back(Edge<TVertex>(this->graph.getVertex(i),-1,INFINITY));
	}

	// Raiz do caminho (posição zero [inicial] do vetor de vertices)
	// Atualiza o custo da raiz
	vertex_cost[0].cost(0);

	// Cria fila de prioridades
	Heap<Edge<TVertex> > priority_queue(vertex_cost, MIN_HEAP, vertex_cost.size(), vertex_cost.size());
	
	while (priority_queue.isEmpty() != true){
		edge = priority_queue.extract();
		vector<Edge<TVertex> > adj = this->graph.getAdjacents(edge.vertexSource());
		//if (edge.cost() == INFINITY) break;

		// Para todos os vizinho do vertice
		for (int ind = 0; ind < adj.size(); ind++){
			bool exist_priority = false;// = priority_queue.search(vertex_cost[ind_vertex_source]);
			int ind_vertex_source = this->graph.getIndex(adj[ind].vertexSource());

			// Para evitar repetições de arestas: (3, 2) e (2, 3)
			for (int i = 0; i < vertex_cost.size(); i++){
				if ((vertex_cost[i].vertexSource() == adj[ind].vertexTarget()) &&
					(vertex_cost[i].vertexTarget() == adj[ind].vertexSource())){
					exist_priority = true;
					break;
				}
			}

			if ( !exist_priority && (vertex_cost[ind_vertex_source].cost() > adj[ind].cost())){

				// Atualiza custos
				vertex_cost[ind_vertex_source].cost(adj[ind].cost());
				priority_queue.updateCost(ind_vertex_source, adj[ind].cost());

				// Atribui o "antecedente" do vertice, no caso da classe Edge, o target
				vertex_cost[ind_vertex_source].vertexTarget(adj[ind].vertexTarget());
				
				priority_queue.changeKey(ind_vertex_source, vertex_cost[ind_vertex_source], "");
			}
		}
	}
	
	this->mst.assign(vertex_cost.begin() + 1, vertex_cost.end());
}


template <class TVertex>
vector<Edge<TVertex> > Prim<TVertex>::getMST(){
	return this->mst;
}


template <class TVertex>
void Prim<TVertex>::printMST(){
	cout << "    ";
	for (int i = 0; i < this->mst.size(); i++)
	{
		cout << "(" << this->mst[i].vertexSource() << ", "
			<< this->mst[i].vertexTarget() << ", C = "
			<< this->mst[i].cost() << ") ";
		if (i != (this->mst.size() - 1))
			cout << "  -  ";
	}
	cout << endl;

}

// Salva as arestas obtidas com o algoritmo, dentro de um arquivo
template <class TVertex>
void Prim<TVertex>::saveEdgesFile(){

	ofstream outfile;
	// Abre o arquivo em modo de escrita para salvar os vertices
	outfile.open(FILEOUTPUT_EDGES, ios::out | ios::trunc);
	outfile << "Node1,Node2" << endl;

	for (int i = 0; i < this->mst.size(); i++){
		outfile << this->graph.getIndex(this->mst.at(i).vertexSource())
			<< "," << this->graph.getIndex(this->mst.at(i).vertexTarget()) << endl;
	}

	outfile.close();
}

template <class TVertex>
Prim<TVertex>::~Prim(){}
