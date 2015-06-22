/*
* Main.cpp
*
*      Author: Kellison
*		
*/

#include <iostream>
#include <stdio.h>
#include "Kruskal.hpp" 

using namespace std;

int main(int argc, char* argv[]){
	char op;
	vector<int> a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	Graph<int> g("new", a);

	printf("\n %c%c%c%c%c%c%c TRABALHANDO COM GRAFOS - ALG. DE KRUSKAL %c%c%c%c%c%c%c \n\n",
		205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

	g.showAllVertex();

	cout << endl << " Matriz de Adjacencias (com custos): " << endl << endl;

	g.setEdge(0, 1, 5);
	g.setEdge(0, 2, 6);
	g.setEdge(0, 3, 4);
	g.setEdge(1, 2, 1);
	g.setEdge(1, 3, 2);
	g.setEdge(2, 3, 2);
	g.setEdge(2, 5, 3);
	g.setEdge(2, 4, 6);
	g.setEdge(3, 5, 4);
	g.setEdge(4, 5, 4);

	g.showMatriz();
	
	Kruskal<int> k;
	//Kruskal<int> k(g); // Gera erro
	k.graph = g;

	// Gera a MST (arvore gerdore minima)
	//k.createMST();

	vector< Edge<int> > vec = k.getMST();

	printf("\n\n Algoritmo de Kruskal %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
	cout << endl << "   - Arvore Geradora Minima:" << endl;

	k.printEdges();
	k.saveEdgesFile();
	

	/*cout << endl << endl << " Visualizar o grafo? 1 - SIM: ";
	op = cin.get();
	if (op == '1'){
		g.showGraphView();
		cout << "  Abrindo arquivo ..." << endl << endl << "Execucao finalizada." << endl;
	}
	else{
		cout << endl << endl << " (Pressione <ENTER> para encerrar>" << endl;
		cin.get();
	}	*/

	cout << endl << endl << " (Pressione <ENTER> para encerrar>" << endl;
	cin.get();

	return 0;
}