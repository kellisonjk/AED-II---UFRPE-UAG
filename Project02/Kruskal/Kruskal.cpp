/*
* Kruskal.cpp
*
*  Created on: May 29, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação do algoritmo de Kruskal aplicado junto com a classe Graph.
*
*	   - Problemas com a classe:
*		- Existe algo que impede que o programa seja compilado quando eu passo, em qualquer 
*		  método, como parâmetro um objeto "Graph<TVertex>". Tive que definir o atributo "graph"
*		  na classe "Graph.hpp" como publico para conseguir utilizá-lo.  Os erros obtidos quando tento 
*		  compilar estão na imagem "log-make"
*
*/

#include "Kruskal.hpp"

template class Kruskal<int>;
using namespace std;


// Inicializadores da classe

template <class TVertex>
Kruskal<TVertex>::Kruskal(){
	this->components[graph.getNumberVertex()];
}

template <class TVertex>
Kruskal<TVertex>::Kruskal(Graph<TVertex> gph){
	this->graph = gph;
	this->components[graph.getNumberVertex()];
	//this->mst.resize(graph.getNumberEdge());
}

// Impl. do Algortimo de Kruskal
// Salva (arestas) a menor árvore geradora do grafo
template <class TVertex>
void  Kruskal<TVertex>::createMST(){
	vector< Edge<TVertex> > edges_graph = this->graph.getAllEdges();
	ofstream outfile;

	// Abre o arquivo para salvar o log da execução do algoritmo
	outfile.open("log-kruskal.txt", ios::out | ios::trunc);
	outfile << "Inicio do algoritmo" << endl;
	outfile << " Criando componenter" << endl;

	for (int i = 0; i < (int) this->graph.getNumberVertex(); i++){

		outfile << " Componente (" << i << ")" << endl;
		// Cria o componente: o indice do vetor 'components' representa o vértice, e o valor atribuido
		// a ele indica qual o componente em que o vértice está.
		this->components[i] = i;

	}
	
	// Ordena as arestas (em ordem crescente pelo custo das arestas)

	outfile << endl<< " Ordena arestas." << endl;

	sort(edges_graph.begin(), edges_graph.end());

	for (int i = 0; i < (int) edges_graph.size(); i++){
		outfile << " Laço (" << i << ")" << endl;

		TVertex vertice_u = edges_graph.at(i).getVertexU();
		TVertex vertice_v = edges_graph.at(i).getVertexV();
		if (this->graph.getEdge(vertice_u, vertice_v).getCost() > -1){
			outfile << "   Testando os vertices: " << vertice_u << "," << vertice_v << endl;

			// Verifica se os dois vértices fazem parte do mesmo componente
			if (this->findComponent(vertice_u) != this->findComponent(vertice_v)){
				this->mst.push_back(edges_graph.at(i));

				outfile << "    Componente (" << vertice_u << "): " << this->findComponent(vertice_u) << endl;
				outfile << "    Componente (" << vertice_v << "): " << this->findComponent(vertice_v) << endl;

				// Realiza a união dos vértices no mesmo componente

				outfile << "      Unindo componentes" << endl;
				this->mergeComponent(vertice_u, vertice_v);

				outfile << "        Componente (" << vertice_u << "): " << this->findComponent(vertice_u) << endl;
				outfile << "        Componente (" << vertice_v << "): " << this->findComponent(vertice_v) << endl;
			}
		}

		outfile << " Fim do laço (" << i << ")" << endl;
	}

	outfile << "Encerra algoritmo" << endl;

	outfile.close();
}

// Procura pelo componente que contém o vértice passado por parâmetro
template <class TVertex>
int Kruskal<TVertex>::findComponent(TVertex vertice){
	int index_comp = this->graph.getIndex(vertice);

	return this->components[index_comp];
}

// Realiza do vétrice u com o componente do vétice v, formando um novo componente
template <class TVertex>
void Kruskal<TVertex>::mergeComponent(TVertex vertice_u, TVertex vertice_v){
	int index_u = this->graph.getIndex(vertice_u);
	int index_v = this->graph.getIndex(vertice_v);
	int comp_u = this->components[index_u];
	int comp_v = this->components[index_v];

	// Une o vértice u ao v (e vice-versa), atualizando seus componentes
	// A união será feita atribuindo o maior componente ao menor
	if (this->components[index_u] > this->components[index_v]){

		// Atualiza todos os membros do componente em que "u" estava contido
		for (int i = 0; i < this->graph.getNumberVertex(); i++){
			if (this->components[i] == comp_u)
				this->components[i] = comp_v;
		}
	}
	else{
		// Atualiza todos os membros do componente em que "v" estava contido
		for (int i = 0; i < this->graph.getNumberVertex(); i++){
			if (this->components[i] == comp_v)
				this->components[i] = comp_u;
		}
	}


}

// Retorna as arestas salvas no método getMinimumCost
template <class TVertex>
vector< Edge<TVertex> > Kruskal<TVertex>::getMST(){
	return this->mst;
}

template <class TVertex>
void Kruskal<TVertex>::printEdges(){
	cout << "    ";
	for (int i = 0; i < this->mst.size(); i++)
	{
		cout << "(" << this->mst[i].getVertexU() << "," 
			 << this->mst[i].getVertexV() << ", C = " 
			 << this->mst[i].getCost() << ") ";
		if (i != (this->mst.size() - 1))
			cout << "  -  ";
	}
	cout << endl;

}


// Salva as arestas obtidas com o algoritmo, dentro de um arquivo
template <class TVertex>
void Kruskal<TVertex>::saveEdgesFile(){

	ofstream outfile;
	// Abre o arquivo em modo de escrita para salvar os vertices
	outfile.open(FILEOUTPUT_KRUSKAL, ios::out | ios::trunc);
	outfile << "Node1,Node2" << endl;

	for (int i = 0; i < this->mst.size(); i++){
		outfile << this->mst.at(i).getVertexV() << "," << this->mst.at(i).getVertexU() << endl;
	}

	outfile.close();
}

template <class TVertex>
Kruskal<TVertex>::~Kruskal(){
}
